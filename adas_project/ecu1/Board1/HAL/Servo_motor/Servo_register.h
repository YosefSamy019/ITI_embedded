/*
 * Servo_register.h
 *
 * Created: 8/1/2022 
 *  Author: maka
 */ 


#ifndef HAL_SERVO_SERVO_REGISTER_H_
#define HAL_SERVO_SERVO_REGISTER_H_

/*timers interrupt mask register*/
#define TIMSK  *((volatile u8 *)(0x59))

/*timers interrupt flags register*/
#define TIFR  *((volatile u8 *)(0x58))

        /****************************************************************/
        /**                        TIMER1                              **/
        /****************************************************************/

/**Timer1/counter1 control registerA*/		
#define TCCR1A   *((volatile u8 *)(0x4F))

/**Timer1/counter1 control registerB*/		
#define TCCR1B   *((volatile u8 *)(0x4E))

/**Timer1 output compare registerA*/		
#define OCR1A    *((volatile u16*)(0x4A))

/**Timer1 output compare registerB*/		
#define OCR1B    *((volatile u16*)(0x48))

/**Timer1/counter1 register*/		
#define TCNT1    *((volatile u16*)(0x4C))

/**Input capture register*/		
#define ICR1     *((volatile u16*)(0x46))


#endif /* HAL_SERVO_SERVO_REGISTER_H_ */