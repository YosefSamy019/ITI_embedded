/*
 * T2C_prog.c
 *
 *  Created on: Aug 9, 2022
 *      Author: mohammed ramadan
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "I2C_int.h"
#include "I2C_register.h"
#include "I2C_private.h"
#include "I2C_conf.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <math.h>

void MTWI_voidMasterInt (u32 A_u32Scl)
{
	#if   PRESCALAR == 1
	      TWSR = 0 ;  /*TWPS0 = 0 , TWPS1 = 0*/
          #define POWER_VAL  0
	#elif PRESCALAR == 4
	      TWSR = 1 ;  /*TWPS0 = 0 , TWPS1 = 1*/
          #define POWER_VAL  1
	#elif PRESCALAR == 16
       	  TWSR = 2 ;  /*TWPS0 = 1 , TWPS1 = 0*/
          #define POWER_VAL  3
	#elif PRESCALAR == 64
	      TWSR = 3 ;  /*TWPS0 = 1 , TWPS1 = 1*/
          #define POWER_VAL  3
	#else
		#error "select correct options of PRESCALAR"
	#endif
	TWBR= (u8) (((F_CPU/A_u32Scl)-16) / (2*pow ((f64)4.0,POWER_VAL)));
}

void MTWI_voidMasterSendStartCondition (void)
{
	/*wait to finish initializing and ending last operation*/
	_delay_ms (300) ;
	/*set enable bit*/
	/*set enable start condition*/
	/*set interrupt enable*/
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	/*wait to finish */
	while(READ_BIT(TWCR,TWINT)==0);
	/*start condition has been transmitted */
	while ((TWSR & 0XF8) != START_CONDITION_HAS_BEEN_TRANSMITTED);
}

void MTWI_voidMasterSendRepetedStartCondition (void)
{
	/*wait to finish initializing and ending last operation*/
	_delay_ms (300) ;
	/*set enable bit*/
	/*set enable start condition*/
	/*set interrupt enable*/
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	/*wait to finish */
	while(READ_BIT(TWCR,TWINT)==0);
	/*start condition has been transmitted */
	while ((TWSR & 0XF8) != REPETED_START_CONDITION_HAS_BEEN_TRANSMITTED);
}

void MTWI_voidMasterSendAddress (u8 A_u8Address)
{
	/*store address in data register*/
	TWDR=A_u8Address;
	/*set enable bit*/
	/*set interrupt enable*/
	TWCR=(1<<TWINT)|(1<<TWEN);
	/* wait to finish */
	while(READ_BIT(TWCR,TWINT)==0);
	/* SLA+write has been transmitted and ACK has been received */
	while ((TWSR & 0XF8) != SLAVE_ADDRESS_HAS_BEEN_TRANSMITTED);
}

void MTWI_voidMasterSendAddressToRead (u8 A_u8Address)
{
	/*store address in data register*/
	TWDR=A_u8Address;
	/*set enable bit*/
	/*set interrupt enable*/
	TWCR=(1<<TWINT)|(1<<TWEN);
	/* wait to finish */
	while(READ_BIT(TWCR,TWINT)==0);
	/* SLA+write has been transmitted and ACK has been received */
	while ((TWSR & 0XF8) != SLAVE_ADDRESS_AND_READ_HAS_BEEN_TRANSMITTED);
}
void MTWI_voidMasterSendData (u8 A_u8Data)
{
	/*store data in data register*/
	TWDR=A_u8Data;
	/*set enable bit*/
	/*set interrupt enable*/
	TWCR=(1<<TWINT)|(1<<TWEN);
	/* wait to finish */
	while(READ_BIT(TWCR,TWINT)==0);
	/* data has been transmitted and ACK has been received */
	while ((TWSR & 0XF8) != DATA_AND_ACK_HAS_BEEN_TRANSMITTED);
}

u8 MTWI_voidMasterReadData (void)
{
	/*set enable bit*/
	/*set interrupt enable*/
	TWCR=(1<<TWINT)|(1<<TWEN);
	/* wait to finish */
	while(READ_BIT(TWCR,TWINT)==0);
	/* data has been transmitted and ACK has been received */
	while ((TWSR & 0XF8) != DATA_READ_AND_ACK_HAS_BEEN_TRANSMITTED);
	return TWDR ;
}

u8 MTWI_voidMasterReadDataWithNACK (void)
{
	/*set enable bit*/
	/*set interrupt enable*/
	TWCR=(1<<TWINT)|(1<<TWEN);
	/* wait to finish */
	while(READ_BIT(TWCR,TWINT)==0);
	/* data has been transmitted and ACK has been received */
	while ((TWSR & 0XF8) != DATA_READ_AND_NACK_HAS_BEEN_TRANSMITTED);
	return TWDR ;
}

void MTWI_voidMasterSendStopCondition (void)
{
	/*set enable bit*/
	/*set enable stop condition*/
	/*set interrupt enable*/
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void MTWI_voidSlaveSetAddress (u8 A_u8Address)
{
	/*store address in address register*/
	TWAR=A_u8Address;
}

u8 MTWI_voidSlaveReadData (void)
{
	/*set enable bit*/
	/*set enable Ack*/
	/*set interrupt enable*/
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	/*wait to finish*/
	while(READ_BIT(TWCR,TWINT)==0);
	/* own SLA+W has been received and ACK has been returned */
	while ((TWSR & 0XF8) != SLAVE_ADDRESS_HAS_BEEN_RESEVED);
    /*set enable bit*/
	/*set enable Ack*/
	/*set interrupt enable*/
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	/*wait to finish*/
	while(READ_BIT(TWCR,TWINT)==0);
	/*previously addressed with own SLA+W : data has been received : ACK has been returned*/
	while ((TWSR & 0XF8) != DATA_AND_ACK_HAS_BEEN_RESEVED);
	/*return data*/
	return TWDR ;
}
