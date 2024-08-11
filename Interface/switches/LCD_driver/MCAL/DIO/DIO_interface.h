/*
 * DIO_interface.h
 *
 * Created: 03/08/2024 12:05:19 م
 *  Author: a24e4
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"


#define HIGH ((u8)1)
#define LOW ((u8)0)

#define OUTPUT ((u8)1)
#define INPUT ((u8)0)
#define INPUT_PULL_UP ((u8)2)



typedef enum {
	PinA0 = 0xA0,
	PinA1 = 0xA1,
	PinA2 = 0xA2,
	PinA3 = 0xA3,
	PinA4 = 0xA4,
	PinA5 = 0xA5,
	PinA6 = 0xA6,
	PinA7 = 0xA7,
	PinB0 = 0xB0,
	PinB1 = 0xB1,
	PinB2 = 0xB2,
	PinB3 = 0xB3,
	PinB4 = 0xB4,
	PinB5 = 0xB5,
	PinB6 = 0xB6,
	PinB7 = 0xB7,
	PinC0 = 0xC0,
	PinC1 = 0xC1,
	PinC2 = 0xC2,
	PinC3 = 0xC3,
	PinC4 = 0xC4,
	PinC5 = 0xC5,
	PinC6 = 0xC6,
	PinC7 = 0xC7,
	PinD0 = 0xD0,
	PinD1 = 0xD1,
	PinD2 = 0xD2,
	PinD3 = 0xD3,
	PinD4 = 0xD4,
	PinD5 = 0xD5,
	PinD6 = 0xD6,
	PinD7 = 0xD7	
}Pin_t;


void MDIO_voidInit(void);
void MDIO_voidSetPinDir(Pin_t A_Pin_tPin, u8 A_u8Dir);
void MDIO_voidSetPinVal(Pin_t A_Pin_tPin, u8 A_u8Val);
u8	 MDIO_u8GetPinVal(Pin_t A_Pin_tPin);
void MDIO_voidTogPinVal(Pin_t A_Pin_tPin);







#endif /* DIO_INTERFACE_H_ */