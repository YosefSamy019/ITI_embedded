/*
 * LCD_driver.c
 *
 * Created: 04/08/2024 08:24:43 ص
 * Author : a24e4
 */ 
#include <avr/io.h>

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DELAY/DELAY_interface.h"

#include "MCAL/GI/GI_interface.h"

#include "MCAL/EXT_INT/EXT_INT_interface.h"

#include "MCAL/ADC/ADC_interface.h"

#include "MCAL/TIMER_0/TIMER_0_interface.h"

#include "MCAL/ICU/ICU_interface.h"


#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_patterns.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_config.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#include "HAL/KEYPAD/KEYPAD_congif.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"


void WE(){
		
		//2 s
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);

		//enable
		SET_BIT(WDTCR,3);
		
}

void WD(){
	u8 x1 = WDTCR;
	u8 x2 = WDTCR;
	SET_BIT(x1,4);
	SET_BIT(x1,3);
	
	SET_BIT(x2,4);
	CLR_BIT(x2,3);
		
	WDTCR = x1;
	WDTCR = x2;
}


int main(void)
{
	MDIO_voidInit();
	
	HLed_t l = HLED_HLed_t_Create(PinB0,HLED_ActiveHigh);
	HLED_void_TurnOn(&l);
	MDELAY_void_milli(500);
	HLED_void_TurnOff(&l);

	WE();


	while(1){
			WD();
	}
}