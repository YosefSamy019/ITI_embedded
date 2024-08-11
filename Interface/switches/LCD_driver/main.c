/*
 * LCD_driver.c
 *
 * Created: 04/08/2024 08:24:43 ص
 * Author : a24e4
 */ 

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DELAY/DELAY_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_patterns.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_config.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#define RS PinB1
#define RW PinB2
#define E1 PinB3
#define E2 PinB4

int main(void)
{
	MDIO_voidInit();
	

	HBUTTON_t btn = HBUTTON_HBUTTON_t_Create(PinB0,HBUTTON_inputInternalPullUp);
	HLed_t led = HLED_HLed_t_Create(PinA2,HLED_ActiveHigh);
	
	do 
	{
		
	} while (0);
	
	
    while (1) 
    {
		if( HBUTTON_HBUTTON_state_t_getButtonState(&btn) == HBUTTON_pressed){
			HLED_void_TurnOn(&led);
		}else{
			HLED_void_TurnOff(&led);
		}
    } 
}

