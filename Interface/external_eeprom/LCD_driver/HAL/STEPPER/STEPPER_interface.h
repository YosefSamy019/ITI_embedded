/*
 * STEPPER_interface.h
 *
 * Created: 26/08/2024 02:53:42 م
 *  Author: a24e4
 */ 


#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

#define HSTEPPER_WIRES_COUNT 4

typedef struct{
	u8 iterator;
	Pin_t stepperPins[HSTEPPER_WIRES_COUNT];
}HStepper_t;

HStepper_t HStepper_HStepper_t_Create(Pin_t A_arrStepperPins[HSTEPPER_WIRES_COUNT]);

void HStepper_stepForward(HStepper_t* A_ptrHStepper_t);
void HStepper_stepBackward(HStepper_t* A_ptrHStepper_t);


#endif /* STEPPER_INTERFACE_H_ */