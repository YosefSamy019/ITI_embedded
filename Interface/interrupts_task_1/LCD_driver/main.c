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


HLed_t G_hled_L0,G_hled_L1;

void callback0(void){
	HLED_void_TurnToggle(&G_hled_L0);
}

void callback1(void){
	HLED_void_TurnToggle(&G_hled_L1);
}



int main(void)
{

	
	
	MGI_void_Enable();
	
	MEXT_INT_0_voidInit();
	MEXT_INT_0_voidEnable();
	MEXT_INT_0_voidSenseControl(MEXT_INT_0_Sense_AnyChange);
	
		
	MEXT_INT_1_voidInit();
	MEXT_INT_1_voidEnable();
	MEXT_INT_1_voidSenseControl(MEXT_INT_1_Sense_AnyChange);
			
	
	G_hled_L0 = HLED_HLed_t_Create(PinA0,HLED_ActiveHigh);
	G_hled_L1 = HLED_HLed_t_Create(PinA1,HLED_ActiveHigh);
	
	MEXT_INT_0_voidSetCallback(callback0);
	MEXT_INT_1_voidSetCallback(callback1);

	while(1);
	
}

