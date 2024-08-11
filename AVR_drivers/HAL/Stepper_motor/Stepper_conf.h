/*
 * Stepper_conf.h
 *
 * Created: 8/1/2022 
 *  Author: mohammed ramadan
 */
 
#ifndef HAL_STEPPER_MOTOR_STEPPER_CONF_H_
#define HAL_STEPPER_MOTOR_STEPPER_CONF_H_

/*Connection Ports of Coils
 **Options 
    *DIO_PORTA
    *DIO_PORTB
    *DIO_PORTC
    *DIO_PORTD
*/
#define STPM_YELLOW_PORT 	 DIO_PORTA
#define STPM_BLUE_PORT 		 DIO_PORTA
#define STPM_PINK_PORT 		 DIO_PORTA
#define STPM_ORANGE_PORT	 DIO_PORTA

/*Connection Pins of Coils
 **Options 
    *DIO_PIN0
    *DIO_PIN1
    *DIO_PIN2
    *DIO_PIN3
    *DIO_PIN4
    *DIO_PIN5
    *DIO_PIN6
    *DIO_PIN7
*/
#define STPM_BLUE_PIN		 DIO_PIN0
#define STPM_PINK_PIN		 DIO_PIN1
#define STPM_YELLOW_PIN		 DIO_PIN2
#define STPM_ORANGE_PIN		 DIO_PIN3

#define ANGLE_OF_ONE_STEP    0.17578125

#define NUMBER_OF_COILS      4

#endif /*HAL_STEPPER_MOTOR_STEPPER_CONF_H_*/