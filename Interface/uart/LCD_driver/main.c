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

#include "MCAL/ICU/ICU_interface.h"

#include "MCAL/UART/UART_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_patterns.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_config.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#include "HAL/KEYPAD/KEYPAD_congif.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"

#define RS PinB1
#define RW PinB2
#define E PinB3

	HLCD_t lcd1;


void echo(u32 d){
		HLCD_void_WriteCharacter(&lcd1,d);

}

int main(void)
{
	
	MGI_void_Enable();
	MDIO_voidInit();
	
	Pin_t dataPins[]  ={PinA7,PinA6,PinA5,PinA4,PinA3,PinA2,PinA1,PinA0};
	lcd1 = HLCD_HLCD_t_LcdCreate(RS,RW,E,dataPins);

	HLCD_void_DisplayOn(&lcd1);
	HLCD_void_CursorBlinkOn(&lcd1);
	HLCD_void_CursorOn(&lcd1);

	MUART_voidInit();
	MUART_voidSetRXCallback(echo);

	while(1){
		//MUART_voidSendData('F');
		//HLCD_void_WriteCharacter(&lcd1,'F');
		MDELAY_void_milli(1000);
	}
}