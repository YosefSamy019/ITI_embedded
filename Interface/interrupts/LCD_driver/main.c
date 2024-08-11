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

HLed_t l1,l2,l3;

void cb0(void){
	HLED_void_TurnToggle(&l1);
}

void cb1(void){
	HLED_void_TurnToggle(&l2);
}
void cb2(void){
	HLED_void_TurnToggle(&l3);
}


int main(void)
{
	MGI_void_Enable();
	
	MEXT_INT_0_voidInit();
	MEXT_INT_0_voidEnable();
	MEXT_INT_0_voidSenseControl(MEXT_INT_0_Sense_LowLevel);
	
		
		MEXT_INT_1_voidInit();
		MEXT_INT_1_voidEnable();
		MEXT_INT_1_voidSenseControl(MEXT_INT_1_Sense_LowLevel);
		
		
			
			MEXT_INT_2_voidInit();
			MEXT_INT_2_voidEnable();
			MEXT_INT_2_voidSenseControl(MEXT_INT_2_Sense_RisingEdge);
			
	
	l1 = HLED_HLed_t_Create(PinA0,HLED_ActiveHigh);
	l2 = HLED_HLed_t_Create(PinA1,HLED_ActiveHigh);
	l3 = HLED_HLed_t_Create(PinA2,HLED_ActiveHigh);

	MEXT_INT_0_voidSetCallback(cb0);
		MEXT_INT_1_voidSetCallback(cb1);
	MEXT_INT_2_voidSetCallback(cb2);

	while(1);
	
}

