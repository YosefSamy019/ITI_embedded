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

#define RS PinB1
#define RW PinB2
#define E1 PinB3
#define E2 PinB4



int main(void)
{
	MDIO_voidInit();
	
	HLCD_t lcd1, lcd2;
	
	{
		Pin_t dataPins[]  ={PinA7,PinA6,PinA5,PinA4,PinA3,PinA2,PinA1,PinA0};
		lcd1 = HLCD_HLCD_t_LcdCreate(RS,RW,E1,dataPins);
		lcd2 = HLCD_HLCD_t_LcdCreate(RS,RW,E2,dataPins);

		HLCD_void_DisplayOn(&lcd1);
		HLCD_void_DisplayOn(&lcd2);
		


		u8 cc0[] = HLCD_YOUSEF_AR_C1_5X8;
		u8 cc1[] = HLCD_YOUSEF_AR_C2_5X8;
		u8 cc2[] = HLCD_YOUSEF_AR_C3_5X8;
		u8 cc3[] = HLCD_YOUSEF_AR_C4_5X8;
		

		HLCD_void_CreateChar(&lcd1, 0,cc0);
		HLCD_void_CreateChar(&lcd1, 1,cc1);
		HLCD_void_CreateChar(&lcd1, 2,cc2);
		HLCD_void_CreateChar(&lcd1, 3,cc3);
		
		HLCD_void_CreateChar(&lcd2, 0,cc0);
		HLCD_void_CreateChar(&lcd2, 1,cc1);
		HLCD_void_CreateChar(&lcd2, 2,cc2);
		HLCD_void_CreateChar(&lcd2, 3,cc3);
		
				HLCD_void_setCursor(&lcd1,6,0);
				HLCD_void_setCursor(&lcd2,5,0);
		
		HLCD_void_WriteCharacter(&lcd1, 3);
		HLCD_void_WriteCharacter(&lcd1, 2);
		HLCD_void_WriteCharacter(&lcd1, 1);
		HLCD_void_WriteCharacter(&lcd1, 0);
		
		HLCD_void_WriteCharacter(&lcd2, 3);
		HLCD_void_WriteCharacter(&lcd2, 2);
		HLCD_void_WriteCharacter(&lcd2, 1);
		HLCD_void_WriteCharacter(&lcd2, 0);


	}
	
    while (1) 
    {
		HLCD_void_DisplayShiftLeft(&lcd1);
		HLCD_void_DisplayShiftRight(&lcd2);
		
		MDELAY_void_milli(500);
		
				HLCD_void_DisplayShiftRight(&lcd1);
				HLCD_void_DisplayShiftLeft(&lcd2);
				
						MDELAY_void_milli(500);

    } 
}

