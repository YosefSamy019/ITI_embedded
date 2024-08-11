/*
 * BUTTON_program.c
 *
 * Created: 03/08/2024 01:29:47 م
 *  Author: a24e4
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "BUTTON_config.h"
#include "BUTTON_interface.h"
#include "BUTTON_private.h"

HBUTTON_t HBUTTON_HBUTTON_t_Create(Pin_t pin,HBUTTON_type_t type){
	HBUTTON_t button;
	
	button.pin = pin;
	button.type = type;
	
	switch(type){
		case HBUTTON_inputExternalPullUp:
		case HBUTTON_inputExternalPullDown: 
			MDIO_voidSetPinDir(pin,INPUT); break;
		case HBUTTON_inputInternalPullUp: 
			MDIO_voidSetPinDir(pin,INPUT_PULL_UP); break;
	}
	
	return button;
}

HBUTTON_state_t HBUTTON_HBUTTON_state_t_getButtonState(HBUTTON_t* A_HBUTTON_t_Button){
	u8 pinVal = MDIO_u8GetPinVal(A_HBUTTON_t_Button->pin);
	HBUTTON_state_t state;
	
	switch(A_HBUTTON_t_Button->type){
		case HBUTTON_inputExternalPullDown:
			switch(pinVal){
				case HIGH: state= HBUTTON_pressed; break;
				case LOW: state= HBUTTON_free; break;
			}
			
		 break;
		 
		case HBUTTON_inputInternalPullUp:
		case HBUTTON_inputExternalPullUp: 
			switch(pinVal){
				case LOW: state= HBUTTON_pressed; break;
				case HIGH: state= HBUTTON_free; break;
			}		
		 break;
	}
	
	return state;
}