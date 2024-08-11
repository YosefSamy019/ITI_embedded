/*
 * TIMER_0_register.h
 *
 * Created: 11/08/2024 12:08:39 م
 *  Author: a24e4
 */ 


#ifndef TIMER_0_REGISTER_H_
#define TIMER_0_REGISTER_H_



/*Status register*/
#define SREG_REG   *((volatile u8 *)(0x5F))

/*Timers interrupt mask register*/
#define TIMSK_REG  *((volatile u8 *)(0x59))

/*Timers interrupt flags register*/
#define TIFR_REG  *((volatile u8 *)(0x58))

/**Timer0/counter0 control register*/
#define TCCR0_REG   *((volatile u8 *)(0x53))

/**Timer0/counter0 register*/
#define TCNT0_REG   *((volatile u8 *)(0x52))

/**Timer0 output compare register*/
#define OCR0_REG    *((volatile u8 *)(0x5C))





#endif /* TIMER_0_REGISTER_H_ */