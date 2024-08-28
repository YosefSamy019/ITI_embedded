/*
 * DCMotor_conf.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */
 
#ifndef HAL_DC_MOTOR_DCMOTOR_CONF_H_
#define HAL_DC_MOTOR_DCMOTOR_CONF_H_

/*
 **Connection of DC Motor
 *Options of PORT_DC_T1
        *DIO_PORTA
        *DIO_PORTB
        *DIO_PORTC
        *DIO_PORTD
		
 *Options of PORT_DC_T2
        *DIO_PORTA
        *DIO_PORTB
        *DIO_PORTC
        *DIO_PORTD
		
 *Options of PIN_DC_T1
        *DIO_PIN0
        *DIO_PIN1
        *DIO_PIN2
        *DIO_PIN3
        *DIO_PIN4
        *DIO_PIN5
        *DIO_PIN6
        *DIO_PIN7
		
  *Options of PIN_DC_T2
        *DIO_PIN0
        *DIO_PIN1
        *DIO_PIN2
        *DIO_PIN3
        *DIO_PIN4
        *DIO_PIN5
        *DIO_PIN6
        *DIO_PIN7
 */


#define PORT_DC_T1   DIO_PORTA
#define PIN_DC_T1    DIO_PIN0
#define PORT_DC_T2   DIO_PORTA
#define PIN_DC_T2    DIO_PIN1

#endif  /*HAL_DC_MOTOR_DCMOTOR_CONF_H_*/