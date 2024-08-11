/*
 * T2C_private.h
 *
 *  Created on: Aug 9, 2022
 *      Author: mohammed ramadan
 */

#ifndef MCAL_TWI_T2C_PRIVATE_H_
#define MCAL_TWI_T2C_PRIVATE_H_

/*TWI control register*/
#define TWIE   0   /*TWI interrupt enable*/
#define TWEN   2   /*TWI enable*/
#define TWWC   3   /*TWI write collision flag*/
#define TWSTO  4   /*TWI stop condition bit*/
#define TWSTA  5   /*TWI start condition bit*/
#define TWEA   6   /*TWI enable Ack*/
#define TWINT  7   /*TWI interrupt flag*/

/*TWI statues register*/
#define TWPS0  0   /*TWI prescaller bit 0*/
#define TWPS1  1   /*TWI prescaller bit 1*/

/*TWI address register*/
#define TWGCE  0   /*TWI general call enable*/

#define START_CONDITION_HAS_BEEN_TRANSMITTED          (0x08)
#define REPETED_START_CONDITION_HAS_BEEN_TRANSMITTED  (0x10)
#define SLAVE_ADDRESS_HAS_BEEN_TRANSMITTED            (0x18)
#define DATA_AND_ACK_HAS_BEEN_TRANSMITTED             (0x28)
#define DATA_READ_AND_ACK_HAS_BEEN_TRANSMITTED        (0x58)
#define SLAVE_ADDRESS_HAS_BEEN_RESEVED                (0x60)
#define DATA_AND_ACK_HAS_BEEN_RESEVED                 (0x80)

#endif /* MCAL_TWI_T2C_PRIVATE_H_ */
