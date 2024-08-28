/*
 * SPI_int.h
 *
 *  Created on: Aug 2, 2022
 *      Author: mohammed ramadan
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

/*
	Function Name        : MSPI_voidInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize SPI as a slave or master 
*/
void MSPI_voidInit(void);

/*
	Function Name        : MSPI_voidMasterTransmitchar
	Function Returns     : void
	Function Arguments   : u8 A_u8Data
	Function Description : send data from master to slave
*/
void MSPI_voidMasterTransmitChar (u8 A_u8Data) ;

/*
	Function Name        : MSPI_voidMasterTransmitString
	Function Returns     : void
	Function Arguments   : u8* A_pu8Str
	Function Description : send string from master to slave
*/
void MSPI_voidMasterTransmitString (u8* A_pu8Str) ;

/*
	Function Name        : MSPI_SlaveReceivechar
	Function Returns     : u8
	Function Arguments   : void
	Function Description : recive data from slave to master
*/
u8 MSPI_SlaveReceivechar(void) ;

/*
	Function Name        : MSPI_voidReceiveString
	Function Returns     : void
	Function Arguments   : u8 A_u8Str[]
	Function Description : recive string from slave to master
*/
void MSPI_voidReceiveString(u8 A_u8Str[]) ;

#endif /* MCAL_SPI_SPI_INT_H_ */