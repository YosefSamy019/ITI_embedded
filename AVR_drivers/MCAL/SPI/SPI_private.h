/*
 * SPI_private.h
 *
 *  Created on: Aug 2, 2022
 *      Author: mohammed ramadan
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

/*SPI control register*/
#define  SPR0   0 /*SPI Clock Rate Select 0*/
#define  SPR1   1 /*SPI Clock Rate Select 1*/
#define  CPHA   2 /*clock phase*/
#define  CPOL   3 /*clock polarity*/
#define  MSTR   4 /*master slave select*/
#define  DORD   5 /*Data ordered*/
#define  SPE    6 /*SPI enable*/
#define  SPIE   7 /*SPI interrupt enable*/

/*SPI statues register*/
#define  SPI2X  0 /*Double SPI Speed Bit*/
#define  WCOL   6 /*Write COLlision Flag*/
#define  SPIF   7 /*SPI Interrupt Flag*/

/*define master mode*/
#define SPI_MASTER 1

/*define slave mode*/
#define SPI_SLAVE  2

/*set clock to master*/
#define PRESCALLER_4     1
#define PRESCALLER_16    2
#define PRESCALLER_64    3
#define PRESCALLER_128   4
#define PRESCALLER_2     5
#define PRESCALLER_8     6
#define PRESCALLER_32    7

/*dummy data for slave*/
#define DUMMY_DATA 0xff
#endif /* MCAL_SPI_SPI_PRIVATE_H_ */