/*
 * TIMER_2_config.h
 *
 * Created: 23/08/2024 09:57:28 ص
 *  Author: a24e4
 */ 


#ifndef TIMER_2_CONFIG_H_
#define TIMER_2_CONFIG_H_



//Calculations of CTC & NORMAL
#define MTIMER2_PRELOAD_VAL 24		//NORMAL OR CTC
#define MTIMER2_MAX_COUNT 4			//NORMAL OR CTC
#define MTIMER2_COMPARE_VALUE 200	//CTC Only

//Timer/Counter Mode of Operation
#define MTIMER2_MODE_NORMAL 0
#define MTIMER2_MODE_PHASE_CORRECT 1
#define MTIMER2_MODE_CTC 2
#define MTIMER2_MODE_FAST_PWM 3
#define MTIMER2_MODE_SELECT MTIMER2_MODE_NORMAL

//Compare Output Mode           					//NORMAL/CTC		 F-PWM												 Phase-correct
#define MTIMER2_OC2_MODE_0 0						//discounted		 discounted										     discounted
#define MTIMER2_OC2_MODE_1 1						//toggle on compare  reserved										     reserved
#define MTIMER2_OC2_MODE_2 2						//clear on compare   clear on compare,set at bottom(nin-inverted)        clear count-up,set count-down
#define MTIMER2_OC2_MODE_3 3						//set on compare	 set on compare,clear at bottom(inverted)            set count-up, clear count-down
#define MTIMER2_OC2_SELECT MTIMER2_OC2_MODE_0

//Clock Select Bit Description
#define MTIMER2_PRESCALER_NO_CLOCK 0
#define MTIMER2_PRESCALER_1 1
#define MTIMER2_PRESCALER_8 2
#define MTIMER2_PRESCALER_32 3
#define MTIMER2_PRESCALER_64 4
#define MTIMER2_PRESCALER_128 5
#define MTIMER2_PRESCALER_256 6
#define MTIMER2_PRESCALER_1024 7
#define MTIMER2_PRESCALER_SELECT						 MTIMER2_PRESCALER_8




#endif /* TIMER_2_CONFIG_H_ */