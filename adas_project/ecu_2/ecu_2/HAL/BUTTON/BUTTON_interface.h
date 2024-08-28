/*
 * BUTTON_interface.h
 *
 * Created: 03/08/2024 01:30:00 م
 *  Author: a24e4
 */ 


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

typedef enum {
	HBUTTON_inputExternalPullDown,
	HBUTTON_inputExternalPullUp,
	HBUTTON_inputInternalPullUp
}HBUTTON_type_t;

typedef struct{
	Pin_t pin;
	HBUTTON_type_t type;
	
}HBUTTON_t;

typedef enum {
	HBUTTON_pressed,
	HBUTTON_free
}HBUTTON_state_t;


HBUTTON_t HBUTTON_HBUTTON_t_Create(Pin_t pin,HBUTTON_type_t type);

HBUTTON_state_t HBUTTON_HBUTTON_state_t_getButtonState(HBUTTON_t* A_HBUTTON_t_Button);

#endif /* BUTTON_INTERFACE_H_ */