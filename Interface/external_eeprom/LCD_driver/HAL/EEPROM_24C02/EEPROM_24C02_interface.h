/*
 * EEPROM_24C02_interface.h
 *
 * Created: 26/08/2024 03:10:06 م
 *  Author: a24e4
 */ 


#ifndef EEPROM_24C02_INTERFACE_H_
#define EEPROM_24C02_INTERFACE_H_


void HEEPROM_24C02_voidWrite(u8 A_u8_location, u8 A_u8_data);
u8 HEEPROM_24C02_u8Read(u8 A_u8_location);


#endif /* EEPROM_24C02_INTERFACE_H_ */