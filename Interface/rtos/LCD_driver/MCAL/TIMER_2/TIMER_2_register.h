/*
 * TIMER_2_register.h
 *
 * Created: 23/08/2024 09:57:17 ص
 *  Author: a24e4
 */ 


#ifndef TIMER_2_REGISTER_H_
#define TIMER_2_REGISTER_H_



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



/**Timer1/counter1 control registerA*/
#define TCCR1A_REG   *((volatile u8 *)(0x4F))

/**Timer1/counter1 control registerB*/
#define TCCR1B_REG   *((volatile u8 *)(0x4E))

/**Timer1 output compare registerA*/
#define OCR1A_REG    *((volatile u16*)(0x4A))

/**Timer1 output compare registerB*/
#define OCR1B_REG    *((volatile u16*)(0x48))

/**Timer1/counter1 register*/
#define TCNT1_REG    *((volatile u16*)(0x4C))

/**Input capture register*/
#define ICR1_REG     *((volatile u16*)(0x46))



/**Timer2/counter2 control register*/
#define TCCR2_REG   *((volatile u8 *)(0x45))

/**Timer2/counter2 register*/
#define TCNT2_REG   *((volatile u8 *)(0x44))

/**Timer2 output compare register*/
#define OCR2_REG    *((volatile u8 *)(0x43))

/**Asynchronous status register*/
#define ASSR_REG    *((volatile u8 *)(0x42))



#endif /* TIMER_2_REGISTER_H_ */