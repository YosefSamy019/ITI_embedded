/*
 * EEPROM_init.h
 *
 * Created: 8/30/2022 2:28:04 PM
 *  Author: maka
 */ 


#ifndef EEPROM_INIT_H_
#define EEPROM_INIT_H_

void HEEPROM_voidInit (u32 A_u32Scl) ;
void HEEPROM_voidWriteByte (u16 A_u16Address , u8 A_u8Data) ;
u8 HEEPROM_u8ReadByte (u16 A_u16Address) ;

#endif /* EEPROM_INIT_H_ */