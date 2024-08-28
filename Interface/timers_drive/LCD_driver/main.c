/*
 * LCD_driver.c
 *
 * Created: 04/08/2024 08:24:43 ص
 * Author : a24e4
 */ 

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DELAY/DELAY_interface.h"

#include "MCAL/GI/GI_interface.h"

#include "MCAL/EXT_INT/EXT_INT_interface.h"

#include "MCAL/ADC/ADC_interface.h"

#include "MCAL/TIMER_0/TIMER_0_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_patterns.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_config.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#include "HAL/KEYPAD/KEYPAD_congif.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"


int main(void)
{
	u32 L_SpeedVOLT=0,L_DirVOLT;
	u8  L_dc=0;
	
	
		MDIO_voidInit();

			MDIO_voidSetPinDir(PinD7,OUTPUT);
			MDIO_voidSetPinDir(PinD6,OUTPUT);
	
	MGI_void_Enable();
	
	MADC_voidInit();	
		
	
	MTIMER_0_voidInit();
		
	while(1){

		L_SpeedVOLT = MADC_u32ReadVoltage(MADC_SINGLE_CHANNEL_0);
		L_dc = (u8)((L_SpeedVOLT * 255.0)/5000.0);
		
		L_DirVOLT = MADC_u32ReadVoltage(MADC_SINGLE_CHANNEL_7);
		
		MTIMER_0_voidSetDutyCucle(L_dc);
		
		if(L_DirVOLT > 700){
			MDIO_voidSetPinVal(PinD7,HIGH );
			MDIO_voidSetPinVal(PinD6,LOW);
		}else if (L_DirVOLT<300){
			MDIO_voidSetPinVal(PinD7,LOW );
			MDIO_voidSetPinVal(PinD6,HIGH);
		}else{
						MDIO_voidSetPinVal(PinD7,LOW );
						MDIO_voidSetPinVal(PinD6,LOW);
		}
		
		MDELAY_void_milli(100);
	}
}