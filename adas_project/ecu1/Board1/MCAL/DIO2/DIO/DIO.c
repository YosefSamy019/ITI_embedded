/*
 * DIO.c
 *
 * Created: 20/02/2024 23:08:58
 *  Author: PC
 */ 
#include "registers.h"
#include "../../../LIB2/LIB/STD_TYPES.h"
#include "DIO.h"
void DIO_PinMode(uint8 Pin_No ,uint8 Mode ){
	uint8 port=Pin_No/10;
	uint8 Pin=Pin_No%10;
	switch(port){
		
		case 0:
			///PORTA
		
		if(Mode==OUTPUT)
		{
			SET_BIT(DDRA,Pin);
		}
		else if(Mode==INPUT){
			CLR_BIT(DDRA,Pin);
		}
		
		break;
		case 1:
			///PORTB
		if(Mode==OUTPUT)
		{
			SET_BIT(DDRB,Pin);
		}
		else if(Mode==INPUT){
			CLR_BIT(DDRB,Pin);
		}
		
		break;
		case 2:
		if(Mode==OUTPUT)
		{
			SET_BIT(DDRC,Pin);
		}
		else if(Mode==INPUT){
			CLR_BIT(DDRC,Pin);
		}
		
		break;
		case 3:
		if(Mode==OUTPUT)
		{
			SET_BIT(DDRD,Pin);
		}
		else if(Mode==INPUT){
			CLR_BIT(DDRD,Pin);
		}
		break;
	
}
}

void DIO_digitalWrite(uint8 Pin_No ,uint8 State){
	
	uint8 port=Pin_No/10;
	uint8 Pin=Pin_No%10;
	switch(port){
		
		case 0:
		
		if(State==HIGH)
		{
			SET_BIT(PORTA,Pin);
		}
		else if(State==LOW){
			CLR_BIT(PORTA,Pin);
		}
		
		break;
		case 1:
		if(State==HIGH)
		{
			SET_BIT(PORTB,Pin);
		}
		else if(State==LOW){
			CLR_BIT(PORTB,Pin);
		}
		
		break;
		case 2:
		if(State==HIGH)
		{
			SET_BIT(PORTC,Pin);
		}
		else if(State==LOW){
			CLR_BIT(PORTC,Pin);
		}
		
		break;
		case 3:
		if(State==HIGH)
		{
			SET_BIT(PORTD,Pin);
		}
		else if(State==LOW){
			CLR_BIT(PORTD,Pin);
			
		}
		break;
	}

}

uint8 DIO_digitalRead(uint8 Pin_No ){
	
	uint8 Pin=Pin_No/10;
	uint8 Pin_number=Pin_No%10;
	switch(Pin){
		
		case 0:
		return GET_BIT(PINA,Pin_number);
		break;
		case 1:
		
		return GET_BIT(PINB,Pin_number);
		
		break;
		case 2:
		return GET_BIT(PINC,Pin_number);
		break;
		case 3:
		return GET_BIT(PIND,Pin_number);
		break;
	}

}

