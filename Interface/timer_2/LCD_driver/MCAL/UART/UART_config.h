/*
 * UART_config.h
 *
 * Created: 16/08/2024 10:36:39 م
 *  Author: a24e4
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


//Baud Rate (Tables in datasheet)
/*select baud rate of data 
 ** Options
   *2400
   *4800
   *9600
   *14400
   *19200
   *28800
   *38400
   *57600
   *76800
   *115200
   *230400
   *250000
   *500000
   *1000000
 */
#define MUART_BAUD_RATE 9600

//Double the USART Transmission Speed (0, 1)
#define MUART_DOUBLE_SPEED_ENABLE 0

#define F_CPU 8000000UL

//Parity
#define MUART_PARITY_DISABLED 0
#define MUART_PARITY_RESERVED 1
#define MUART_PARITY_EVEN 2
#define MUART_PARITY_ODD  3
#define MUART_PARITY_SELECT MUART_PARITY_ODD

//Stop bits
#define MUART_1_STOP_BIT  0
#define MUART_2_STOP_BITS 1
#define MUART_STOP_BITS_SELECT MUART_1_STOP_BIT

//Character Size
#define MUART_CHAR_SIZE_5_BITS 0
#define MUART_CHAR_SIZE_6_BITS 1
#define MUART_CHAR_SIZE_7_BITS 2
#define MUART_CHAR_SIZE_8_BITS 3
#define MUART_CHAR_SIZE_9_BITS 7
#define MUART_CHAR_SIZE_SELECT MUART_CHAR_SIZE_8_BITS

#define MUART_RX_COMPLETE_INTERRUPTS_ENABLE			1


#endif /* UART_CONFIG_H_ */