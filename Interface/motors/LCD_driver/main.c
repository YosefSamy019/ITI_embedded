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


Pin_t stepperPins[]= {PinD7,PinD6,PinD5,PinD4};
u8 si = 4,i;

int main(void)
{
	
	
	MDIO_voidInit();
	
	for(i=0;i<si;i++){
		MDIO_voidSetPinDir(stepperPins[i],OUTPUT);
		MDIO_voidSetPinVal(stepperPins[i],HIGH);
	}
	
	u8 p=0,pp=si-1;
	
    while (1) 
    {
		MDIO_voidSetPinVal(stepperPins[pp],HIGH);
		MDIO_voidSetPinVal(stepperPins[p],LOW);
		
		p = (p+1)%si;
		pp = (pp+1)%si;
		
		MDELAY_void_milli(3000);
    } 
}

