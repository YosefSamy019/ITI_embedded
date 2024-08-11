/*
 * LCD_interface.h
 *
 * Created: 04/08/2024 10:17:07 ص
 *  Author: a24e4
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "LCD_private.h"
#include "LCD_config.h"


#if HLCD_BIT_MODE_CONFIG == 0
	#define HLCD_DATA_PINS_NO 4 //4 bit mode
#else
	#define HLCD_DATA_PINS_NO 8 //8 bit mode
#endif



typedef struct{
	u8 entryMode_ID:1;
	u8 entryMode_SH:1;
	
	u8 displayControl_D:1;
	u8 displayControl_C:1;
	u8 displayControl_B:1;

	u8 functionSet_DL:1;
	u8 functionSet_N:1;
	u8 functionSet_F:1;
		
	Pin_t pinRS;
	Pin_t pinRW;
	Pin_t pinE;
	Pin_t pinsData[HLCD_DATA_PINS_NO];

}HLCD_t;


HLCD_t HLCD_HLCD_t_LcdCreate(Pin_t pinRS,Pin_t pinRW,Pin_t pinE,Pin_t pinsData[HLCD_DATA_PINS_NO]);

void HLCD_void_DisplayOn(HLCD_t *A_HLCD_t_lcd);
void HLCD_void_DisplayOff(HLCD_t *A_HLCD_t_lcd);

void HLCD_void_CursorOn(HLCD_t *A_HLCD_t_lcd);
void HLCD_void_CursorOff(HLCD_t *A_HLCD_t_lcd);

void HLCD_void_CursorBlinkOn(HLCD_t *A_HLCD_t_lcd);
void HLCD_void_CursorBlinkOff(HLCD_t *A_HLCD_t_lcd);

void HLCD_void_WriteCharacter(HLCD_t *A_HLCD_t_lcd,u8 A_u8_char);
void HLCD_void_WriteString(HLCD_t *A_HLCD_t_lcd,u8 A_u8_string[]);

void HLCD_void_setCursor(HLCD_t *A_HLCD_t_lcd,u8 A_u8_x,u8 A_u8_y);

void HLCD_void_DisplayShiftRight(HLCD_t *A_HLCD_t_lcd);
void HLCD_void_DisplayShiftLeft(HLCD_t *A_HLCD_t_lcd);

void HLCD_void_CursorShiftRight(HLCD_t *A_HLCD_t_lcd);
void HLCD_void_CursorShiftLeft(HLCD_t *A_HLCD_t_lcd);

void HLCD_void_ClearDisplay(HLCD_t *A_HLCD_t_lcd);
void HLCD_void_ReturnHome(HLCD_t *A_HLCD_t_lcd);

void HLCD_void_WriteNumber(HLCD_t *A_HLCD_t_lcd,s32 A_s32_number);

void HLCD_void_CreateChar(HLCD_t *A_HLCD_t_lcd,u8 A_u8_BlockIndex, u8 *A_u8_Array);

#endif /* LCD_INTERFACE_H_ */