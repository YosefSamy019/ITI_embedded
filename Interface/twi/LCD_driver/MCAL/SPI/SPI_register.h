/*
 * SPI_register.h
 *
 * Created: 16/08/2024 11:21:07 م
 *  Author: a24e4
 */ 


#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_


#define SPCR_REG (*((volatile u8*)0x2D))
#define SPSR_REG (*((volatile u8*)0x2E))
#define SPDR_REG (*((volatile u8*)0x2F))


#endif /* SPI_REGISTER_H_ */