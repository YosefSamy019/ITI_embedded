/*
 * SPI_prog.c
 *
 *  Created on: Aug 2, 2022
 *      Author: mohammed ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "SPI_int.h"
#include "SPI_register.h"
#include "SPI_private.h"
#include "SPI_conf.h"

#define F_CPU 8000000UL /*frequancy of mc*/
#include <util/delay.h>

void MSPI_voidInit(void)
{
	#if    SPI_MODE == SPI_MASTER
	          /*Set SS as output pins for master*/
	          MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN4,DIO_HIGH);
			  /*Set MOSI as output pins for master*/
	          MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN5,DIO_HIGH);
			  /*Set SCK  as output pins for master*/
	          MDIO_voidSetPinDir(DIO_PORTB,DIO_PIN7,DIO_HIGH);
			  /*Enable Master mode*/
	          SET_BIT(SPCR,MSTR);
			  /*Set clock to master */
			  #if    SPI_CLOCK_RATE == PRESCALLER_4 /*fosc/4*/
                       	CLR_BIT(SPCR,SPR0);
                       	CLR_BIT(SPCR,SPR1);
                       	CLR_BIT(SPSR,SPI2X);
			  #elif  SPI_CLOCK_RATE == PRESCALLER_16 /*fosc/16*/
			           	SET_BIT(SPCR,SPR0);
                       	CLR_BIT(SPCR,SPR1);
                       	CLR_BIT(SPSR,SPI2X);
			  #elif  SPI_CLOCK_RATE == PRESCALLER_64 /*fosc/64*/
			           	CLR_BIT(SPCR,SPR0);
                       	SET_BIT(SPCR,SPR1);
                       	CLR_BIT(SPSR,SPI2X);
			  #elif  SPI_CLOCK_RATE == PRESCALLER_128 /*fosc/128*/
			           	SET_BIT(SPCR,SPR0);
                       	SET_BIT(SPCR,SPR1);
                       	CLR_BIT(SPSR,SPI2X);
			  #elif  SPI_CLOCK_RATE == PRESCALLER_2 /*fosc/2*/
         	            CLR_BIT(SPCR,SPR0);
                       	CLR_BIT(SPCR,SPR1);
                       	SET_BIT(SPSR,SPI2X);			  
			  #elif  SPI_CLOCK_RATE == PRESCALLER_8 /*fosc/8*/
			           	SET_BIT(SPCR,SPR0);
                       	CLR_BIT(SPCR,SPR1);
                       	SET_BIT(SPSR,SPI2X);
			  #elif  SPI_CLOCK_RATE == PRESCALLER_32 /*fosc/32*/
			           	CLR_BIT(SPCR,SPR0);
                       	SET_BIT(SPCR,SPR1);
                       	SET_BIT(SPSR,SPI2X);
			  #else 
				  #error "select correct option of SPI_CLOCK_RATE"
			  #endif
			  /*Enable SPI*/
			  SET_BIT(SPCR,SPE);
			  /*set SS to high*/
	          MDIO_voidSetPinVal(DIO_PORTB,DIO_PIN4);
			  /*wait until other peripherals be initialized */
			  _delay_ms(300) ;
	#elif  SPI_MODE == SPI_SLAVE
	          /*Enable SPI*/
	          SET_BIT(SPCR,SPE);
			  /*Set MISO as output*/
	          MDIO_voidSetPinDir(DIO_PORTB , DIO_PIN6 , DIO_HIGH);  
	#else 
		#error "select correct option of SPI_MODE"
	#endif
}

void MSPI_voidMasterTransmitChar(u8 A_u8Data)
{
	
	/*Clear SS to send data to slave*/
	MDIO_voidClrPinVal(DIO_PORTB,DIO_PIN4);
	/*Put data on SPDR*/
	SPDR=A_u8Data;
	/*Wait until data is received in SPI register*/
	while(READ_BIT(SPSR,SPIF)==0);
}

void MSPI_voidMasterTransmitString(u8* A_pu8Str)
{
	while(*A_pu8Str != '\0')
	{
		MSPI_voidMasterTransmitChar(*A_pu8Str);
		A_pu8Str++ ;
	}
	MSPI_voidMasterTransmitChar('\n');
}

u8 MSPI_SlaveReceivechar(void)
{
	/*Put dummy data on SPDR*/
	/*Wait until data is received in SPI register*/
	while(READ_BIT(SPSR,SPIF)==0);
	/*read the received data*/
	return SPDR ;
}

void MSPI_voidReceiveString(u8 A_u8Str[])
{
	u32 L_u32Index = 0 ;
	while (1)
	{
		A_u8Str[L_u32Index]=MSPI_SlaveReceivechar();
		if(A_u8Str[L_u32Index] == '\n' || A_u8Str[L_u32Index]=='\r' )
		{
			A_u8Str[L_u32Index]='\0';
			break;
		}
		L_u32Index ++ ;
	}
}

