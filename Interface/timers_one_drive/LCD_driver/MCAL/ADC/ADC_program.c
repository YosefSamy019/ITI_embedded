/*
 * ADC_program.c
 *
 * Created: 10/08/2024 02:35:32 م
 *  Author: a24e4
 */ 


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"

#include "AVR/delay.h"

static  void (*G_ptr2voidFunU32)(u32) = NULL;


void MADC_voidInit(void){
		//Enable ADC
		SET_BIT(ADCSRA_REG,ADCSRA_ADEN_BIT);
		
		//Voltage Reference Selection
		ADMUX_REG = (ADMUX_REG&0b00111111) | (MADC_VREF_SELECTION<<6);
		
		//ADC Prescaler Select Bits
		ADCSRA_REG = (ADCSRA_REG&0b11111000) | (MADC_DIV_FACT_SELECTION&0b00000111);
		
		//ADJUSTEMNT
		#if ADC_ADJUST==0
			CLR_BIT(ADMUX_REG,ADMUX_ADLAR_BIT);
		#elif ADC_ADJUST==1
			SET_BIT(ADMUX_REG,ADMUX_ADLAR_BIT);
		#else
			#error "ADC ERROR, adjust undefined"
		#endif
		
		
		//ADC Auto Trigger Enable
		#if MADC_Auto_Trigger_Enable==0
			CLR_BIT(ADCSRA_REG,ADCSRA_ADATE_BIT);
		#elif MADC_Auto_Trigger_Enable==1
			SET_BIT(ADCSRA_REG,ADCSRA_ADATE_BIT);
			//ADC Auto Trigger Source
			SFIOR_REG = (SFIOR_REG&0b00011111) | (MADC_TRIGGER_SOURCE_SELECTION<<5);
		#else
			#error "ADC ERROR, ADC Auto Trigger Enable undefined"
		#endif
}

u32 MADC_u32ReadVoltage(MADC_channel_t A_MADC_channel_t_channel){
	u32 returnVal = 0;
	
	ADMUX_REG = (ADMUX_REG&0b11100000) | (A_MADC_channel_t_channel & 0b00011111);
	
	//ADC Start Conversion
	SET_BIT(ADCSRA_REG,ADCSRA_ADSC_BIT);
	
	//wait
	while(GET_BIT(ADCSRA_REG,ADCSRA_ADIF_BIT) == 0);
	
	//read
	#if MADC_ADJUST==0
		returnVal = ((int)(ADCL_REG) + ((int)ADCH_REG<<8));
	#elif MADC_ADJUST==1
		returnVal = (int)ADCL_REG>>6 + (int)ADCH_REG<<2;
	#else
		#error "ADC ERROR, adjust undefined"
	#endif
	
	SET_BIT(ADCSRA_REG,ADCSRA_ADIF_BIT);
	
	return returnVal;
}

void MADC_voidStartConversion(MADC_channel_t A_MADC_channel_t_channel){
	ADMUX_REG = (ADMUX_REG&0b11100000) | (A_MADC_channel_t_channel & 0b00011111);
	
	//ADC Start Conversion
	SET_BIT(ADCSRA_REG,ADCSRA_ADSC_BIT);
}

void MADC_voidEnableInterrupt(void){
	SET_BIT(ADCSRA_REG,ADCSRA_ADIE_BIT);
}

void MADC_voidSetCallback( void (*A_ptr2voidFunU32)(u32) ){
	G_ptr2voidFunU32 = A_ptr2voidFunU32;
}

void __vector_16 (void) __attribute__ ((signal,used, externally_visible));
void __vector_16 (void){
	if(G_ptr2voidFunU32 != NULL){
		u32 returnVal = 0;

		//read
		#if MADC_ADJUST==0
			returnVal = ((int)(ADCL_REG) + ((int)ADCH_REG<<8));
		#elif MADC_ADJUST==1
			returnVal = (int)ADCL_REG>>6 + (int)ADCH_REG<<2;
		#else
			#error "ADC ERROR, adjust undefined"
		#endif
		
		if(G_ptr2voidFunU32 != NULL){
			G_ptr2voidFunU32(returnVal);
		}
	}
}

