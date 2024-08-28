/*
 * UART_prog.c
 *
 * Created: 8/22/2022 6:01:57 PM
 *  Author: maka
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../DIO/DIO_int.h"
#include "UART_register.h"
#include "UART_private.h"
#include "UART_conf.h"
#include "UART_int.h"
#define F_CPU 8000000UL /*frequancy of mc*/
#include <util/delay.h>
#include <stdlib.h>

void MUART_voidInit (void)
{
	u16 UBRR  ;
	
	/*Choose baud rate that will be used by sender and receiver by writing to UBRRL/UBRRH*/
	#if    BAUD_RATE == 2400   || BAUD_RATE == 4800   || BAUD_RATE == 9600   || BAUD_RATE == 14400  || \
	       BAUD_RATE == 19200  || BAUD_RATE == 28800  || BAUD_RATE == 38400  || BAUD_RATE == 57600  || \
		   BAUD_RATE == 76800  || BAUD_RATE == 115200 || BAUD_RATE == 230400 || BAUD_RATE == 250000 || \
		   BAUD_RATE == 500000 || BAUD_RATE == 1000000
	                     UBRR  = (F_CPU/(16*(u32)BAUD_RATE))-1 ;
						 UBRRH = (u8)(UBRR>>8);
						 UBRRL = (u8)(UBRR);
	#else 
	     #error "select correct option of baud rate"
	#endif
	
	/*Enable USART Sender*/
	SET_BIT(UCSRB , TXEN) ;
	
	/*Enable USART Receiver*/
	SET_BIT(UCSRB , RXEN) ;
	
	/*Choose number of data bits to be sent*/
	#if   NUMBER_OF_DATA_BITS == 5 /*URSEL = 1 , UCSZ2 = 0 , UCSZ1 = 0 , UCSZ0 = 0*/
	        UCSRC = (1<<URSEL) ;
	#elif NUMBER_OF_DATA_BITS == 6 /*URSEL = 1 , UCSZ2 = 0 , UCSZ1 = 0 , UCSZ0 = 1*/
	        UCSRC = (1<<URSEL) | (1<<UCSZ0) ;
	#elif NUMBER_OF_DATA_BITS == 7 /*URSEL = 1 , UCSZ2 = 0 , UCSZ1 = 1 , UCSZ0 = 0*/
	        UCSRC = (1<<URSEL) | (1<<UCSZ1) ;
	#elif NUMBER_OF_DATA_BITS == 8 /*URSEL = 1 , UCSZ2 = 0 , UCSZ1 = 1 , UCSZ0 = 1*/
	        UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1) ; 
	#elif NUMBER_OF_DATA_BITS == 9 /*URSEL = 1 , UCSZ2 = 1 , UCSZ1 = 1 , UCSZ0 = 1 , TXB8 = 1 , RXB8 = 1*/
	        SET_BIT (UCSRB , TXB8) ;
			SET_BIT (UCSRB , RXB8) ;
			SET_BIT (UCSRB , UCSZ2) ;
	        UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0) ; 
	#else 
	     #error "select correct option of NUMBER_OF_DATA_BITS "
	#endif
	
	/*wait until all other peripherals be initialized*/
	_delay_ms(300) ;
}

void MUART_voidSendData(u8 A_u8Data)
{
	/*Wait for UDR transmit buffer to be empty*/
	while(READ_BIT(UCSRA,UDRE)==0);
	
	/*Put data to UDR transmit buffer transmit*/
	UDR=A_u8Data ;
}

void MUART_voidSendString(u8* A_pu8Str)
{
	while(*A_pu8Str != '\0')
	{
		MUART_voidSendData(*A_pu8Str);
		A_pu8Str++ ;
	}
	MUART_voidSendData('\n');
}

void MUART_voidSendIntNumber(u32 A_u32Number)
{
	/**array to stored conversion character*/
	s8* L_Ps8String [16] = {0} ;

	/** convert integer to string*/
	ltoa (A_u32Number , (s8*)L_Ps8String , 10) ;

	/**display number after convesion*/
	MUART_voidSendString ((u8*)L_Ps8String) ;
}

u8 MUART_u8ReceiveData(void)
{
	/*Wait for UDR receive buffer to be filled with data*/
	while(READ_BIT(UCSRA,RXC)==0);
	
	/*Receive data from UDR receive buffer*/
	return UDR ;
}

void MUART_voidReceiveString(u8 A_u8Str[])
{
	u32 L_u32Index = 0 ;
	while (1)
	{
		A_u8Str[L_u32Index]=MUART_u8ReceiveData();
		if(A_u8Str[L_u32Index] == '\n' || A_u8Str[L_u32Index]=='\r' )
		{
			A_u8Str[L_u32Index]='\0';
			break;
		}
		L_u32Index ++ ;
	}
}

u32 MUART_voidReciveIntNumber(void) 
{
	u32 L_u32Index = 0 ;
	u32 A_u32Number ;
	u8  A_u8Str [100] ;
	while (1)
	{
		A_u8Str[L_u32Index]=MUART_u8ReceiveData();
		if(A_u8Str[L_u32Index] == '\n' || A_u8Str[L_u32Index]=='\r' )
		{
			A_u8Str[L_u32Index]='\0';
			break;
		}
		L_u32Index ++ ;
	}
	A_u32Number = atol(A_u8Str) ;
	return A_u32Number ;
}
