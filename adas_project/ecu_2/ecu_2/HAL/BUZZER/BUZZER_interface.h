/*
 * BUZZER_interface.h
 *
 * Created: 24/08/2024 10:18:33 ص
 *  Author: a24e4
 */ 


#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_



typedef enum {
	HBUZZER_ActiveLow,
	HBUZZER_ActiveHigh
}HBUZZERPolarity_t;


typedef struct {
	Pin_t pin;
	HBUZZERPolarity_t polarity;
}HBUZZER_t;


HBUZZER_t HBUZZER_HBUZZER_t_Create(Pin_t A_Pin_t_pin, HBUZZERPolarity_t A_HBUZZERPolarity_t_polarity);
void HBUZZER_void_TurnOn(HBUZZER_t *A_Pin_t_pin);
void HBUZZER_void_TurnOff(HBUZZER_t *A_Pin_t_pin);
void HBUZZER_void_TurnToggle(HBUZZER_t *A_Pin_t_pin);



#endif /* BUZZER_INTERFACE_H_ */