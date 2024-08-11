/*
 * Dio_Driver.c
 *
 * Created: 03/08/2024 12:01:56 م
 * Author : a24e4
 */ 

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_config.h"
#include "MCAL/DIO/DIO_interface.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#include "HAL/BUTTON/BUTTON_config.h"
#include "HAL/BUTTON/BUTTON_interface.h"

#include "HAL/SEV_SEG/SEV_SEG_config.h"
#include "HAL/SEV_SEG/SEV_SEG_interface.h"

#include <avr/delay.h>

#define SWITCH_PIN PinD0


int main(void)
{
	HBUTTON_t upBtn, downBtn;
	HSEV_SEG_t sevSeg;
	HLed_t led;
	
	u8 num = 4;
	u8 flag =0;
	
	do{
	MDIO_voidInit();
				
	MDIO_voidSetPinDir(SWITCH_PIN,OUTPUT);
	
	upBtn = HBUTTON_HBUTTON_t_Create(PinA0,HBUTTON_inputInternalPullUp);
	downBtn = HBUTTON_HBUTTON_t_Create(PinA4,HBUTTON_inputInternalPullUp);
	
	Pin_t pins[] = {PinC0,PinC1,PinC2,PinC3,PinC4,PinC5,PinC6};
	sevSeg = HSEV_SEG_SEV_SEG_t_Create(HSEV_SEG_commonCathod,pins,PinC7);		
	
	led = HLED_HLed_t_Create(PinB0,HLED_ActiveHigh);
	
	}while(0);
	
	
	
	do 
	{
		if(HBUTTON_HBUTTON_state_t_getButtonState(&upBtn) == HBUTTON_pressed){
			num++;
			if(num>=100){num = 0;}
			HLED_void_TurnOn(&led);
			while(HBUTTON_HBUTTON_state_t_getButtonState(&upBtn) == HBUTTON_pressed);
		}	
		
		if(HBUTTON_HBUTTON_state_t_getButtonState(&downBtn) == HBUTTON_pressed){
			num--;
			if(num == 255) {num = 99;}
			HLED_void_TurnOn(&led);
			while(HBUTTON_HBUTTON_state_t_getButtonState(&downBtn) == HBUTTON_pressed);
		}
		
		HLED_void_TurnOff(&led);
		
		
		switch(flag){
			case 0:
				MDIO_voidSetPinVal(SWITCH_PIN,HIGH);
				HSEV_SEG_void_DisplayDigit(&sevSeg,num%10);
				flag  = 1;
				break;
			case 1:
				MDIO_voidSetPinVal(SWITCH_PIN,LOW);
				HSEV_SEG_void_DisplayDigit(&sevSeg,(num/10)%10);
				flag  = 0;			
				break;
			
		}
		
		_delay_ms(100);
		
	} while (1);
}

