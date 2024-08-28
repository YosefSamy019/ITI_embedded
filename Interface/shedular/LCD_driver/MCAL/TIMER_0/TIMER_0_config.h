/*
 * TIMER_0_config.h
 *
 * Created: 11/08/2024 12:08:25 م
 *  Author: a24e4
 */ 


#ifndef TIMER_0_CONFIG_H_
#define TIMER_0_CONFIG_H_



//Calculations of CTC & NORMAL
#define MTIMER0_PRELOAD_VAL 200		//NORMAL OR CTC
#define MTIMER0_MAX_COUNT 6		//NORMAL OR CTC
#define MTIMER0_COMPARE_VALUE 200	//CTC Only

//Timer/Counter Mode of Operation
#define MTIMER0_MODE_NORMAL 0
#define MTIMER0_MODE_PHASE_CORRECT 1
#define MTIMER0_MODE_CTC 2
#define MTIMER0_MODE_FAST_PWM 3
#define MTIMERO_MODE_SELECT MTIMER0_MODE_CTC

//Compare Output Mode           					//NORMAL/CTC		 F-PWM												 Phase-correct
#define MTIMER0_OC0_MODE_0 0						//discounted		 discounted										     discounted
#define MTIMER0_OC0_MODE_1 1						//toggle on compare  reserved										     reserved
#define MTIMER0_OC0_MODE_2 2						//clear on compare   clear on compare,set at bottom(nin-inverted)        clear count-up,set count-down
#define MTIMER0_OC0_MODE_3 3						//set on compare	 set on compare,clear at bottom(inverted)            set count-up, clear count-down
#define MTIMER0_OC0_SELECT MTIMER0_OC0_MODE_0

//Clock Select Bit Description
#define MTIMER0_PRESCALER_NO_CLOCK 0
#define MTIMER0_PRESCALER_1 1
#define MTIMER0_PRESCALER_8 2
#define MTIMER0_PRESCALER_64 3
#define MTIMER0_PRESCALER_256 4
#define MTIMER0_PRESCALER_1024 5
#define MTIMER0_PRESCALER_EXT_CLK_T0_PIN_FALLING_EDGE 6
#define MTIMER0_PRESCALER_EXT_CLK_T0_PIN_RISING_EDGE 7
#define MTIMER0_PRESCALER_SELECT						 MTIMER0_PRESCALER_8



#endif /* TIMER_0_CONFIG_H_ */