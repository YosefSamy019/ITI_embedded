/*
 * SPI_program.c
 *
 * Created: 16/08/2024 11:20:16 م
 *  Author: a24e4
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"

void MSPI_voidInit(void){
	//SPI enable
	SET_BIT(SPCR_REG,6);
	
	//Data order
	#if MSPI_DATA_ORDER_SELECT == MSPI_DATA_ORDER_MSB_IS_FIRST
		CLR_BIT(SPCR_REG,5);
	#elif MSPI_DATA_ORDER_SELECT == MSPI_DATA_ORDER_LSB_IS_FIRST
		SET_BIT(SPCR_REG,5);
	#else
		#error "SPI ERROR, Data order not defined"
	#endif
	
	//Clock Polarity
	SPCR_REG = (SPCR_REG&(0b11110111)) | (MSPI_CLOCK_POLARITY_SELECT<<3);
	
	//Clock Phase
	SPCR_REG = (SPCR_REG&(0b11111011)) | (MSPI_CLOCK_PHASE_SELECT<<2);
	
	//SPI mode
	#if MSPI_MODE == MSPI_SLAVE_MODE
		//pins directions
		MDIO_voidSetPinDir(MSPI_MOSI_PIN,INPUT);
		MDIO_voidSetPinDir(MSPI_MISO_PIN,OUTPUT);
		MDIO_voidSetPinDir(MSPI_SS_PIN,INPUT);
		MDIO_voidSetPinDir(MSPI_SCK_PIN,INPUT);
	
		//interrupt enable
		SPCR_REG = (SPCR_REG&0b01111111)|(MSPI_ENABLE_INTERRUPT<<7);
	
		//slave select
		CLR_BIT(SPCR_REG,4);
	
	#elif MSPI_MODE == MSPI_MASTER_MODE
		//Prescaler
		//SPR0, SPR1 bits
		SPCR_REG = (SPCR_REG&0b11111100)|(SPI_PRESCALER_SELECT&0b00000011);
		//SPI2X: Double SPI Speed Bit
		SPSR_REG = (SPSR_REG&0b11111110)|(SPI_PRESCALER_SELECT>>2);
	
		//pins directions
		MDIO_voidSetPinDir(MSPI_MOSI_PIN,OUTPUT);
		MDIO_voidSetPinDir(MSPI_MISO_PIN,INPUT);
		MDIO_voidSetPinDir(MSPI_SS_PIN,OUTPUT);
		MDIO_voidSetPinDir(MSPI_SCK_PIN,OUTPUT);

		//unselected the slave (active low)
		MDIO_voidSetPinVal(MSPI_SS_PIN,HIGH);
	
	
		//master select, should be after make the SS output according to datasheet
		SET_BIT(SPCR_REG,4);

	#else
	#error "SPI ERROR, Mode not defined"
	#endif
}

#if MSPI_MODE==MSPI_MASTER_MODE
u8 MSPI_u8Transceive(u8 A_u8Data){
		//select the slave active low
		MDIO_voidSetPinVal(MSPI_SS_PIN,LOW);
		
		SPDR_REG = A_u8Data;
		
		//wait
		while(GET_BIT(SPSR_REG,7)==0);
		
		//unselect the slave active low
		MDIO_voidSetPinVal(MSPI_SS_PIN,HIGH);
		
		return ((u8)SPDR_REG);
}
#endif

#if MSPI_ENABLE_INTERRUPT==1||MSPI_MODE==MSPI_SLAVE_MODE
	static volatile ptr2voidU32Callback G_ptrCallback = NULL;

	void MSPI_voidSetCallback(ptr2voidU32Callback A_ptrCallback){
		G_ptrCallback = A_ptrCallback;
	}
	
	
	void __vector_12(void)__attribute__((signal));
	void __vector_12(void){
		if(G_ptrCallback != NULL){
			G_ptrCallback((u8)SPDR_REG);
		}
	}
		
#endif
