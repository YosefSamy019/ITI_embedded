/*
 * TWI_private.h
 *
 * Created: 18/08/2024 11:01:03 ص
 *  Author: a24e4
 */ 


#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_



#define MTWBR_VAL(CPU_F,TWI_F) (CPU_F/TWI_F - 16)/(2*1)




//Status Code
//-----------------------------------------------------------------------------------------------------
#define MTWI_STATUS_START_ACK                             0x08   /* start has been send */
#define MTWI_STATUS_REP_START                             0x10   /* repeated start*/
#define MTWI_STATUS_SLAVE_ADD_AND_WR_ACK                  0x18   /* MASTER transmit (slave address + write request  */
#define MTWI_STATUS_SLAVE_ADD_AND_RR_ACK                  0x40   /* MASTER transmit (slave address + read request  */
#define MTWI_STATUS_MASTER_WR_BYTE_ACK                    0x28   /* MASTER transmit Data ack  */
#define MTWI_STATUS_MASTER_RD_BYTE_WITH_ACK               0x50   /* MASTER  recive data with ack  */
#define MTWI_STATUS_MASTER_RD_BYTE_WITH_NACK              0x58   /* MASTER  recive data with ack  */
#define MTWI_STATUS_SLAVE_ADD_RCVD_RD_REQ                 0xA8   /* MEANS that slave address is received with read request  */
#define MTWI_STATUS_SLAVE_ADD_RCVD_WD_REQ                 0x60   /* MEANS that slave address is received with Write request  */
#define MTWI_STATUS_SLAVE_DATA_RECEIVED                   0x80   /* MEANS that data byte is recevied */
#define MTWI_STATUS_SLAVE_BYTE_TRANSMITTIED               0xB8   /* MEANS that data byte  are transmitted  */
//-----------------------------------------------------------------------------------------------------



#endif /* TWI_PRIVATE_H_ */