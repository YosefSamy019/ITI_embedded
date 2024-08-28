/*
 * EEPROM.h
 *
 *  Created on: Aug 23, 2024
 *      Author: Mahmoud Osman
 */

#ifndef MCAL_EEPROM_EEPROM_H_
#define MCAL_EEPROM_EEPROM_H_
#include "EEPROM_reg.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
void EEPROM_writeByte(u16 location_10bit,u8 data);
u8 EEPROM_readByte(u16 location_10bit);

#endif /* MCAL_EEPROM_EEPROM_H_ */
