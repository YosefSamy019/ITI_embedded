/*
 * LCD_driver.c
 *
 * Created: 04/08/2024 08:24:43 ص
 * Author : a24e4
 */ 

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DELAY/DELAY_interface.h"

#include "MCAL/GI/GI_interface.h"

#include "MCAL/EXT_INT/EXT_INT_interface.h"

#include "MCAL/ADC/ADC_interface.h"

#include "MCAL/TIMER_0/TIMER_0_interface.h"

#include "MCAL/TIMER_2/TIMER_2_interface.h"


#include "MCAL/ICU/ICU_interface.h"

#include "MCAL/UART/UART_interface.h"

#include "MCAL/SPI/SPI_interface.h"

#include "MCAL/TWI/TWI_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_patterns.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_config.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#include "HAL/KEYPAD/KEYPAD_congif.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"

HLed_t l;

void echo(u32 d){
	HLED_void_TurnToggle(&l);
}

int main(void)
{
	l = HLED_HLed_t_Create(PinB0,HLED_ActiveHigh);
	
	MGI_void_Enable();
	MDIO_voidInit();
	
	MTIMER_2_voidInit();
	MTIMER_2_voidSetCallback(echo);

	while(1){
		
	}
}