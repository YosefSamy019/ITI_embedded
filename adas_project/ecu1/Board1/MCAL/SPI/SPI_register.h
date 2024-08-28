/*
 * SPI_register.h
 *
 *  Created on: Aug 2, 2022
 *      Author: mohammed ramadan
 */

#ifndef MCAL_SPI_SPI_REGISTER_H_
#define MCAL_SPI_SPI_REGISTER_H_

/*SPI control register*/
#define SPCR		*((volatile u8*)(0x2D))

/*SPI statues register*/
#define SPSR		*((volatile u8*)(0x2E))

/*SPI data register*/
#define SPDR		*((volatile u8*)(0x2F))

#endif /* MCAL_SPI_SPI_REGISTER_H_ */