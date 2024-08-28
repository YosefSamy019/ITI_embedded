/*
 * EEPROM_prog.c
 *
 * Created: 8/30/2022 2:27:02 PM
 *  Author: maka
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/I2C/I2C_int.h"
#include "EEPROM_init.h"

void HEEPROM_voidInit (u32 A_u32Scl)
{
	MTWI_voidMasterInt(A_u32Scl) ;
}

void HEEPROM_voidWriteByte (u16 A_u16Address , u8 A_u8Data)
{
	u8 L_u8WordAddress ;
	L_u8WordAddress = ((0b10100000) | ((A_u16Address>>8)<<1)) ;
	MTWI_voidMasterSendStartCondition() ;
	MTWI_voidMasterSendAddress(L_u8WordAddress) ;
	MTWI_voidMasterSendData((u8)A_u16Address) ;
	MTWI_voidMasterSendData(A_u8Data) ;
	MTWI_voidMasterSendStopCondition() ;
}

u8 HEEPROM_u8ReadByte (u16 A_u16Address)
{
	u8 L_u8WordAddress ;
	u8 L_u8ReturnByte ;
	L_u8WordAddress = ((0b10100000) | ((A_u16Address>>8)<<1)) ;
	MTWI_voidMasterSendStartCondition() ;
	MTWI_voidMasterSendAddress(L_u8WordAddress) ;
	MTWI_voidMasterSendData((u8)A_u16Address) ;
	MTWI_voidMasterSendRepetedStartCondition() ;
	L_u8WordAddress = ((0b10100001) | ((A_u16Address>>8)<<1)) ;
	MTWI_voidMasterSendAddressToRead(L_u8WordAddress) ;
	L_u8ReturnByte = MTWI_voidMasterReadDataWithNACK() ;
	MTWI_voidMasterSendStopCondition() ;
	return L_u8ReturnByte ;
}
