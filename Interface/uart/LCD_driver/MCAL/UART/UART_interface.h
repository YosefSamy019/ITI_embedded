/*
 * UART_interface.h
 *
 * Created: 16/08/2024 10:36:04 م
 *  Author: a24e4
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void MUART_voidInit(void);
void MUART_voidSendData(u32 A_u32Data);
u32  MUART_U32ReceiveData(void);

#if MUART_RX_COMPLETE_INTERRUPTS_ENABLE == 1
	void MUART_voidSetRXCallback(ptr2voidU32Callback A_ptrCallback);
#endif

#endif /* UART_INTERFACE_H_ */