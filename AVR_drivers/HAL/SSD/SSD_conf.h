/*
 * SSD_conf.h
 *
 *  Created on: May 24, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_SSD_SSD_CONF_H_
#define HAL_SSD_SSD_CONF_H_
/**
*Options of A_u8SsdId 
       *SSD1_ID
	   *SSD2_ID

*Options of A_u8Num 
       *DISPLAY_0
	   *DISPLAY_1 
	   *DISPLAY_2 
	   *DISPLAY_3 
	   *DISPLAY_4 
	   *DISPLAY_5 
	   *DISPLAY_6 
	   *DISPLAY_7 
	   *DISPLAY_8 
	   *DISPLAY_9 
    OR any integer from 0 to 9
	elsewhere at error case the display is zero
	   
*/
/**
*SSD PORT Data  
*Options :
       *DIO_PORTA
	   *DIO_PORTB
	   *DIO_PORTC
	   *DIO_PORTD
*/
#define SSD1_PORT DIO_PORTA
#define SSD2_PORT DIO_PORTA

/**
*SSD PORT Control  
*Options :
       *DIO_PORTA
	   *DIO_PORTB
	   *DIO_PORTC
	   *DIO_PORTD
*/
#define SSD1EN_PORT DIO_PORTD
#define SSD2EN_PORT DIO_PORTD

/**
*SSD PIN Control  
*Options :
       *DIO_PIN0
	   *DIO_PIN1
	   *DIO_PIN2
	   *DIO_PIN3
	   *DIO_PIN4
	   *DIO_PIN5
	   *DIO_PIN6
	   *DIO_PIN7
*/
#define SSD1EN_PIN  DIO_PIN0
#define SSD2EN_PIN  DIO_PIN1

/**
*SSD type  
*Options :
       *COMM_CATHODE
	   *COMM_ANODE
*/
#define SSD_TYPE   COMM_CATHODE

#endif /* HAL_SSD_SSD_CONF_H_ */
