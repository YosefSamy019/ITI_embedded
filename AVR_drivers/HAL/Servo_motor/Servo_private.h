/*
 * Servo_private.h
 *
 * Created: 8/1/2022 
 *  Author: mohammed ramadan
 */ 


#ifndef HAL_SERVO_MOTOR_SERVO_PRIVATE_H_
#define HAL_SERVO_MOTOR_SERVO_PRIVATE_H_

/*frequancy of mc*/
#define CLOK_SYSTEM 8000000UL


/****************************************************************/
/**                        TIMER1                              **/
/****************************************************************/
/**Timer1/counter1 control register (TCCR1A)*/
#define WGM10    0 /*Waveform Generation Mode Bits 0 , 1*/
#define WGM11    1
#define FOC1B    2 /*Fource Output Compare B*/
#define FOC1A    3 /*Fource Output Compare A*/
#define COM1B0   4 /*Compare A Output Mode Bits*/
#define COM1B1   5
#define COM1A0   6 /*Compare B Output Mode Bits*/
#define COM1A1   7

/**Timer1/counter1 control register (TCCR1B)*/
#define CS10     0 /*The thee Clock Select bits select the clock source to be used by the Timer/Counter*/
#define CS11     1
#define CS12     2
#define WGM12    3 /*Waveform Generation Mode Bits 2 , 3*/
#define WGM13    4
#define ICES1    6 /*Input Capture Edge Select*/
#define ICNC1    7 /*Input Capture Noise Canceler*/

/**Timer interrupt mask register (TIMSK)*/
#define TOIE1    2  /*Timer/Counter1 Overflow Interrupt Enable*/
#define OCIE1B   3  /*Timer/Counter1 Output Compare Match A Interrupt Enable*/
#define OCIE1A   4  /*Timer/Counter1 Output Compare Match B Interrupt Enable*/
#define TICIE1   5  /*Timer/Counter1 Input Capture Enable*/

/**Timer interrupt flag register (TIFR)*/
#define TOV1     2  /*Timer/Counter1 Overflow Flag*/
#define OCF1A    3  /*Timer/Counter1 Output Compare Flag*/
#define OCF1B    4  /*Timer/Counter1 Output Compare Flag*/
#define ICF1     5  /*Timer/Counter1 Input Capture Flag*/

/*ENABLE/DISABLE TIMER2*/
#define ENABLE1   5  /*ENABLE TIMER2*/

/*Types of ctc */
#define COMPARE_A    1 /*compare match A*/

/*Top value of TCR1 */
#define TOP_ICR1_VALUE 159999

#endif /* HAL_SERVO_MOTOR_SERVO_PRIVATE_H_ */