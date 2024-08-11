/*
 * DIO_prog.c
 *
 * Created: 03/08/2024 12:05:05 م
 *  Author: a24e4
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_reg.h"

void MDIO_voidInit(void){
	#if MDIO_ENABLE_PULL_UP_CIRCUIT == 0
		SET_BIT(SFIOR_REG,PUD_BIT);
	#else
		CLR_BIT(SFIOR_REG,PUD_BIT);
	#endif
}


void MDIO_voidSetPinDir(Pin_t A_Pin_tPin, u8 A_u8Dir){
	u8 L_portNum = A_Pin_tPin & 0xF0;
	u8 L_pinNum = A_Pin_tPin & 0x0F;
	
	volatile u8 *L_dirReg,*L_valReg;
	
	switch (L_portNum)
	{
		case MDIO_PORT_A_NUM:
				L_dirReg = &DDRA_REG; L_valReg = &PORTA_REG;
			break;
		case MDIO_PORT_B_NUM:
						L_dirReg = &DDRB_REG; L_valReg = &PORTB_REG;

			break;		
		case MDIO_PORT_C_NUM:
						L_dirReg = &DDRC_REG; L_valReg = &PORTC_REG;

			break;		
		case MDIO_PORT_D_NUM:
						L_dirReg = &DDRD_REG; L_valReg = &PORTD_REG;

			break;
		}
		
		switch(A_u8Dir){
			case INPUT: 
				CLR_BIT(*L_dirReg,L_pinNum) ;
				break;
			case OUTPUT: 
				SET_BIT(*L_dirReg,L_pinNum) ;
				break;
			case INPUT_PULL_UP: 
				CLR_BIT(*L_dirReg,L_pinNum);
				SET_BIT(*L_valReg,L_pinNum);
				break;
		}
	
}
void MDIO_voidSetPinVal(Pin_t A_Pin_tPin, u8 A_u8Val){
	u8 L_portNum = A_Pin_tPin & 0xF0;
	u8 L_pinNum = A_Pin_tPin & 0x0F;
	
	volatile  u8 *L_dirReg,*L_valReg;
	
	switch (L_portNum)
	{
		case MDIO_PORT_A_NUM:
		L_dirReg = &DDRA_REG; L_valReg = &PORTA_REG;
		break;
		case MDIO_PORT_B_NUM:
		L_dirReg = &DDRB_REG; L_valReg = &PORTB_REG;

		break;
		case MDIO_PORT_C_NUM:
		L_dirReg = &DDRC_REG; L_valReg = &PORTC_REG;

		break;
		case MDIO_PORT_D_NUM:
		L_dirReg = &DDRD_REG; L_valReg = &PORTD_REG;

		break;
	}
	
	switch(A_u8Val){
		case LOW:
		CLR_BIT(*L_valReg,L_pinNum) ;
		break;
		case HIGH:
		SET_BIT(*L_valReg,L_pinNum) ;
		break;
		
	}
}

u8	 MDIO_u8GetPinVal(Pin_t A_Pin_tPin){
	u8 L_portNum = A_Pin_tPin & 0xF0;
	u8 L_pinNum = A_Pin_tPin & 0x0F;
	u8 L_returnVal = 0;
	
	volatile u8  *L_dirReg = NULL,*L_pinReg =NULL;
	
	switch (L_portNum)
	{
		case MDIO_PORT_A_NUM:
		L_dirReg = &DDRA_REG; L_pinReg = &PINA_REG;
		break;
		case MDIO_PORT_B_NUM:
		L_dirReg = &DDRB_REG; L_pinReg = &PINB_REG;

		break;
		case MDIO_PORT_C_NUM:
		L_dirReg = &DDRC_REG; L_pinReg = &PINC_REG;

		break;
		case MDIO_PORT_D_NUM:
		L_dirReg = &DDRD_REG; L_pinReg = &PIND_REG;

		break;
	}
	

	
	switch(GET_BIT(*L_pinReg,L_pinNum)){
		case 0:
			L_returnVal = LOW;
		break;
		case 1:
			L_returnVal = HIGH;
		break;
		
	}
	
	return 	L_returnVal ;
}

void MDIO_voidTogPinVal(Pin_t A_Pin_tPin){
	u8 L_portNum = A_Pin_tPin & 0xF0;
	u8 L_pinNum = A_Pin_tPin & 0x0F;
	
	volatile u8  *L_dirReg = NULL,*L_valReg =NULL;
	
	switch (L_portNum)
	{
		case MDIO_PORT_A_NUM:
		L_dirReg = &DDRA_REG; L_valReg = &PORTA_REG;
		break;
		case MDIO_PORT_B_NUM:
		L_dirReg = &DDRB_REG; L_valReg = &PORTB_REG;

		break;
		case MDIO_PORT_C_NUM:
		L_dirReg = &DDRC_REG; L_valReg = &PORTC_REG;

		break;
		case MDIO_PORT_D_NUM:
		L_dirReg = &DDRD_REG; L_valReg = &PORTD_REG;

		break;
	}
	
	TOG_BIT(*L_valReg,L_pinNum);
}


