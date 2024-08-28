/*
 * TIMER_0_program.c
 *
 * Created: 11/08/2024 12:07:45 م
 *  Author: a24e4
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "TIMER_0_config.h"
#include "TIMER_0_interface.h"
#include "TIMER_0_private.h"
#include "TIMER_0_register.h"



static volatile ptr2voidCallback G_ptr2voidCallback_callback = NULL;

void MTIMER_0_voidInit(void){
	#if MTIMERO_MODE_SELECT == MTIMER0_MODE_NORMAL
		//Normal Mode
		CLR_BIT(TCCR0_REG,6);
		CLR_BIT(TCCR0_REG,3);
	
		//OC0 PIN
		TCCR0_REG = (TCCR0_REG&0b11001111)|(MTIMER0_OC0_SELECT<<4);
	
		//PRELOAD VALUE
		TCNT0_REG = MTIMER0_PRELOAD_VAL;
	
		//CLK SELECT
		TCCR0_REG = (TCCR0_REG&0b11111000)|(MTIMER0_PRESCALER_SELECT);

		// Timer/Counter0 Overflow Interrupt Enable
		SET_BIT(TIMSK_REG,0);
	#elif MTIMERO_MODE_SELECT == MTIMER0_MODE_CTC
		//CTC Mode
		CLR_BIT(TCCR0_REG,6);
		SET_BIT(TCCR0_REG,3);
		
		//OC0 PIN
		TCCR0_REG = (TCCR0_REG&0b11001111)|(MTIMER0_OC0_SELECT<<4);
		
		//PRELOAD VALUE
		TCNT0_REG = MTIMER0_PRELOAD_VAL;
		
		//COMPARE VALUE
		OCR0_REG = MTIMER0_COMPARE_VALUE;
		
		//CLK SELECT
		TCCR0_REG = (TCCR0_REG&0b11111000)|(MTIMER0_PRESCALER_SELECT);

		//Timer/Counter0 Output Compare Match Interrupt Enable
		SET_BIT(TIMSK_REG,1);
	#elif MTIMERO_MODE_SELECT == MTIMER0_MODE_FAST_PWM
		//FAST PWM
		SET_BIT(TCCR0_REG,6);
		SET_BIT(TCCR0_REG,3);

		//OC0 PIN
		TCCR0_REG = (TCCR0_REG&0b11001111)|(MTIMER0_OC0_SELECT<<4);

		//CLK SELECT
		TCCR0_REG = (TCCR0_REG&0b11111000)|(MTIMER0_PRESCALER_SELECT);

		//OC0 OUTPUT
		MDIO_voidSetPinDir(OC0_PIN,OUTPUT);

	#elif MTIMERO_MODE_SELECT == MTIMER0_MODE_PHASE_CORRECT
		//Phase Correct
		SET_BIT(TCCR0_REG,6);
		CLR_BIT(TCCR0_REG,3);

		//OC0 PIN
		TCCR0_REG = (TCCR0_REG&0b11001111)|(MTIMER0_OC0_SELECT<<4);

		//CLK SELECT
		TCCR0_REG = (TCCR0_REG&0b11111000)|(MTIMER0_PRESCALER_SELECT);

		//OC0 OUTPUT
		MDIO_voidSetPinDir(OC0_PIN,OUTPUT);


	#else
		#error "TIMER0 error, mode operation undefined"
	#endif

}

void MTimer_0_voidDisableClk(void){
	//CLK SELECT
	TCCR0_REG = (TCCR0_REG&0b11111000)|(MTIMER0_PRESCALER_NO_CLOCK);
}
	
void MTimer_0_voidEnableClk(void){
	//CLK SELECT
	TCCR0_REG = (TCCR0_REG&0b11111000)|(MTIMER0_PRESCALER_SELECT);
}

#if MTIMERO_MODE_SELECT == MTIMER0_MODE_NORMAL || MTIMERO_MODE_SELECT == MTIMER0_MODE_CTC
	void MTimer_0_voidSetCallback(ptr2voidCallback A_ptr2voidCallback_callback){
		G_ptr2voidCallback_callback = A_ptr2voidCallback_callback;
	}
#endif

#if MTIMERO_MODE_SELECT == MTIMER0_MODE_NORMAL || MTIMERO_MODE_SELECT == MTIMER0_MODE_CTC
	void MTimer_0_voidDisableInterrupt(void){
		#if MTIMERO_MODE_SELECT == MTIMER0_MODE_NORMAL
			CLR_BIT(TIMSK_REG,0);
		#elif MTIMERO_MODE_SELECT == MTIMER0_MODE_CTC
			CLR_BIT(TIMSK_REG,1);
		#else
			#error "TIMER0 error, mode operation undefined"
		#endif
	}
#endif

#if MTIMERO_MODE_SELECT == MTIMER0_MODE_NORMAL || MTIMERO_MODE_SELECT == MTIMER0_MODE_CTC
	void MTimer_0_voidEnableInterrupt(void){
		#if MTIMERO_MODE_SELECT == MTIMER0_MODE_NORMAL
			SET_BIT(TIMSK_REG,0);
		#elif MTIMERO_MODE_SELECT == MTIMER0_MODE_CTC
			SET_BIT(TIMSK_REG,1);
		#else
			#error "TIMER0 error, mode operation undefined"
		#endif	
	}
#endif



#if MTIMERO_MODE_SELECT == MTIMER0_MODE_FAST_PWM || MTIMERO_MODE_SELECT == MTIMER0_MODE_PHASE_CORRECT
	//dutyCycle range [000, 100]
	void MTIMER_0_voidSetDutyCucle(u8 A_u8DutyCycle){
		u8 L_ocrVal = 0;
				
		#if MTIMER0_OC0_SELECT == MTIMER0_OC0_MODE_2     //nin inverted mode
			L_ocrVal = (u8)((A_u8DutyCycle/100.0) * (TIMER0_TICKS_NO - 1));
		#elif MTIMER0_OC0_SELECT == MTIMER0_OC0_MODE_3   //inverted mode
			L_ocrVal = (u8)(((100 - A_u8DutyCycle)/100.0) * (TIMER0_TICKS_NO - 1));
		#else
			#error "TIMER0 ERROR, in PWM or Phase correct, the oc0 must be inverted or nin inverted"
		#endif
				
		OCR0_REG = L_ocrVal;
	}
#endif


//Timer/Counter0 Overflow ISR
#if MTIMERO_MODE_SELECT == MTIMER0_MODE_NORMAL
	void __vector_11(void)__attribute__((signal));
	void __vector_11(){
		static u32 counter = 0;
		counter++;

		if(counter == MTIMER0_MAX_COUNT){
			counter = 0;
			TCNT0_REG = MTIMER0_PRELOAD_VAL;
		
			if(G_ptr2voidCallback_callback != NULL){
				G_ptr2voidCallback_callback();
			}
		
		}
	}
#endif


//Timer/Counter0 Compare ISR
#if MTIMERO_MODE_SELECT == MTIMER0_MODE_CTC
	void __vector_10(void)__attribute__((signal));
	void __vector_10(){
		static u32 counter = 0;
		counter++;

		if(counter == MTIMER0_MAX_COUNT){
			counter = 0;
			TCNT0_REG = MTIMER0_PRELOAD_VAL;
			
			if(G_ptr2voidCallback_callback != NULL){
				G_ptr2voidCallback_callback();
			}
			
		}
	}
#endif
