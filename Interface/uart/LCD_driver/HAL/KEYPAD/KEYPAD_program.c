/*
 * KEYPAD_program.c
 *
 * Created: 05/08/2024 03:06:27 م
 *  Author: a24e4
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DELAY/DELAY_interface.h"

#include "KEYPAD_congif.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"

static const u8 keypadData[HKEYPAD_ROWS_NO][HKEYPAD_COLS_NO]={
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'C','0','=','+'}
};

HKEYPAD_t HKEYPAD_HKEYPAD_t_Create(Pin_t A_Pin_t_rowPins[HKEYPAD_ROWS_NO], Pin_t A_Pin_t_colPins[HKEYPAD_COLS_NO]){
	u8 L_u8_i;
	HKEYPAD_t L_HKEYPAD_t_keypad;
	
	for (L_u8_i = 0; L_u8_i < HKEYPAD_ROWS_NO ;L_u8_i++)
	{
		L_HKEYPAD_t_keypad.rowPins[L_u8_i] = A_Pin_t_rowPins[L_u8_i];
		
		MDIO_voidSetPinDir(A_Pin_t_rowPins[L_u8_i],INPUT_PULL_UP);
	}
	
	for (L_u8_i = 0; L_u8_i < HKEYPAD_COLS_NO ;L_u8_i++)
	{
		L_HKEYPAD_t_keypad.colPins[L_u8_i] = A_Pin_t_colPins[L_u8_i];
		
		MDIO_voidSetPinDir(A_Pin_t_colPins[L_u8_i],OUTPUT);
		MDIO_voidSetPinVal(A_Pin_t_colPins[L_u8_i],HIGH);
	}
	
	return L_HKEYPAD_t_keypad;
}


u8 HKEYPAD_u8_getChar(HKEYPAD_t * A_HKEYPAD_t_keypad){
	u8 L_u8_i,L_u8_j,L_u8_temp;
	u8 L_u8_pressedChar = HKEYPAD_DEFAULT_RETURN_CHAR;	
	
	for (L_u8_i=0;L_u8_i < HKEYPAD_COLS_NO;L_u8_i++)
	{	
		MDIO_voidSetPinVal(A_HKEYPAD_t_keypad->colPins[L_u8_i],LOW);
		
		for (L_u8_j=0;L_u8_j < HKEYPAD_ROWS_NO;L_u8_j++)
		{
			L_u8_temp = MDIO_u8GetPinVal(A_HKEYPAD_t_keypad->rowPins[L_u8_j]);
			if(L_u8_temp == LOW){
				L_u8_pressedChar = keypadData[L_u8_j][L_u8_i];
				
				#if WAIT_BUTTON_TO_RELEASE==1
					//wait button to be released
					L_u8_j = L_u8_j - 1;
				#endif
			}
		}
		
		MDIO_voidSetPinVal(A_HKEYPAD_t_keypad->colPins[L_u8_i],HIGH);
	}
	
	
	
	MDELAY_void_milli(HKEPAD_DELAY_TIME_MS_AFTER_READ);
	
	return L_u8_pressedChar;
}
