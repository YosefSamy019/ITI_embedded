/*
 * BUZZER_program.c
 *
 * Created: 24/08/2024 10:18:23 ص
 *  Author: a24e4
 */ 
 
 #include "../../LIB/STD_TYPES.h"
 #include "../../LIB/BIT_MATH.h"

 #include "../../MCAL/DIO/DIO_interface.h"

 #include "BUZZER_config.h"
 #include "BUZZER_interface.h"
 #include "BUZZER_private.h"

 HBUZZER_t HBUZZER_HBUZZER_t_Create(Pin_t A_Pin_t_pin, HBUZZERPolarity_t A_HBUZZERPolarity_t_polarity){
	 HBUZZER_t L_BUZZER ;
	 
	 L_BUZZER.pin = A_Pin_t_pin;
	 L_BUZZER.polarity = A_HBUZZERPolarity_t_polarity;
	 
	 MDIO_voidSetPinDir(A_Pin_t_pin,OUTPUT);
	 
	 return L_BUZZER;
 }

 void HBUZZER_void_TurnOn(HBUZZER_t *A_Pin_t_pin){
	 switch(A_Pin_t_pin->polarity){
		 case HBUZZER_ActiveHigh:
		 MDIO_voidSetPinVal(A_Pin_t_pin->pin,HIGH); break;
		 case HBUZZER_ActiveLow:
		 MDIO_voidSetPinVal(A_Pin_t_pin->pin,LOW); break;
	 }
 }

 
 void HBUZZER_void_TurnOff(HBUZZER_t *A_Pin_t_pin){
	 switch(A_Pin_t_pin->polarity){
		 case HBUZZER_ActiveHigh:
		 MDIO_voidSetPinVal(A_Pin_t_pin->pin,LOW); break;
		 case HBUZZER_ActiveLow:
		 MDIO_voidSetPinVal(A_Pin_t_pin->pin,HIGH); break;
	 }
 }
 
 void HBUZZER_void_TurnToggle(HBUZZER_t *A_Pin_t_pin){
	 MDIO_voidTogPinVal(A_Pin_t_pin->pin);
 }