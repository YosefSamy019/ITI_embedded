/*
 * LCD_driver.c
 *
 * Created: 04/08/2024 08:24:43 ص
 * Author : a24e4
 */ 

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DELAY/DELAY_interface.h"
#include "MCAL/GI/GI_interface.h"
#include "MCAL/TWI/TWI_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_patterns.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_config.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#include "HAL/KEYPAD/KEYPAD_congif.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"

#include "HAL/STEPPER/STEPPER_interface.h"
#include "HAL/EEPROM_24C02/EEPROM_24C02_interface.h"


int main(void)
{
	MDIO_voidInit();
	MTWI_void_initMaster();
	MGI_void_Enable();
	
	


    while (1) 
    {
			HEEPROM_24C02_voidWrite(0,'I');
			HEEPROM_24C02_voidWrite(1,'T');
			HEEPROM_24C02_voidWrite(2,'I');
			HEEPROM_24C02_voidWrite(3,' ');
			HEEPROM_24C02_voidWrite(4,'B');
			HEEPROM_24C02_voidWrite(5,'E');
			HEEPROM_24C02_voidWrite(6,'N');
			HEEPROM_24C02_voidWrite(7,'H');
			HEEPROM_24C02_voidWrite(8,'A');

		MDELAY_void_milli(1000);
    } 
}

