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
		//lcd2 = HLCD_HLCD_t_LcdCreate(RS,RW,E2,dataPins);

		HLCD_void_DisplayOn(&lcd1);
		//HLCD_void_DisplayOn(&lcd2);
		
		u8 cc0[] = LCD_PATTERN_ARROW_UP_ANIM_1_5X8;
		u8 cc1[] = LCD_PATTERN_ARROW_UP_ANIM_2_5X8;
		u8 cc2[] = LCD_PATTERN_ARROW_UP_ANIM_3_5X8;

		HLCD_void_CreateChar(&lcd1, 0,cc0);
		HLCD_void_CreateChar(&lcd1, 1,cc1);
		HLCD_void_CreateChar(&lcd1, 2,cc2);

	}
	
	//LCD_void_WriteString(&lcd1,"Youssef: ");
	//HLCD_void_WriteString(&lcd2,"Samy: ");
	HLCD_void_WriteCharacter(&lcd1,0);

	u8 i=0;

    while (1) 
    {
		
		HLCD_void_setCursor(&lcd1,0,0);
		HLCD_void_WriteCharacter(&lcd1,i);
		i = (i+1)%3;
		
		HLCD_void_setCursor(&lcd1,0,1);
		HLCD_void_WriteCharacter(&lcd1,i);
		i = (i+1)%3;
		
		MDELAY_void_milli(200);
    } 
}

