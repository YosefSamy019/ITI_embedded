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

#include "MCAL/ADC/ADC_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_patterns.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_config.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#include "HAL/KEYPAD/KEYPAD_congif.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"

#define LCD_RS PinB1
#define LCD_RW PinB2
#define LCD_E  PinB3

volatile u32 G_adcRead=0;

void callBack(u32 A_u32_v){
	G_adcRead= A_u32_v;
}

int main(void)
{
	MDELAY_void_milli(20);
	
		HLCD_t L_lcd;
		Pin_t dataPins[] = {PinA7,PinA6,PinA5,PinA4,PinA3,PinA2,PinA1,PinA0};
		L_lcd = HLCD_HLCD_t_LcdCreate(LCD_RS,LCD_RW,LCD_E,dataPins);
		
		MGI_void_Enable();
		MDIO_voidInit();
		MADC_voidInit();
		MADC_voidSetCallback(callBack);
		MADC_voidEnableInterrupt();
		
		HLCD_void_DisplayOn(&L_lcd);
		HLCD_void_CursorBlinkOn(&L_lcd);
		HLCD_void_CursorOn(&L_lcd);
		
		
		while(1){
			HLCD_void_WriteString(&L_lcd,"TEMP: ");		
			
			
				
			HLCD_void_WriteNumber(&L_lcd, ((G_adcRead * 5000)/1024 ) );
			HLCD_void_WriteString(&L_lcd,"     ");
			HLCD_void_ReturnHome(&L_lcd);
			
			MDELAY_void_milli(100);
			MADC_voidStartConversion(MADC_SINGLE_CHANNEL_0);
		}
	
}

