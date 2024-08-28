/*
 * DELAY_interface.c
 *
 * Created: 2024-01-27 2:33:43 PM
 *  Author: asus
 */ 

#define F_CPU 8000000ul
#include <avr/delay.h>

#include "../../LIB/STD_TYPES.h"

#include "DELAY_interface.h"

void MDELAY_void_milli(u32 A_u32_ms){
	while(A_u32_ms>0){
		if(A_u32_ms >= 1000){
			_delay_ms(1000);
			A_u32_ms -= 1000;
		}
		else if(A_u32_ms >= 100){
			_delay_ms(100);
			A_u32_ms -= 100;
		}else if(A_u32_ms >= 10){
			_delay_ms(10);
			A_u32_ms -= 10;
		}else{
			_delay_ms(1);
			A_u32_ms -= 1;
		}
	}
}

void MDELAY_void_micro(u32 A_u32_us){
	while(A_u32_us>0){
		if(A_u32_us >= 1000){
			_delay_us(1000);
			A_u32_us -= 1000;
		}
		else if(A_u32_us >= 100){
			_delay_us(100);
			A_u32_us -= 100;
		}else if(A_u32_us >= 10){
			_delay_us(10);
			A_u32_us -= 10;
		}else{
			_delay_us(1);
			A_u32_us -= 1;
		}
	}
}