/*
 * SPI_interface.h
 *
 * Created: 16/08/2024 11:20:26 م
 *  Author: a24e4
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void MSPI_voidInit(void);

#if MSPI_MODE==MSPI_MASTER_MODE
u8 MSPI_u8Transceive(u8 A_u8Data);
#endif

#if MSPI_ENABLE_INTERRUPT==1||MSPI_MODE==MSPI_SLAVE_MODE
void MSPI_voidSetCallback(ptr2voidU32Callback A_ptrCallback);
#endif



#endif /* SPI_INTERFACE_H_ */