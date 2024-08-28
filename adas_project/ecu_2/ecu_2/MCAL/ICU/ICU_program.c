/*
 * ICU_program.c
 *
 * Created: 13/08/2024 09:41:41 ص
 *  Author: a24e4
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_interface.h"
#include "ICU_config.h"
#include "ICU_interface.h"
#include "ICU_private.h"
#include "ICU_register.h"

static volatile u64 G_u64TicksHigh = 1;
static volatile u64 G_u64TicksLow  = 1;

static volatile u32 G_u32OverflowsCount=0;




void MICU_voidInit(void){
	

		
	//normal mode
	CLR_BIT(TCCR1A_REG,WGM10);
	CLR_BIT(TCCR1A_REG,WGM11);
	CLR_BIT(TCCR1B_REG,WGM12);
	CLR_BIT(TCCR1B_REG,WGM13);
	
	//enable Input Capture Noise Canceler
	SET_BIT(TCCR1B_REG,ICNC1);

	
	//Input Capture Interrupt Enable
	SET_BIT(TIMSK_REG,TICIE1);
	
	//edge select: wait RISING
	SET_BIT(TCCR1B_REG,ICES1);
	
	//Overflow Interrupt Enable
	SET_BIT(TIMSK_REG,TOIE1);
	
		//clk, prescaller 8
		CLR_BIT(TCCR1B_REG,CS10);
		SET_BIT(TCCR1B_REG,CS11);
		CLR_BIT(TCCR1B_REG,CS12);
}

u64 MICU_u64ReadTimeHighMicro(void){
	u64 L_highTimeMicro;
	L_highTimeMicro = G_u64TicksHigh * MICU_TICK_TIME_MICRO;
	
	return L_highTimeMicro;
}

u64 MICU_u64ReadTimeLowMicro(void){
	u64 L_lowTimMicro;
	L_lowTimMicro = G_u64TicksLow * MICU_TICK_TIME_MICRO;
	
	return L_lowTimMicro;
}

//0 --> 100
u8 MICU_u8ReadDutyCycle(void){
	return (G_u64TicksHigh * 100 ) / (G_u64TicksHigh + G_u64TicksLow);
}



//Timer/Counter1 Capture Event
void __vector_6 (void) __attribute__ ((signal,used, externally_visible));
void __vector_6 (void){
	static u8 L_u8Flag  = 0;
	
	switch(L_u8Flag){			
		case 0:
			L_u8Flag = 1;
			TCNT1_REG = (u16)0;			//clear timer
			CLR_BIT(TCCR1B_REG,ICES1);	//edge select: wait FALLING
			G_u32OverflowsCount = 0;
			break;	
			
		case 1:
			L_u8Flag = 2;
			G_u64TicksHigh = (u64)(TCNT1_REG)  + G_u32OverflowsCount * 0XFFFF;	// read high ticks
			TCNT1_REG = (u16)0;					//clear timer
			G_u32OverflowsCount = 0;
			SET_BIT(TCCR1B_REG,ICES1);			//edge select: wait RISING
			break;	
			
		case 2:
		
			L_u8Flag = 1;
			G_u64TicksLow = (u64)(TCNT1_REG)  + G_u32OverflowsCount * 0XFFFF; // read low ticks
			TCNT1_REG = (u16)0;					//clear timer
			G_u32OverflowsCount = 0;
			CLR_BIT(TCCR1B_REG,ICES1);	//edge select: wait falling
			break;						
	} 
}

void __vector_9 (void)__attribute__((signal))__attribute__((interrupt));
void __vector_9 (void)
	{
		G_u32OverflowsCount++;
}
	
	
