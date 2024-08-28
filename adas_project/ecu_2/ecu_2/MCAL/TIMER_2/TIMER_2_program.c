/*
 * TIMER_2_program.c
 *
 * Created: 23/08/2024 09:56:35 ص
 *  Author: a24e4
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "TIMER_2_config.h"
#include "TIMER_2_interface.h"
#include "TIMER_2_private.h"
#include "TIMER_2_register.h"



static volatile ptr2voidCallback G_ptr2voidCallback_callback = NULL;

void MTIMER_2_voidInit(void){
	#if MTIMER2_MODE_SELECT == MTIMER2_MODE_NORMAL
		//Normal Mode
		CLR_BIT(TCCR2_REG,6);
		CLR_BIT(TCCR2_REG,3);
		
		//OC2 PIN
		TCCR2_REG = (TCCR2_REG&0b11001111)|(MTIMER2_OC2_MODE_2<<4);
		
		//PRELOAD VALUE
		TCNT2_REG = MTIMER2_PRELOAD_VAL;
		
		//CLK SELECT
		TCCR2_REG = (TCCR2_REG&0b11111000)|(MTIMER2_PRESCALER_SELECT);

		// Timer/Counter2 Overflow Interrupt Enable
		SET_BIT(TIMSK_REG,6);
		
	#elif MTIMER2_MODE_SELECT == MTIMER2_MODE_CTC
		//CTC Mode
		SET_BIT(TCCR2_REG,6);
		CLR_BIT(TCCR2_REG,3);
		
		//OC2 PIN
		TCCR2_REG = (TCCR2_REG&0b11001111)|(MTIMER2_OC2_SELECT<<4);
		
		//PRELOAD VALUE
		TCNT2_REG = MTIMER2_PRELOAD_VAL;
		
		//COMPARE VALUE
		OCR2_REG = MTIMER2_COMPARE_VALUE;
		
		//CLK SELECT
		TCCR2_REG = (TCCR2_REG&0b11111000)|(MTIMER2_PRESCALER_SELECT);

		// Timer/Counter2 Output Compare Match Interrupt Enable
		SET_BIT(TIMSK_REG,7);
	#elif MTIMER2_MODE_SELECT == MTIMER2_MODE_FAST_PWM
		//FAST PWM
		SET_BIT(TCCR2_REG,6);
		SET_BIT(TCCR2_REG,3);
	
		//OC2 PIN
		TCCR2_REG = (TCCR2_REG&0b11001111)|(MTIMER2_OC2_SELECT<<4);
	
		//CLK SELECT
		TCCR2_REG = (TCCR2_REG&0b11111000)|(MTIMER2_PRESCALER_SELECT);
	
		//OC2 OUTPUT
		MDIO_voidSetPinDir(OC2_PIN,OUTPUT);
	

	#elif MTIMER2_MODE_SELECT == MTIMER2_MODE_PHASE_CORRECT
		//Phase Correct
		SET_BIT(TCCR2_REG,6);
		CLR_BIT(TCCR2_REG,3);
	
		//OC2 PIN
		TCCR2_REG = (TCCR2_REG&0b11001111)|(MTIMER2_OC2_SELECT<<4);
	
		//CLK SELECT
		TCCR2_REG = (TCCR2_REG&0b11111000)|(MTIMER2_PRESCALER_SELECT);
	
		//OC2 OUTPUT
		MDIO_voidSetPinDir(OC2_PIN,OUTPUT);


	#else
	#error "TIMER2 error, mode operation undefined"
	#endif

}

void MTIMER_2_voidDisableClk(void){
	//CLK SELECT
		TCCR2_REG = (TCCR2_REG&0b11111000)|(MTIMER2_PRESCALER_NO_CLOCK);
}

void MTIMER_2_voidEnableClk(void){
	//CLK SELECT
		TCCR2_REG = (TCCR2_REG&0b11111000)|(MTIMER2_PRESCALER_SELECT);
}

#if MTIMER2_MODE_SELECT == MTIMER2_MODE_NORMAL || MTIMER2_MODE_SELECT == MTIMER2_MODE_CTC
void MTIMER_2_voidSetCallback(ptr2voidCallback A_ptr2voidCallback_callback){
	G_ptr2voidCallback_callback = A_ptr2voidCallback_callback;
}
#endif

#if MTIMER2_MODE_SELECT == MTIMER2_MODE_NORMAL || MTIMER2_MODE_SELECT == MTIMER2_MODE_CTC
void MTIMER_2_voidDisableInterrupt(void){
	#if MTIMER2_MODE_SELECT == MTIMER2_MODE_NORMAL
		CLR_BIT(TIMSK_REG,6);
	#elif MTIMER2_MODE_SELECT == MTIMER2_MODE_CTC
		CLR_BIT(TIMSK_REG,7);
	#else
		#error "TIMER2 error, mode operation undefined"
	#endif
}
#endif

#if MTIMER2_MODE_SELECT == MTIMER2_MODE_NORMAL || MTIMER2_MODE_SELECT == MTIMER2_MODE_CTC
void MTIMER_2_voidEnableInterrupt(void){
	#if MTIMER2_MODE_SELECT == MTIMER2_MODE_NORMAL
	SET_BIT(TIMSK_REG,6);
	#elif MTIMER2_MODE_SELECT == MTIMER2_MODE_CTC
	SET_BIT(TIMSK_REG,7);
	#else
	#error "TIMER2 error, mode operation undefined"
	#endif
}
#endif



#if MTIMER2_MODE_SELECT == MTIMER2_MODE_FAST_PWM || MTIMER2_MODE_SELECT == MTIMER2_MODE_PHASE_CORRECT
//dutyCycle range [000, 100]
void MTIMER_2_voidSetDutyCucle(u8 A_u8DutyCycle){
	u8 L_ocrVal = 0;
	
	#if MTIMER2_OC2_SELECT == MTIMER2_OC2_MODE_2     //nin inverted mode
		L_ocrVal = (u8)((A_u8DutyCycle/100.0) * (TIMER2_TICKS_NO - 1));
	#elif MTIMER2_OC2_SELECT == MTIMER2_OC2_MODE_3   //inverted mode
		L_ocrVal = (u8)(((100 - A_u8DutyCycle)/100.0) * (TIMER2_TICKS_NO - 1));
	#else
	#error "TIMER2 ERROR, in PWM or Phase correct, the OC2 must be inverted or nin inverted"
	#endif
	
	OCR2_REG = L_ocrVal;
}
#endif


//Timer/Counter2 Overflow ISR
#if MTIMER2_MODE_SELECT == MTIMER2_MODE_NORMAL
void __vector_5(void)__attribute__((signal));
void __vector_5(){
	static u32 counter = 0;
	counter++;

	if(counter == MTIMER2_MAX_COUNT){
		counter = 0;
		TCNT2_REG = MTIMER2_PRELOAD_VAL;
		
		if(G_ptr2voidCallback_callback != NULL){
			G_ptr2voidCallback_callback();
		}
		
	}
}
#endif

//Timer/Counter2 Compare ISR
#if MTIMER2_MODE_SELECT == MTIMER2_MODE_CTC
void __vector_4(void)__attribute__((signal));
void __vector_4(){
	static u32 counter = 0;
	counter++;

	if(counter == MTIMER2_MAX_COUNT){
		counter = 0;
		TCNT2_REG = MTIMER2_PRELOAD_VAL;
		
		if(G_ptr2voidCallback_callback != NULL){
			G_ptr2voidCallback_callback();
		}
		
	}
}
#endif