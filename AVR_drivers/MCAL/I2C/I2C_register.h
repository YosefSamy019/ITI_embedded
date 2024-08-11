/*
 * T2C_register.h
 *
 *  Created on: Aug 9, 2022
 *      Author: mohammed ramadan
 */

#ifndef MCAL_TWI_T2C_REGISTER_H_
#define MCAL_TWI_T2C_REGISTER_H_

/*TWI Bit rate register*/
#define TWBR	*((volatile u8*)(0x20))

/*TWI control register*/
#define TWCR	*((volatile u8*)(0x56))

/*TWI statues register*/
#define TWSR	*((volatile u8*)(0x21))

/*TWI data register*/
#define TWDR	*((volatile u8*)(0x23))

/*TWI address register*/
#define TWAR	*((volatile u8*)(0x22))

#endif /* MCAL_TWI_T2C_REGISTER_H_ */
