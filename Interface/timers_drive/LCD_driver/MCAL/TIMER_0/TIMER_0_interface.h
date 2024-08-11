/*
 * TIMER_0_interface.h
 *
 * Created: 11/08/2024 12:08:01 م
 *  Author: a24e4
 */ 


#ifndef TIMER_0_INTERFACE_H_
#define TIMER_0_INTERFACE_H_


void MTIMER_0_voidInit(void);

void MTimer_0_voidDisableClk(void);

void MTimer_0_voidEnableClk(void);

void MTimer_0_voidSetCallback(ptr2voidCallback A_ptr2voidCallback_callback);

void MTimer_0_voidDisableInterrupt(void);

void MTimer_0_voidEnableInterrupt(void);

#endif /* TIMER_0_INTERFACE_H_ */