/*
 * EEPROM_reg.h
 *
 *  Created on: Aug 23, 2024
 *      Author: Mahmoud Osman
 */

#ifndef MCAL_EEPROM_EEPROM_REG_H_
#define MCAL_EEPROM_EEPROM_REG_H_
#include "../../LIB/STD_TYPES.h"
/*		EEPROM		*/
#define EEARH_REG *((volatile u8*)0x3F)
#define EEARL_REG *((volatile u8*)0x3E)
#define EEDR_REG  *((volatile u8*)0x3D)
#define EECR_REG  *((volatile u8*)0x3C)

#endif /* MCAL_EEPROM_EEPROM_REG_H_ */
