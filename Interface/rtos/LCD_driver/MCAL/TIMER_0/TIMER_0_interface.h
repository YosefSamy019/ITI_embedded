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

#if MTIMERO_MODE_SELECT == MTIMER0_MODE_NORMAL || MTIMERO_MODE_SELECT == MTIMER0_MODE_CTC
	void MTimer_0_voidSetCallback(ptr2voidCallback A_ptr2voidCallback_callback);
#endif

#if MTIMERO_MODE_SELECT == MTIMER0_MODE_NORMAL || MTIMERO_MODE_SELECT == MTIMER0_MODE_CTC
	void MTimer_0_voidDisableInterrupt(void);
#endif

#if MTIMERO_MODE_SELECT == MTIMER0_MODE_NORMAL || MTIMERO_MODE_SELECT == MTIMER0_MODE_CTC
	void MTimer_0_voidEnableInterrupt(void);
#endif

#if MTIMERO_MODE_SELECT == MTIMER0_MODE_FAST_PWM || MTIMERO_MODE_SELECT == MTIMER0_MODE_PHASE_CORRECT
	//dutyCycle range [000, 1023]
	void MTIMER_0_voidSetDutyCucle(u8 A_u8DutyCycle);
#endif

#endif /* TIMER_0_INTERFACE_H_ */