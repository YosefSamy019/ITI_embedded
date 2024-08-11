/*
 * T2C_int.h
 *
 *  Created on: Aug 9, 2022
 *      Author: mohammed ramadan
 */

#ifndef MCAL_TWI_T2C_INT_H_
#define MCAL_TWI_T2C_INT_H_

void MTWI_voidMasterInt (u32 A_u32Scl) ;

void MTWI_voidMasterSendStartCondition (void) ;

void MTWI_voidMasterSendRepetedStartCondition (void) ;

void MTWI_voidMasterSendAddress (u8 A_u8Address) ;

void MTWI_voidMasterSendData (u8 A_u8Data) ;

void MTWI_voidMasterSendStopCondition (void) ;

void MTWI_voidSlaveSetAddress (u8 A_u8Address) ;

u8 MTWI_voidMasterReadData (void) ;

u8 MTWI_voidSlaveReadData (void) ;

#endif /* MCAL_TWI_T2C_INT_H_ */
