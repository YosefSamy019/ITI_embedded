/*
 * SEV_SEG_program.c
 *
 * Created: 03/08/2024 01:56:39 م
 *  Author: a24e4
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SEV_SEG_config.h"
#include "SEV_SEG_interface.h"
#include "SEV_SEG_private.h"

#define CREATE_BINARY(a,b,c,d,e,f,g) 0b##a##b##c##d##e##f##g##0

static  const u8 seven_seg_patterns[] = {
	CREATE_BINARY(1,1,1,1,1,1,0), // 0
	CREATE_BINARY(0,1,1,0,0,0,0), // 1
	CREATE_BINARY(1,1,0,1,1,0,1), // 2
	CREATE_BINARY(1,1,1,1,0,0,1), // 3
	CREATE_BINARY(0,1,1,0,0,1,1), // 4
	CREATE_BINARY(1,0,1,1,0,1,1), // 5
	CREATE_BINARY(1,0,1,1,1,1,1), // 6
	CREATE_BINARY(1,1,1,0,0,0,0), // 7
	CREATE_BINARY(1,1,1,1,1,1,1), // 8
	CREATE_BINARY(1,1,1,1,0,1,1), // 9
	CREATE_BINARY(1,1,1,0,1,1,1), // A
	CREATE_BINARY(0,0,1,1,1,1,1), // B
	CREATE_BINARY(1,0,0,1,1,1,0), // C
	CREATE_BINARY(0,1,1,1,1,0,1), // D
	CREATE_BINARY(1,0,0,1,1,1,1), // E
	CREATE_BINARY(1,0,0,0,1,1,1)  // F
};


HSEV_SEG_t HSEV_SEG_SEV_SEG_t_Create(HSEV_SEG_polarity A_HSEV_SEG_polarity_polarity,Pin_t A_Pin_t_pins[SEV_SEG_PINS_NO],Pin_t A_Pin_tpinDP){
	u8 L_u8_i;
	HSEV_SEG_t sevSeg;
	
	sevSeg.polarity =A_HSEV_SEG_polarity_polarity;
	sevSeg.pinDP = A_Pin_tpinDP;

	for (L_u8_i=0;L_u8_i<SEV_SEG_PINS_NO;L_u8_i++)
	{
		sevSeg.pins[L_u8_i] = A_Pin_t_pins[L_u8_i];
		MDIO_voidSetPinDir(A_Pin_t_pins[L_u8_i], OUTPUT);
	}
	
	MDIO_voidSetPinDir(A_Pin_tpinDP, OUTPUT);

	return sevSeg;
}

void HSEV_SEG_void_DisplayDigit(HSEV_SEG_t * A_HSEV_SEG_t_sevSeg,u8 A_u8_digit){
	u8 L_u8_binaryOut,L_u8_i;;
	
	if(A_u8_digit >= HSEV_SEG_MIN_NUM && A_u8_digit <= HSEV_SEG_MAX_NUM){
		L_u8_binaryOut = seven_seg_patterns[A_u8_digit];
	}else{
		L_u8_binaryOut = INVALID_PATTERN;
	}
	
	switch(A_HSEV_SEG_t_sevSeg->polarity){
		case HSEV_SEG_commonAnode: L_u8_binaryOut = ~L_u8_binaryOut; break;
		case HSEV_SEG_commonCathod: L_u8_binaryOut = L_u8_binaryOut; break;
	}
	
	for (L_u8_i=0;L_u8_i<SEV_SEG_PINS_NO;L_u8_i++)
	{
		MDIO_voidSetPinVal(A_HSEV_SEG_t_sevSeg->pins[L_u8_i],GET_BIT(L_u8_binaryOut,SEV_SEG_PINS_NO - L_u8_i ));
	}

		
}

void HSEV_SEG_void_DisplayOff(HSEV_SEG_t * A_HSEV_SEG_t_sevSeg){
	u8 L_u8_val,L_u8_i;
	
	switch(A_HSEV_SEG_t_sevSeg->polarity){
		case HSEV_SEG_commonAnode: L_u8_val = HIGH; break;
		case HSEV_SEG_commonCathod: L_u8_val = LOW ;break;
	}
	
	for (L_u8_i=0;L_u8_i<SEV_SEG_PINS_NO;L_u8_i++)
	{
			MDIO_voidSetPinVal(A_HSEV_SEG_t_sevSeg->pins[L_u8_i],L_u8_val);
	}
	
	MDIO_voidSetPinVal(A_HSEV_SEG_t_sevSeg->pinDP,L_u8_val);
}

void HSEV_SEG_void_TurnOnDot(HSEV_SEG_t * A_HSEV_SEG_t_sevSeg){
	switch(A_HSEV_SEG_t_sevSeg->polarity){
		case HSEV_SEG_commonAnode:  MDIO_voidSetPinVal(A_HSEV_SEG_t_sevSeg->pinDP,LOW);  break;
		case HSEV_SEG_commonCathod: MDIO_voidSetPinVal(A_HSEV_SEG_t_sevSeg->pinDP,HIGH);  break;
	}
}
void HSEV_SEG_void_TurnOffDot(HSEV_SEG_t * A_HSEV_SEG_t_sevSeg){
		switch(A_HSEV_SEG_t_sevSeg->polarity){
			case HSEV_SEG_commonAnode:  MDIO_voidSetPinVal(A_HSEV_SEG_t_sevSeg->pinDP,HIGH);  break;
			case HSEV_SEG_commonCathod: MDIO_voidSetPinVal(A_HSEV_SEG_t_sevSeg->pinDP,LOW);  break;
		}
}