/*
 * LED_interface.h
 *
 * Created: 03/08/2024 01:10:23 م
 *  Author: a24e4
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef enum {
	HLED_ActiveLow,
	HLED_ActiveHigh
}HLedPolarity_t;


typedef struct {
	Pin_t pin;
	HLedPolarity_t polarity;
}HLed_t;


HLed_t HLED_HLed_t_Create(Pin_t A_Pin_t_pin, HLedPolarity_t A_HLedPolarity_t_polarity);
void HLED_void_TurnOn(HLed_t *A_Pin_t_pin);
void HLED_void_TurnOff(HLed_t *A_Pin_t_pin);
void HLED_void_TurnToggle(HLed_t *A_Pin_t_pin);


#endif /* LED_INTERFACE_H_ */