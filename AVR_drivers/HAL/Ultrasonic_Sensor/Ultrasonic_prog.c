/*
 * Ultrasonic_prog.h
 *
 *  Created on: Jun 2, 2022
 *      Author: Mohamed Ramadan
 */
 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/Timer/Timer_int.h"
#include "Ultrasonic_private.h"
#include "Ultrasonic_conf.h"
#include "Ultrasonic_int.h"
#define F_CPU 8000000UL
#include <util/delay.h>
void HUltrasonic_voidInt (void) 
{
	/*set trig pin as output pin*/
	MDIO_voidSetPinDir(TRIG_PORT , TRIG_PIN , DIO_HIGH) ;
}

u16 HUltrasonic_u16CalcDistance (void)
{
	u16 L_u16Distance = 0 ;
	
	MTimer_voidInt() ;
	
	/*set trig pin as output pin*/
	MDIO_voidSetPinDir(TRIG_PORT , TRIG_PIN , DIO_HIGH) ;
	MDIO_voidSetPinVal(TRIG_PORT , TRIG_PIN) ;
	_delay_us(50) ;
	MDIO_voidClrPinVal(TRIG_PORT , TRIG_PIN) ;
	L_u16Distance = SOUND_VELOCITY ;
	L_u16Distance = L_u16Distance / 2 ;
	L_u16Distance = L_u16Distance / MTimerCalcFreqofTon() ;
	return L_u16Distance ;
}