/*
 * LED_program.c
 *
 * Created: 03/08/2024 01:10:58 م
 *  Author: a24e4
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"

HLed_t HLED_HLed_t_Create(Pin_t A_Pin_t_pin, HLedPolarity_t A_HLedPolarity_t_polarity){
	HLed_t L_led ;
	
	L_led.pin = A_Pin_t_pin;
	L_led.polarity = A_HLedPolarity_t_polarity;
	
	MDIO_voidSetPinDir(A_Pin_t_pin,OUTPUT);
	
	return L_led;
}

void HLED_void_TurnOn(HLed_t *A_Pin_t_pin){
	switch(A_Pin_t_pin->polarity){
		case HLED_ActiveHigh:
			MDIO_voidSetPinVal(A_Pin_t_pin->pin,HIGH); break;
		case HLED_ActiveLow:
			MDIO_voidSetPinVal(A_Pin_t_pin->pin,LOW); break;	
	}
}

	
void HLED_void_TurnOff(HLed_t *A_Pin_t_pin){
	switch(A_Pin_t_pin->polarity){
		case HLED_ActiveHigh:
		MDIO_voidSetPinVal(A_Pin_t_pin->pin,LOW); break;
		case HLED_ActiveLow:
		MDIO_voidSetPinVal(A_Pin_t_pin->pin,HIGH); break;
	}
}
	
void HLED_void_TurnToggle(HLed_t *A_Pin_t_pin){
			MDIO_voidTogPinVal(A_Pin_t_pin->pin);
}