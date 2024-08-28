/*
 * TWI_interface.h
 *
 * Created: 18/08/2024 11:01:54 ص
 *  Author: a24e4
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

#define MTWI_READ  1
#define MTWI_WRITE 0

void MTWI_void_initMaster(void);
void MTWI_void_initSlave(u8 A_u8_slaveAddress_7bits);
u8 MTWI_u8_sendStartCondition(void);
u8 MTWI_u8_sendSlaveAddress(u8 A_u8_address_7bits,u8 A_u8_rw_1bit);
u8 MTWI_u8_sendData(u8 A_u8_data);
u8 MTWI_u8_receiveDataWithAck(u8 *A_u8_copyData);
u8 MTWI_u8_sendStopCondition(void);
u8 MTWI_u8_waitAckSlave(void);
u8 MTWI_u8_receiveDataSalve(u8 *A_u8_copyData);




#endif /* TWI_INTERFACE_H_ */