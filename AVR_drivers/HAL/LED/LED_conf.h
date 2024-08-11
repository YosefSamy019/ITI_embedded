/*
 * LED_conf.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohamed Ramadan
 */

#ifndef HAL_LED_LED_CONF_H
#define HAL_LED_LED_CONF_H
/**
      ** Connections **
	  
 *Options of LEDx_PORT are :
            *DIO_PORTA
			*DIO_PORTB
			*DIO_PORTC
			*DIO_PORTD

 *Options of LEDx_PIN are :
            *DIO_PIN0
			*DIO_PIN1
			*DIO_PIN2
			*DIO_PIN3
			*DIO_PIN4
			*DIO_PIN5
			*DIO_PIN6
			*DIO_PIN7
			
	where x is the ID of led "x = 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8"
*/

/**
 * Options of A_u8LED_ID 
        *LED1_ID 
		*LED2_ID 
		*LED3_ID 
		*LED4_ID 
		*LED5_ID 
		*LED6_ID
		*LED7_ID
		*LED8_ID
*/

/**
 * connection of led 1
*/
#define LED1_PORT    DIO_PORTA 
#define LED1_PIN     DIO_PIN0

/**
 * connection of led 2
*/
#define LED2_PORT    DIO_PORTA 
#define LED2_PIN     DIO_PIN1

/**
 * connection of led 3
*/
#define LED3_PORT    DIO_PORTA 
#define LED3_PIN     DIO_PIN2

/**
 * connection of led 4
*/
#define LED4_PORT    DIO_PORTA 
#define LED4_PIN     DIO_PIN3
 
/**
 * connection of led 5
*/
#define LED5_PORT    DIO_PORTA 
#define LED5_PIN     DIO_PIN4

/**
 * connection of led 6
*/
#define LED6_PORT    DIO_PORTA 
#define LED6_PIN     DIO_PIN5

/**
 * connection of led 7
*/
#define LED7_PORT    DIO_PORTA
#define LED7_PIN     DIO_PIN6

/**
 * connection of led 8
*/
#define LED8_PORT    DIO_PORTA 
#define LED8_PIN     DIO_PIN7 


#endif /* HAL_LED_LED_CONF_H */
