/*
 * LCD_driver.c
 *
 * Created: 04/08/2024 08:24:43 ص
 * Author : a24e4
 */ 

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DELAY/DELAY_interface.h"

#include "MCAL/GI/GI_interface.h"

#include "MCAL/EXT_INT/EXT_INT_interface.h"

#include "MCAL/ADC/ADC_interface.h"

#include "MCAL/TIMER_0/TIMER_0_interface.h"

#include "MCAL/TIMER_2/TIMER_2_interface.h"


#include "MCAL/ICU/ICU_interface.h"

#include "MCAL/UART/UART_interface.h"

#include "MCAL/SPI/SPI_interface.h"

#include "MCAL/TWI/TWI_interface.h"

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
	Pin_t pins[] = {PinA7,PinA6,PinA5,PinA4,PinA3,PinA2,PinA1,PinA0};
	HLCD_t lcd = HLCD_HLCD_t_LcdCreate(PinB0,PinB1,PinB2,pins);
	
	MICU_voidInit();
	MGI_void_Enable();
	
	HLCD_void_DisplayOn(&lcd);
	HLCD_void_WriteString(&lcd,"ON");
	MDELAY_void_milli(1000);

	while(1){
		
		HLCD_void_setCursor(&lcd,0,0);
		HLCD_void_WriteString(&lcd,"LOW_ms:  ");
		HLCD_void_WriteNumber(&lcd,MICU_u64ReadTimeLowMicro()/1000);
		HLCD_void_WriteString(&lcd,"     ");

		HLCD_void_setCursor(&lcd,0,1);
		HLCD_void_WriteString(&lcd,"HIGH_ms: ");
		HLCD_void_WriteNumber(&lcd,MICU_u64ReadTimeHighMicro()/1000);	
		HLCD_void_WriteString(&lcd,"     ");

		MDELAY_void_milli(100);

	}
}