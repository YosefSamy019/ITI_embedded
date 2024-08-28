/*
 * registers.h
 *
 *  Created on: Aug 2, 2024
 *      Author: Mahmoud Osman
 */

#ifndef MCAL_DIO_REGISTERS_H_
#define MCAL_DIO_REGISTERS_H_
#include "../../../LIB2/LIB/STD_TYPES.h"
#include "../../../LIB2/LIB/BIT_MATH.h"

///******DDR Addresses*********

#define DDRA *((volatile uint8 *) 0x3A )
#define DDRB *((volatile uint8 *) 0x37 )
#define DDRC *((volatile uint8 *) 0x34 )
#define DDRD *((volatile uint8 *) 0x31 )


///******PORTS Addresses*********

#define PORTA *((volatile uint8 *) 0x3B)
#define PORTB *((volatile uint8 *) 0x38)
#define PORTC *((volatile uint8 *) 0x35)
#define PORTD *((volatile uint8 *) 0x32)

///******PINS Addresses*********

#define PINA *((volatile uint8 *) 0x39)
#define PINB *((volatile uint8 *) 0x36)
#define PINC *((volatile uint8 *) 0x33)
#define PIND *((volatile uint8 *) 0x30)

#endif /* MCAL_DIO_REGISTERS_H_ */
