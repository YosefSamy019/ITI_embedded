/*
 * TWI_register.h
 *
 * Created: 18/08/2024 11:00:56 ص
 *  Author: a24e4
 */ 


#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_


/*TWI Bit rate register*/
#define TWBR_REG	*((volatile u8*)(0x20))

/*TWI control register*/
#define TWCR_REG	*((volatile u8*)(0x56))

/*TWI statues register*/
#define TWSR_REG	*((volatile u8*)(0x21))

/*TWI data register*/
#define TWDR_REG	*((volatile u8*)(0x23))

/*TWI address register*/
#define TWAR_REG	*((volatile u8*)(0x22))


#endif /* TWI_REGISTER_H_ */