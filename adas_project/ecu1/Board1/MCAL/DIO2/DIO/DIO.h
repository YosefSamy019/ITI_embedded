/*
 * IncFile1.h
 *
 * Created: 20/02/2024 23:07:56
 *  Author: PC
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../../LIB2/LIB/STD_TYPES.h"
#include "../../../LIB2/LIB/BIT_MATH.h"
#include "DIO_config.h"
void DIO_PinMode(uint8 Pin_No ,uint8 Mode );
void DIO_digitalWrite(uint8 Pin_No ,uint8 State);
uint8 DIO_digitalRead(uint8 Pin_No );

#endif /* DIO_ */
