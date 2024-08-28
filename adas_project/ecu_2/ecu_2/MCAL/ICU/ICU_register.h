/*
 * ICU_register.h
 *
 * Created: 13/08/2024 10:52:52 ص
 *  Author: a24e4
 */ 


#ifndef ICU_REGISTER_H_
#define ICU_REGISTER_H_



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






/*Status register*/
#define SREG_REG   *((volatile u8 *)(0x5F))

/*Timers interrupt mask register*/
#define TIMSK_REG  *((volatile u8 *)(0x59))
/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0


/*Timers interrupt flags register*/
#define TIFR_REG  *((volatile u8 *)(0x58))


/**Timer1/counter1 control registerA*/
#define TCCR1A_REG   *((volatile u8 *)(0x4F))
/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0


/**Timer1/counter1 control registerB*/
#define TCCR1B_REG   *((volatile u8 *)(0x4E))
/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0



/**Timer1 output compare registerA*/
#define OCR1A_REG    *((volatile u16*)(0x4A))

/**Timer1 output compare registerB*/
#define OCR1B_REG    *((volatile u16*)(0x48))

/**Timer1/counter1 register*/
#define TCNT1_REG    *((volatile u16*)(0x4C))

/**Input capture register*/
#define ICR1_REG     *((volatile u16*)(0x46))





#endif /* ICU_REGISTER_H_ */