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

#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_patterns.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_config.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#include "HAL/KEYPAD/KEYPAD_congif.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"



u8 G_u8_AnimNo = 0;

void callback2(void){
	G_u8_AnimNo = (G_u8_AnimNo+1)%2;
}



int main(void)
{
	u8 L_u8_temp;
	Pin_t L_Pin_t_ledspins[8] = {PinC0,PinC1,PinC2,PinC3,PinC4,PinC5,PinC6,PinC7};
	HLed_t LHLed_t_ledsArr[8];
	
	MGI_void_Enable();
	
	MEXT_INT_2_voidInit();
	MEXT_INT_2_voidEnable();
	MEXT_INT_2_voidSenseControl(MEXT_INT_1_Sense_RisingEdge);
	MEXT_INT_2_voidSetCallback(callback2);

	for (L_u8_temp =0;L_u8_temp<8;L_u8_temp++)
	{
		LHLed_t_ledsArr[L_u8_temp] = HLED_HLed_t_Create(L_Pin_t_ledspins[L_u8_temp],HLED_ActiveHigh);
	}

	L_u8_temp = 0;
	while(1){
		if(G_u8_AnimNo == 0){
			HLED_void_TurnOff(&LHLed_t_ledsArr[L_u8_temp]);
			
			L_u8_temp = (L_u8_temp+1)%8;
			
			HLED_void_TurnOn(&LHLed_t_ledsArr[L_u8_temp]);
			
		}else{
			HLED_void_TurnOff(&LHLed_t_ledsArr[L_u8_temp]);
			HLED_void_TurnOff(&LHLed_t_ledsArr[7 - L_u8_temp]);
			
			L_u8_temp = (L_u8_temp+1)%4;

			HLED_void_TurnOn(&LHLed_t_ledsArr[L_u8_temp]);
			HLED_void_TurnOn(&LHLed_t_ledsArr[7 - L_u8_temp]);
		}
		
		MDELAY_void_milli(400);
	}
	
}

