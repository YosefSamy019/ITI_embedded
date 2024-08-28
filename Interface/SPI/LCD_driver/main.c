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

void echo(u32 d){
	MUART_voidSendData(d);
}

int main(void)
{
	MGI_void_Enable();
	MDIO_voidInit();
	
	MSPI_voidInit();
	//MSPI_voidSetCallback(echo);

	while(1){
		MSPI_u8Transceive('F');
		MDELAY_void_milli(1000);
	}
}