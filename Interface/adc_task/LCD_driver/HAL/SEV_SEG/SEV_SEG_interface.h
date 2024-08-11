/*
 * SEV_SEG_interface.h
 *
 * Created: 03/08/2024 01:55:58 م
 *  Author: a24e4
 */ 


#ifndef SEV_SEG_INTERFACE_H_
#define SEV_SEG_INTERFACE_H_

#include "SEV_SEG_private.h"

typedef enum{
	HSEV_SEG_commonAnode,
	HSEV_SEG_commonCathod
}HSEV_SEG_polarity;

typedef struct{
	
	HSEV_SEG_polarity polarity;
	Pin_t pins[SEV_SEG_PINS_NO];
	Pin_t pinDP;
}HSEV_SEG_t;



HSEV_SEG_t HSEV_SEG_SEV_SEG_t_Create(HSEV_SEG_polarity A_HSEV_SEG_polarity_polarity,Pin_t A_Pin_t_pins[SEV_SEG_PINS_NO],Pin_t A_Pin_tpinDP);

void HSEV_SEG_void_DisplayDigit(HSEV_SEG_t * A_HSEV_SEG_t_sevSeg,u8 A_u8_digit);

void HSEV_SEG_void_DisplayOff(HSEV_SEG_t * A_HSEV_SEG_t_sevSeg);

void HSEV_SEG_void_TurnOnDot(HSEV_SEG_t * A_HSEV_SEG_t_sevSeg);

void HSEV_SEG_void_TurnOffDot(HSEV_SEG_t * A_HSEV_SEG_t_sevSeg);

#endif /* SEV_SEG_INTERFACE_H_ */