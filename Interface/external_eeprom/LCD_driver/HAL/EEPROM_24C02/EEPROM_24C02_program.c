/*
 * EEPROM_24C02_program.c
 *
 * Created: 26/08/2024 03:09:33 م
 *  Author: a24e4
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/TWI/TWI_interface.h"
#include "../../MCAL/DELAY/DELAY_interface.h"

#include "EEPROM_24C02_config.h"
#include "EEPROM_24C02_interface.h"
#include "EEPROM_24C02_private.h"

void HEEPROM_24C02_voidWrite(u8 A_u8_location, u8 A_u8_data){
		u8 L_u8SlaveAdd = 0b01010000;
		L_u8SlaveAdd = L_u8SlaveAdd | (HEEPROM_24C02_A2<<2) | (HEEPROM_24C02_A1<<1) | (HEEPROM_24C02_A0);
		
		MTWI_u8_sendStartCondition();
		MTWI_u8_sendSlaveAddress(L_u8SlaveAdd,MTWI_WRITE);
		MTWI_u8_sendData(A_u8_location);
		MTWI_u8_sendData(A_u8_data);
		MDELAY_void_milli(HEEPROM_24C02_WRITE_DELAY_MILLI);
		MTWI_u8_sendStopCondition();
		
		MDELAY_void_milli(10);
}

u8 HEEPROM_24C02_u8Read(u8 A_u8_location){
		u8 L_u8Data = 0x00;
		u8 L_u8SlaveAdd = 0b01010000;
		L_u8SlaveAdd = L_u8SlaveAdd | (HEEPROM_24C02_A2<<2) | (HEEPROM_24C02_A1<<1) | (HEEPROM_24C02_A0);
		
		MTWI_u8_sendStartCondition();
		MTWI_u8_sendSlaveAddress(L_u8SlaveAdd,MTWI_WRITE);
		MTWI_u8_sendData(A_u8_location);
		MTWI_u8_sendStartCondition();
		MTWI_u8_sendSlaveAddress(L_u8SlaveAdd,MTWI_READ);
		MTWI_u8_receiveDataWithAck(&L_u8Data);
		MTWI_u8_sendStopCondition();
		
				MDELAY_void_milli(10);

		return L_u8Data;
}