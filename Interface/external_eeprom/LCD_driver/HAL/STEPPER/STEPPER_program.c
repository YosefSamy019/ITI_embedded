/*
 * STEPPER_program.c
 *
 * Created: 26/08/2024 02:53:34 م
 *  Author: a24e4
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DELAY/DELAY_interface.h"

#include "STEPPER_config.h"
#include "STEPPER_interface.h"
#include "STEPPER_private.h"

HStepper_t HStepper_HStepper_t_Create(Pin_t A_arrStepperPins[HSTEPPER_WIRES_COUNT]){
	HStepper_t L_HStepper_t;
	u8 L_u8Iterator;
	
	L_HStepper_t.iterator = HSTEPPER_WIRES_COUNT - 1;
	
	for(L_u8Iterator = 0;L_u8Iterator < HSTEPPER_WIRES_COUNT;L_u8Iterator++){
		L_HStepper_t.stepperPins[L_u8Iterator] = A_arrStepperPins[L_u8Iterator];
		MDIO_voidSetPinDir(A_arrStepperPins[L_u8Iterator],OUTPUT);
	}
	
	return L_HStepper_t;
}

void HStepper_stepForward(HStepper_t* A_ptrHStepper_t){
	MDIO_voidSetPinVal(A_ptrHStepper_t->stepperPins[A_ptrHStepper_t->iterator],LOW);
	
	A_ptrHStepper_t->iterator = (A_ptrHStepper_t->iterator + 1) % HSTEPPER_WIRES_COUNT;
	
	MDIO_voidSetPinVal(A_ptrHStepper_t->stepperPins[A_ptrHStepper_t->iterator],HIGH);
}

void HStepper_stepBackward(HStepper_t* A_ptrHStepper_t){
	MDIO_voidSetPinVal(A_ptrHStepper_t->stepperPins[A_ptrHStepper_t->iterator],LOW);
	
	if(A_ptrHStepper_t->iterator == 0){
		A_ptrHStepper_t->iterator = HSTEPPER_WIRES_COUNT - 1;
	}else{
		A_ptrHStepper_t->iterator--;
	}
	
	MDIO_voidSetPinVal(A_ptrHStepper_t->stepperPins[A_ptrHStepper_t->iterator],HIGH);
}
