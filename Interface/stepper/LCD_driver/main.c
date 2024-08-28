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

#include "HAL/KEYPAD/KEYPAD_congif.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"

#include "HAL/STEPPER/STEPPER_interface.h"



int main(void)
{
	u8 i =0;
	
	MDIO_voidInit();


	Pin_t stepperPins[]= {PinD0,PinD1,PinD2,PinD3};
	HStepper_t stepper = HStepper_HStepper_t_Create(stepperPins);
	
    while (1) 
    {
		for(i=0;i<4;i++){
			HStepper_stepForward(&stepper);
			MDELAY_void_milli(500);
		}
		for(i=0;i<4;i++){
			HStepper_stepBackward(&stepper);
			MDELAY_void_milli(500);
		}

    } 
}

