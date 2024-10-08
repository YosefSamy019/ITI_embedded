#define F_CPU 8000000UL

#include <avr/io.h>
#include<avr/delay.h>

typedef unsigned char u8;

const u8 arr[]={
		0b11111100,
		0b01100000,
		0b11011010,
		0b11110010,
		0b01100110,
		0b10110110,
		0b10111110,
		0b11100000,
		0b11111110,
		0b11110110
};

void main(void){
	u8 counter = 0;
	DDRC = 0xff;

	while ( 1 ) {
		PORTC = arr[counter];
		counter = (counter +1)%10;
		_delay_ms(500);
	}
}
