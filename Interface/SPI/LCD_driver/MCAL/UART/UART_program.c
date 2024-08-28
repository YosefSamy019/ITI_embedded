/*
 * UART_program.c
 *
 * Created: 16/08/2024 10:35:54 م
 *  Author: a24e4
 */ 


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_register.h"



void MUART_voidInit(void){
	u16 L_u16ubrr_val=0;
	
	// Double the USART Transmission Speed
	#if MUART_DOUBLE_SPEED_ENABLE==0
		L_u16ubrr_val = F_CPU / (16.0 * MUART_BAUD_RATE) - 1.0;
	#elif MUART_DOUBLE_SPEED_ENABLE==1
		L_u16ubrr_val = F_CPU / (8.0 * MUART_BAUD_RATE) - 1.0;
	#else
		#error "UART ERROR, Double the USART Transmission Speed not defined"
	#endif
	
	// Multi-processor Communication Mode
	CLR_BIT(UCSRA_REG,0);
	
	//Baud rate
	UBRRL_REG = L_u16ubrr_val;
	UBRRH_REG = L_u16ubrr_val>>8;	
	
	//RX Complete Interrupt Enable
	#if MUART_RX_COMPLETE_INTERRUPTS_ENABLE==1
		SET_BIT(UCSRB_REG,7);
	#elif MUART_RX_COMPLETE_INTERRUPTS_ENABLE==0
		CLR_BIT(UCSRB_REG,7);
	#else
		#error "UART ERROR, RX Complete Interrupt Enable not defined"
	#endif	

	
			
	// Double the USART Transmission Speed
	#if MUART_DOUBLE_SPEED_ENABLE==0
		CLR_BIT(UCSRA_REG,1);
	#elif MUART_DOUBLE_SPEED_ENABLE==1
		SET_BIT(UCSRA_REG,1);
	#else
		#error "UART ERROR, Double the USART Transmission Speed not defined"
	#endif	
	
	//Receiver Enable
	SET_BIT(UCSRB_REG,4);
		
	//Transmitter Enable
	SET_BIT(UCSRB_REG,3);
	
	//Because 2 registers share the same address
	u8 ucsrc_val = 0x00;
	
	//Parity
	ucsrc_val = (ucsrc_val)|(MUART_PARITY_SELECT<<4);
	
	//STOP BITS
	ucsrc_val = (ucsrc_val) | (MUART_STOP_BITS_SELECT<<3);

	//Character size
	ucsrc_val = (ucsrc_val) | ((MUART_CHAR_SIZE_SELECT&3)<<1);
	UCSRB_REG = (UCSRB_REG&0b11111011) | ((MUART_CHAR_SIZE_SELECT&4)<<2);
	
	UCSRC_REG |= ucsrc_val;
	
	//Make Pins output
	MDIO_voidSetPinDir(MUART_TX_PIN,OUTPUT);
	MDIO_voidSetPinDir(MUART_RX_PIN,INPUT);
}

void MUART_voidSendData(u32 A_u32Data){
	
		// USART Data Register Empty
		while(GET_BIT(UCSRA_REG,5)==0);

		//write ninth bit then write the low 8 bits
		#if MUART_CHAR_SIZE_SELECT==MUART_CHAR_SIZE_9_BITS
			UCSRB_REG = (UCSRB_REG & 0x11111110) | GET_BIT(A_u32Data,8);
		#endif
		UDR_REG = A_u32Data&0xff;
		
		//USART Transmit Complete
		while(GET_BIT(UCSRA_REG,6)==0);
}

u32  MUART_U32ReceiveData(void){
		u32 L_u32Data = 0;
		
		// USART Receive Complete
		while(GET_BIT(UCSRA_REG,7)==0);

		//write ninth bit then write the low 8 bits
		#if MUART_CHAR_SIZE_SELECT== MUART_CHAR_SIZE_9_BITS
		L_u32Data = GET_BIT(UCSRB_REG,1) << 8;
		#endif
		L_u32Data = L_u32Data | UDR_REG;
		
		return L_u32Data;
}

#if MUART_RX_COMPLETE_INTERRUPTS_ENABLE == 1
	static volatile ptr2voidU32Callback G_ptrCallback = NULL;
	void MUART_voidSetRXCallback(ptr2voidU32Callback A_ptrCallback){
		G_ptrCallback = A_ptrCallback;
	}
	
	void __vector_13(void)__attribute__((signal));
	void __vector_13(void){
		if(G_ptrCallback != NULL){
			u32 L_u32Data = 0;
			
			//write ninth bit then write the low 8 bits
			#if MUART_CHAR_SIZE_SELECT==MUART_CHAR_SIZE_9_BITS
			L_u32Data = GET_BIT(UCSRB_REG,1) << 8;
			#endif
			L_u32Data = L_u32Data | UDR_REG;
			
			G_ptrCallback(L_u32Data);
		}
	}
	
#endif