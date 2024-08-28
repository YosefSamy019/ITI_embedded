/*
 * UART_register.h
 *
 * Created: 16/08/2024 10:36:21 م
 *  Author: a24e4
 */ 


#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

/*USART data register*/
#define UDR_REG	    *((volatile u8 *)(0x2C))

/*USART control and status register A*/
#define UCSRA_REG   *((volatile u8 *)(0x2B))

/*USART control and status register B*/
#define UCSRB_REG   *((volatile u8 *)(0x2A))

/*USART control and status register C*/
#define UCSRC_REG   *((volatile u8 *)(0x40))

/*USART baud rate register low*/
#define UBRRL_REG   *((volatile u8 *)(0x29))

/*USART baud rate register high*/
#define UBRRH_REG   *((volatile u8 *)(0x40))

/*USART control and status register A*/
#define MPCM_BIT    0
#define U2X_BIT	    1
#define PE_BIT	    2
#define DOR_BIT	    3
#define FE_BIT	    4
#define UDRE_BIT    5
#define TXC_BIT	    6
#define RXC_BIT	    7

/*USART control and status register B*/
#define TXB8_BIT    0
#define RXB8_BIT    1
#define UCSZ2_BIT   2
#define TXEN_BIT    3
#define RXEN_BIT    4
#define UDRIE_BIT   5
#define TXCIE_BIT   6
#define RXCIE_BIT   7

/*USART control and status register C*/
#define UCPOL_BIT	0
#define UCSZ0_BIT	1
#define UCSZ1_BIT	2
#define USBS_BIT	3
#define UPM0_BIT	4
#define UPM1_BIT	5
#define UMSEL_BIT	6
#define URSEL_BIT	7

#endif /* UART_REGISTER_H_ */