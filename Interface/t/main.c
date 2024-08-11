#define F_CPU 8000000UL

#include <avr/io.h>
#include<avr/delay.h>

#define infinity (;;)

int main(void){
	DDRA = 0xFF;
	PORTA = 0x01;

	for infinity {
		_delay_ms(500);

		PORTA = PORTA << 1;

		if(PORTA==0x00){
			PORTA=0x01;
		}

	}

	return 0;
}
