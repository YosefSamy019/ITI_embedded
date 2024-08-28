/*
 * LCD_driver.c
 *
 * Created: 04/08/2024 08:24:43 ص
 * Author : a24e4
 */ 

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DELAY/DELAY_interface.h"

#include "MCAL/GI/GI_interface.h"

#include "MCAL/EXT_INT/EXT_INT_interface.h"

#include "MCAL/ADC/ADC_interface.h"

#include "MCAL/TIMER_0/TIMER_0_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_patterns.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_config.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#include "HAL/KEYPAD/KEYPAD_congif.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"


//angle -90 -> 90
void Servo(Pin_t pin,u8 angle){
	u32 highDelay=0,lowDealy=0;
		
	angle = angle +  90;
	angle = angle % 181;
	
	highDelay = (((angle)/180.0) + 1.0)  * 1000;
	lowDealy = 20*1000 - highDelay;
	
	MDIO_voidSetPinVal(pin,HIGH);
	MDELAY_void_micro(highDelay);
	MDIO_voidSetPinVal(pin,LOW);
	MDELAY_void_micro(lowDealy);
}

int main(void)
{
	MDIO_voidInit();
	MADC_voidInit();
	
	MDIO_voidSetPinDir(PinB0,OUTPUT);
		
		
	while(1){
		u32 read  = MADC_u32ReadVoltage(MADC_SINGLE_CHANNEL_0); // 0 -> 1023
	    s8 angle = (read / 1023.0 * 180.0 ) - 90.0;
		
		Servo(PinB0,angle);
		
	}
}