/*
 * KEYPAD_interface.h
 *
 * Created: 05/08/2024 03:05:47 م
 *  Author: a24e4
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define HKEYPAD_ROWS_NO 4
#define HKEYPAD_COLS_NO 4

typedef struct  
{
	Pin_t rowPins[HKEYPAD_ROWS_NO];
	Pin_t colPins[HKEYPAD_COLS_NO];
	
}HKEYPAD_t;


HKEYPAD_t HKEYPAD_HKEYPAD_t_Create(Pin_t A_Pin_t_rowPins[HKEYPAD_ROWS_NO], Pin_t A_Pin_t_colPins[HKEYPAD_COLS_NO]);

u8 HKEYPAD_u8_getChar(HKEYPAD_t * A_HKEYPAD_t_keypad);

#endif /* KEYPAD_INTERFACE_H_ */