/*
 * LCD_program.c
 *
 * Created: 04/08/2024 10:18:14 ص
 *  Author: a24e4
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DELAY/DELAY_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

static void HLCD_void_send(HLCD_t *A_HLCD_t_lcd,u8 A_u8_cmd,u8 A_u8_rs, u8 A_u8_rw,u32 A_u8_executionTime);

HLCD_t HLCD_HLCD_t_LcdCreate(Pin_t A_Pin_t_pinRS,Pin_t A_Pin_t_pinRW,Pin_t A_Pin_t_pinE,Pin_t A_Pin_t_pinsData[HLCD_DATA_PINS_NO]){
	HLCD_t L_lcd_lcd; 
	u8 L_u8_i;
	
	MDELAY_void_micro(HLCD_BEFORE_INIT_TIME_US);
	
	L_lcd_lcd.pinE = A_Pin_t_pinE;
	L_lcd_lcd.pinRW = A_Pin_t_pinRW;
	L_lcd_lcd.pinRS = A_Pin_t_pinRS;
	
	MDIO_voidSetPinDir(A_Pin_t_pinE,OUTPUT);
	MDIO_voidSetPinDir(A_Pin_t_pinRW,OUTPUT);
	MDIO_voidSetPinDir(A_Pin_t_pinRS,OUTPUT);
	
	for (L_u8_i=0;L_u8_i<HLCD_DATA_PINS_NO;L_u8_i++)
	{
		
		L_lcd_lcd.pinsData[L_u8_i] = A_Pin_t_pinsData[L_u8_i];
		
		MDIO_voidSetPinDir(A_Pin_t_pinsData[L_u8_i],OUTPUT);
		
	}
	
	//initialize commands
	L_lcd_lcd.functionSet_DL = HLCD_BIT_MODE_CONFIG;
	L_lcd_lcd.functionSet_N = 1;
	L_lcd_lcd.functionSet_F = 0;
	HLCD_void_send(
	&L_lcd_lcd,
	HLCD_FUNCTION_SET_CMD(HLCD_BIT_MODE_CONFIG,1,0),
	HLCD_FUNCTION_SET_CMD_RS,
	HLCD_FUNCTION_SET_CMD_RW,
	HLCD_FUNCTION_SET_CMD_TIME_US
	);

	L_lcd_lcd.displayControl_D = 0;
	L_lcd_lcd.displayControl_C = 0;
	L_lcd_lcd.displayControl_B = 0;
	HLCD_void_send(
	&L_lcd_lcd,
	HLCD_DISPLAY_CONTROL_CMD(0,0,0),
	HLCD_DISPLAY_CONTROL_CMD_RS,
	HLCD_DISPLAY_CONTROL_CMD_RW,
	HLCD_DISPLAY_CONTROL_CMD_TIME_US
	);

	HLCD_void_send(
	&L_lcd_lcd,
	HLCD_CLR_SCREEN_CMD(),
	HLCD_CLR_SCREEN_CMD_RS,
	HLCD_CLR_SCREEN_CMD_RW,
	HLCD_CLR_SCREEN_CMD_TIME_US
	);

	HLCD_void_send(
	&L_lcd_lcd,
	HLCD_RETURN_HOME_CMD(),
	HLCD_RETURN_HOME_CMD_RS,
	HLCD_RETURN_HOME_CMD_RW,
	HLCD_RETURN_HOME_CMD_TIME_US
	);

	L_lcd_lcd.entryMode_ID = 1;
	L_lcd_lcd.entryMode_SH = 0;

	HLCD_void_send(
	&L_lcd_lcd,
	HLCD_ENTRY_SET_MODE_CMD(1,0),
	HLCD_ENTRY_SET_MODE_CMD_RS,
	HLCD_ENTRY_SET_MODE_CMD_RW,
	HLCD_ENTRY_SET_MODE_CMD_TIME_US
	);
	
	return L_lcd_lcd;
}

void HLCD_void_DisplayOn(HLCD_t *A_HLCD_t_lcd){
	A_HLCD_t_lcd->displayControl_D = 1;
	HLCD_void_send(
	A_HLCD_t_lcd,
	HLCD_DISPLAY_CONTROL_CMD(A_HLCD_t_lcd->displayControl_D,A_HLCD_t_lcd->displayControl_C,A_HLCD_t_lcd->displayControl_B),
	HLCD_DISPLAY_CONTROL_CMD_RS,
	HLCD_DISPLAY_CONTROL_CMD_RW,
	HLCD_DISPLAY_CONTROL_CMD_TIME_US);
}

void HLCD_void_DisplayOff(HLCD_t *A_HLCD_t_lcd){
	A_HLCD_t_lcd->displayControl_D = 0;
	HLCD_void_send(
	A_HLCD_t_lcd,
	HLCD_DISPLAY_CONTROL_CMD(A_HLCD_t_lcd->displayControl_D,A_HLCD_t_lcd->displayControl_C,A_HLCD_t_lcd->displayControl_B),
	HLCD_DISPLAY_CONTROL_CMD_RS,
	HLCD_DISPLAY_CONTROL_CMD_RW,
	HLCD_DISPLAY_CONTROL_CMD_TIME_US);
}



void HLCD_void_CursorOn(HLCD_t *A_HLCD_t_lcd){
		A_HLCD_t_lcd->displayControl_C = 1;
		HLCD_void_send(
		A_HLCD_t_lcd,
		HLCD_DISPLAY_CONTROL_CMD(A_HLCD_t_lcd->displayControl_D,A_HLCD_t_lcd->displayControl_C,A_HLCD_t_lcd->displayControl_B),
		HLCD_DISPLAY_CONTROL_CMD_RS,
		HLCD_DISPLAY_CONTROL_CMD_RW,
		HLCD_DISPLAY_CONTROL_CMD_TIME_US);
}
void HLCD_void_CursorOff(HLCD_t *A_HLCD_t_lcd){
		A_HLCD_t_lcd->displayControl_C = 0;
		HLCD_void_send(
		A_HLCD_t_lcd,
		HLCD_DISPLAY_CONTROL_CMD(A_HLCD_t_lcd->displayControl_D,A_HLCD_t_lcd->displayControl_C,A_HLCD_t_lcd->displayControl_B),
		HLCD_DISPLAY_CONTROL_CMD_RS,
		HLCD_DISPLAY_CONTROL_CMD_RW,
		HLCD_DISPLAY_CONTROL_CMD_TIME_US);
}

void HLCD_void_CursorBlinkOn(HLCD_t *A_HLCD_t_lcd){
		A_HLCD_t_lcd->displayControl_B = 1;
		HLCD_void_send(
		A_HLCD_t_lcd,
		HLCD_DISPLAY_CONTROL_CMD(A_HLCD_t_lcd->displayControl_D,A_HLCD_t_lcd->displayControl_C,A_HLCD_t_lcd->displayControl_B),
		HLCD_DISPLAY_CONTROL_CMD_RS,
		HLCD_DISPLAY_CONTROL_CMD_RW,
		HLCD_DISPLAY_CONTROL_CMD_TIME_US);
}
void HLCD_void_CursorBlinkOff(HLCD_t *A_HLCD_t_lcd){
		A_HLCD_t_lcd->displayControl_B = 0;
		HLCD_void_send(
		A_HLCD_t_lcd,
		HLCD_DISPLAY_CONTROL_CMD(A_HLCD_t_lcd->displayControl_D,A_HLCD_t_lcd->displayControl_C,A_HLCD_t_lcd->displayControl_B),
		HLCD_DISPLAY_CONTROL_CMD_RS,
		HLCD_DISPLAY_CONTROL_CMD_RW,
		HLCD_DISPLAY_CONTROL_CMD_TIME_US);
}

void HLCD_void_WriteCharacter(HLCD_t *A_HLCD_t_lcd,u8 A_u8_char){
	HLCD_void_send(
	A_HLCD_t_lcd,
	HLCD_WRITE_DATA_TO_ADDRESS_CMD(A_u8_char),
	HLCD_WRITE_DATA_TO_ADDRESS_CMD_RS,
	HLCD_WRITE_DATA_TO_ADDRESS_CMD_RW,
	HLCD_WRITE_DATA_TO_ADDRESS_CMD_TIME_US);
}

static void HLCD_void_send(HLCD_t *A_HLCD_t_lcd,u8 A_u8_cmd,u8 A_u8_rs, u8 A_u8_rw,u32 A_u8_executionTime){
	u8 L_u8_i;
	
	MDIO_voidSetPinVal(A_HLCD_t_lcd->pinRS,A_u8_rs);
	MDIO_voidSetPinVal(A_HLCD_t_lcd->pinRW,A_u8_rw);
	

	if(A_HLCD_t_lcd->functionSet_DL == 1){
		//8 bit mode
		for(L_u8_i=0;L_u8_i<HLCD_DATA_PINS_NO;L_u8_i++){
			MDIO_voidSetPinVal(A_HLCD_t_lcd->pinsData[L_u8_i],GET_BIT(A_u8_cmd,HLCD_DATA_PINS_NO - L_u8_i -1));	
		}
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinE,HIGH);
		MDELAY_void_micro(HLCD_CLK_HIGH_LVL_TIME_US);
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinE,LOW);
		
	}
	else{
		//4 bit mode
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinsData[0],GET_BIT(A_u8_cmd, 7 ));
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinsData[1],GET_BIT(A_u8_cmd, 6 ));
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinsData[2],GET_BIT(A_u8_cmd, 5 ));
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinsData[3],GET_BIT(A_u8_cmd, 4 ));

		
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinE,HIGH);
		MDELAY_void_micro(HLCD_CLK_HIGH_LVL_TIME_US);
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinE,LOW);
		
		MDELAY_void_micro(HLCD_TIME_BETWEEN_SEND_2_NIPPES_US);
		
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinsData[0],GET_BIT(A_u8_cmd, 3 ));
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinsData[1],GET_BIT(A_u8_cmd, 2 ));
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinsData[2],GET_BIT(A_u8_cmd, 1 ));
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinsData[3],GET_BIT(A_u8_cmd, 0 ));
		
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinE,HIGH);
		MDELAY_void_micro(HLCD_CLK_HIGH_LVL_TIME_US);
		MDIO_voidSetPinVal(A_HLCD_t_lcd->pinE,LOW);
	}

	MDELAY_void_micro(HLCD_AUXILIARY_TIME_AFTER_SEND_CMD_US + A_u8_executionTime);

}

void HLCD_void_WriteString(HLCD_t *A_HLCD_t_lcd,u8 A_u8_string[]){
	while(*A_u8_string != NULL){
		HLCD_void_WriteCharacter(A_HLCD_t_lcd,*A_u8_string);
		A_u8_string++;
	}
}

void HLCD_void_setCursor(HLCD_t *A_HLCD_t_lcd,u8 A_u8_x,u8 A_u8_y){
	u8 L_u8_address = 0x00;
	
	L_u8_address = HLCD_2_LINE_DISPLAY_MODE_REG_LINE_2_ADDRESS_START * A_u8_y + A_u8_x;
	
	HLCD_void_send(
	A_HLCD_t_lcd,
	HLCD_SET_DDRAM_ADDRESS_CMD(L_u8_address),
	HLCD_SET_DDRAM_ADDRESS_CMD_RS,
	HLCD_SET_DDRAM_ADDRESS_CMD_RW,
	HLCD_SET_DDRAM_ADDRESS_CMD_TIME_US);
}

void HLCD_void_DisplayShiftRight(HLCD_t *A_HLCD_t_lcd){
	HLCD_void_send(
	A_HLCD_t_lcd,
	HLCD_CURSOR_DISPLAY_SHIFT_CMD(1,1),
	HLCD_CURSOR_DISPLAY_SHIFT_CMD_RS,
	HLCD_CURSOR_DISPLAY_SHIFT_CMD_RW,
	HLCD_CURSOR_DISPLAY_SHIFT_CMD_TIME_US);
}

void HLCD_void_DisplayShiftLeft(HLCD_t *A_HLCD_t_lcd){
		HLCD_void_send(
		A_HLCD_t_lcd,
		HLCD_CURSOR_DISPLAY_SHIFT_CMD(1,0),
		HLCD_CURSOR_DISPLAY_SHIFT_CMD_RS,
		HLCD_CURSOR_DISPLAY_SHIFT_CMD_RW,
		HLCD_CURSOR_DISPLAY_SHIFT_CMD_TIME_US);
}


void HLCD_void_CursorShiftRight(HLCD_t *A_HLCD_t_lcd){
	HLCD_void_send(
	A_HLCD_t_lcd,
	HLCD_CURSOR_DISPLAY_SHIFT_CMD(0,1),
	HLCD_CURSOR_DISPLAY_SHIFT_CMD_RS,
	HLCD_CURSOR_DISPLAY_SHIFT_CMD_RW,
	HLCD_CURSOR_DISPLAY_SHIFT_CMD_TIME_US);	
}
void HLCD_void_CursorShiftLeft(HLCD_t *A_HLCD_t_lcd){
	HLCD_void_send(
	A_HLCD_t_lcd,
	HLCD_CURSOR_DISPLAY_SHIFT_CMD(0,0),
	HLCD_CURSOR_DISPLAY_SHIFT_CMD_RS,
	HLCD_CURSOR_DISPLAY_SHIFT_CMD_RW,
	HLCD_CURSOR_DISPLAY_SHIFT_CMD_TIME_US);	
}

void HLCD_void_ClearDisplay(HLCD_t *A_HLCD_t_lcd){
		HLCD_void_send(
		A_HLCD_t_lcd,
		HLCD_CLR_SCREEN_CMD(),
		HLCD_CLR_SCREEN_CMD_RS,
		HLCD_CLR_SCREEN_CMD_RW,
		HLCD_CLR_SCREEN_CMD_TIME_US
		);
		
}
void HLCD_void_ReturnHome(HLCD_t *A_HLCD_t_lcd){
		HLCD_void_send(
		A_HLCD_t_lcd,
		HLCD_RETURN_HOME_CMD(),
		HLCD_RETURN_HOME_CMD_RS,
		HLCD_RETURN_HOME_CMD_RW,
		HLCD_RETURN_HOME_CMD_TIME_US
		);
}

void HLCD_void_WriteNumber(HLCD_t *A_HLCD_t_lcd,s32 A_s32_number){
	u8 L_u8_signFlag;
	s32 L_s32_ReversedNum =0;
	u8 L_digitsCounter =0;
	
	if(A_s32_number >= 0){
		L_u8_signFlag = 0;
	}else{
		L_u8_signFlag = 1;
		A_s32_number = A_s32_number * -1;
	}
	
	do 
	{
		L_digitsCounter++;
		L_s32_ReversedNum = L_s32_ReversedNum*10 + A_s32_number%10;
		A_s32_number = A_s32_number / 10;
		
	} while (A_s32_number != 0);
	
	if(L_u8_signFlag == 1){
		HLCD_void_WriteCharacter(A_HLCD_t_lcd,'-');
	}
	
	while(L_digitsCounter > 0){
		HLCD_void_WriteCharacter(A_HLCD_t_lcd,'0'+  L_s32_ReversedNum%10);
		L_s32_ReversedNum = L_s32_ReversedNum / 10;
		L_digitsCounter--;
	}
	
}

void HLCD_void_CreateChar(HLCD_t *A_HLCD_t_lcd, u8 A_u8_BlockIndex, u8 *A_u8_Array){
	u8 L_u8_BlockAddress = A_u8_BlockIndex * HLCD_TOTAL_PATTERNS_NO;
	u8 L_u8_iterator;
	
	HLCD_void_send(
		A_HLCD_t_lcd,
		HLCD_SET_CGRAM_ADDRESS_CMD(L_u8_BlockAddress),
		HLCD_SET_CGRAM_ADDRESS_CMD_RS,
		HLCD_SET_CGRAM_ADDRESS_CMD_RW,
		HLCD_SET_CGRAM_ADDRESS_CMD_TIME_US
	);
	
	for (L_u8_iterator =0 ;L_u8_iterator < HLCD_PATTERN_ROWS_NO;L_u8_iterator ++)
	{
		HLCD_void_WriteCharacter(A_HLCD_t_lcd,A_u8_Array[L_u8_iterator]);
	}
	
	HLCD_void_setCursor(A_HLCD_t_lcd,0,0);
	
}
