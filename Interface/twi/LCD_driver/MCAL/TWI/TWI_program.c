/*
 * TWI_program.c
 *
 * Created: 18/08/2024 11:00:48 ص
 *  Author: a24e4
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_register.h"

void MTWI_void_initMaster(void){
		//TWI BIT RATE
		TWBR_REG = MTWBR_VAL(MCPU_FREQ_HZ,MTWI_FREQ_HZ);
		
		// TWI Prescaler Bits (fixed at 1 in this driver)
		CLR_BIT(TWSR_REG,0);
		CLR_BIT(TWSR_REG,1);

		//enable TWI
		SET_BIT(TWCR_REG,2);
}
void MTWI_void_initSlave(u8 A_u8_slaveAddress_7bits){
		//Slave address
		TWAR_REG = A_u8_slaveAddress_7bits<<1;
		
		//Enable ACK
		SET_BIT(TWCR_REG,6);
		
		//enable TWI
		SET_BIT(TWCR_REG,2);
}
u8 MTWI_u8_sendStartCondition(void){
	u8 L_u8Status = 0x00;
	
	// TWI START Condition Bit
	SET_BIT(TWCR_REG,5);

	//Clear FLAG
	SET_BIT(TWCR_REG,7);
	
	//Wait FLAG
	while(GET_BIT(TWCR_REG,7) == 0);
	
	L_u8Status = (((u8)TWSR_REG) >> 3)<<3;
	
	return L_u8Status;
}
u8 MTWI_u8_sendSlaveAddress(u8 A_u8_address_7bits,u8 A_u8_rw_1bit){
	u8 L_u8Status = 0x00;
	
	//Slave address
	TWDR_REG = (A_u8_address_7bits<<1) | (A_u8_rw_1bit & 0x01);

	//Clear TWI START Condition Bit
	CLR_BIT(TWCR_REG,5);

	//Clear FLAG
	SET_BIT(TWCR_REG,7);
	
	//Wait FLAG
	while(GET_BIT(TWCR_REG,7) == 0);
	
	L_u8Status = (((u8)TWSR_REG) >> 3)<<3;
	
	return L_u8Status;
}
u8 MTWI_u8_sendData(u8 A_u8_data){
		u8 L_u8Status = 0x00;

		//data
		TWDR_REG = A_u8_data;
		
		//Clear FLAG
		SET_BIT(TWCR_REG,7);
		
		//Wait FLAG
		while(GET_BIT(TWCR_REG,7) == 0);
		
	L_u8Status = (((u8)TWSR_REG) >> 3)<<3;
		
	return L_u8Status;
}
u8 MTWI_u8_receiveDataWithAck(u8 *A_u8_copyData){
		u8 L_u8Status = 0x00;
		// TWI Enable Acknowledge Bit
		SET_BIT(TWCR_REG,6);
		
		//Clear FLAG
		SET_BIT(TWCR_REG,7);
		
		//Wait FLAG
		while(GET_BIT(TWCR_REG,7) == 0);
		
	L_u8Status = (((u8)TWSR_REG) >> 3)<<3;
		*A_u8_copyData = (u8)TWDR_REG;
		
		return L_u8Status;
}
u8 MTWI_u8_sendStopCondition(void){
	u8 L_u8Status = 0x00;
	
	//TWI STOP Condition Bit
	SET_BIT(TWCR_REG,4);
	
	//Clear FLAG
	SET_BIT(TWCR_REG,7);
	
	//Wait
	while(GET_BIT(TWCR_REG,4) == 1);
	
	//get status
	L_u8Status = (((u8)TWSR_REG) >> 3)<<3;
	
	return L_u8Status;
}
u8 MTWI_u8_waitAckSlave(void){
	u8 L_u8Status;
	
	//Clear FLAG
	SET_BIT(TWCR_REG,7);
	
	//wait
	while(GET_BIT(TWCR_REG,7)==0);
	
	L_u8Status = (((u8)TWSR_REG) >> 3)<<3;
	
	return L_u8Status;
}
u8 MTWI_u8_receiveDataSalve(u8 *A_u8_copyData){
	u8 L_u8Status = 0x00;

	//Clear FLAG
	SET_BIT(TWCR_REG,7);
	
	//Wait FLAG
	while(GET_BIT(TWCR_REG,7) == 0);
	
	L_u8Status = (((u8)TWSR_REG) >> 3)<<3;
	*A_u8_copyData = (u8)TWDR_REG;
	
	return L_u8Status;
}