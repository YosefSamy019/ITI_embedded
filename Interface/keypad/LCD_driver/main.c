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

#define RS PinB1
#define RW PinB2
#define E PinB3

int main(void)
{
	MDIO_voidInit();
	

	//HBUTTON_t btn = HBUTTON_HBUTTON_t_Create(PinB0,HBUTTON_inputInternalPullUp);
	//HLed_t led = HLED_HLed_t_Create(PinA2,HLED_ActiveHigh);
	Pin_t dataPins[] = {PinA7,PinA6,PinA5,PinA4,PinA3,PinA2,PinA1,PinA0};
	HLCD_t lcd = HLCD_HLCD_t_LcdCreate(RS,RW,E,dataPins);
	
	Pin_t rowPins[] = {PinC0,PinC1,PinC2,PinC3};
	Pin_t colPins[] = {PinC4,PinC5,PinC6,PinC7};
	HKEYPAD_t kp = HKEYPAD_HKEYPAD_t_Create(rowPins,colPins); 
	
	HLCD_void_DisplayOn(&lcd);
	//HLCD_void_CursorOn(&lcd);
	
	u8 a1[]= HLCD_YOUSEF_AR_C1_5X8;
	HLCD_void_CreateChar(&lcd,0,a1);
	
		
	u8 a2[]= HLCD_YOUSEF_AR_C2_5X8;
	HLCD_void_CreateChar(&lcd,1,a2);
	
	u8 a3[]= HLCD_YOUSEF_AR_C3_5X8;
	HLCD_void_CreateChar(&lcd,2,a3);
	
	u8 a4[]= HLCD_YOUSEF_AR_C4_5X8;
	HLCD_void_CreateChar(&lcd,3,a4);
	
	HLCD_void_WriteCharacter(&lcd,3);
	HLCD_void_WriteCharacter(&lcd,2);
	HLCD_void_WriteCharacter(&lcd,1);
	HLCD_void_WriteCharacter(&lcd,0);

	
    while (1) 
    {
		
    } 
}

