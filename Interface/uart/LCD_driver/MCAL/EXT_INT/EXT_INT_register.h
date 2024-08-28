/*
 * EXT_INT_0_register.h
 *
 * Created: 10/08/2024 10:33:37 ص
 *  Author: a24e4
 */ 


#ifndef EXT_INT_0_REGISTER_H_
#define EXT_INT_0_REGISTER_H_


#define MCUCR_REG (*((volatile u8*)0x55))
#define MCUCR_ISC00_BIT 0
#define MCUCR_ISC01_BIT 1
#define MCUCR_ISC10_BIT 2
#define MCUCR_ISC11_BIT 3

#define GICR_REG (*((volatile u8*)0x5B))
#define GICR_INT2_BIT 5
#define GICR_INT0_BIT 6
#define GICR_INT1_BIT 7

#define MCUCSR_REG (*((volatile u8*)0x54))
#define MCUCSR_ISC2_BIT 6




#endif /* EXT_INT_0_REGISTER_H_ */