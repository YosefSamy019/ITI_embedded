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

#include "MCAL/ICU/ICU_interface.h"

#include "MCAL/UART/UART_interface.h"

#include "MCAL/SPI/SPI_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_patterns.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_config.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#include "HAL/KEYPAD/KEYPAD_congif.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"

#include "OS/OS_interface.h"

HLed_t l1,l2,l3;

void taskLed1(){
	HLED_void_TurnToggle(&l1);
}
void taskLed2(){
	HLED_void_TurnToggle(&l2);
}
void taskLed3(){
	HLED_void_TurnToggle(&l3);
}

int main(void)
{
	l1 = HLED_HLed_t_Create(PinC0,HLED_ActiveHigh);
	l2 = HLED_HLed_t_Create(PinD0,HLED_ActiveHigh);
	l3 = HLED_HLed_t_Create(PinD7,HLED_ActiveHigh);

	MGI_void_Enable();
	MDIO_voidInit();
	OS_void_init();
	
	OS_void_addTask(taskLed1, 500 , 0);
	OS_void_addTask(taskLed2, 1000 , 1000);
	OS_void_addTask(taskLed3, 1500 , 3000);

	OS_void_enable();
	
	while(1){
		
	}
}