/*
 * TIMER_2_interface.h
 *
 * Created: 23/08/2024 09:56:50 ص
 *  Author: a24e4
 */ 


#ifndef TIMER_2_INTERFACE_H_
#define TIMER_2_INTERFACE_H_


void MTIMER_2_voidInit(void);

void MTIMER_2_voidDisableClk(void);

void MTIMER_2_voidEnableClk(void);

#if MTIMERO_MODE_SELECT == MTIMER2_MODE_NORMAL || MTIMERO_MODE_SELECT == MTIMER2_MODE_CTC
void MTIMER_2_voidSetCallback(ptr2voidCallback A_ptr2voidCallback_callback);
#endif

#if MTIMERO_MODE_SELECT == MTIMER2_MODE_NORMAL || MTIMERO_MODE_SELECT == MTIMER2_MODE_CTC
void MTIMER_2_voidDisableInterrupt(void);
#endif

#if MTIMERO_MODE_SELECT == MTIMER2_MODE_NORMAL || MTIMERO_MODE_SELECT == MTIMER2_MODE_CTC
void MTIMER_2_voidEnableInterrupt(void);
#endif

#if MTIMERO_MODE_SELECT == MTIMER2_MODE_FAST_PWM || MTIMERO_MODE_SELECT == MTIMER2_MODE_PHASE_CORRECT
//dutyCycle range [000, 100]
void MTIMER_2_voidSetDutyCucle(u8 A_u8DutyCycle);
#endif



#endif /* TIMER_2_INTERFACE_H_ */