/*
 * Servo_prog.c
 *
 * Created: 8/18/2022 4:31:01 PM
 *  Author: mohammed ramadan
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/Timer/Timer_register.h"
#include "../../MCAL/Timer/Timer_int.h"
#include "Servo_private.h"
#include "Servo_int.h"

#define TIME_OF_ONE_DEGREE  0.0055555555555555555

void HSevo_voidMoveTO (f32 A_f32Angle)
{
	f32 L_f32Value ;
	if (A_f32Angle >= (f32)0.0 && A_f32Angle <= (f32)90.0)
	{
		L_f32Value = 1.5 + (A_f32Angle * TIME_OF_ONE_DEGREE) ;
	}
	else if (A_f32Angle <= (f32)0.0 && A_f32Angle >= (f32)-90.0)
	{
		L_f32Value = 1.5 - (A_f32Angle * - TIME_OF_ONE_DEGREE) ;
	}
	/* set OC1A as output pin */
	MDIO_voidSetPinDir (DIO_PORTD , DIO_PIN5 , DIO_HIGH) ;
	
	/* select fast PWM mode*/
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	/* load a value in OCR1A,ICR1 */
	
	OCR1A=L_f32Value*1000;
	ICR1=19999;
	
	/* select timer clock, 1MHZ */
	CLR_BIT(TCCR1B , CS10) ;
	SET_BIT(TCCR1B , CS11) ;
    CLR_BIT(TCCR1B , CS12) ;
	
	/* clear OC1A on compare match, set OC1A at BOTTOM,(non inverting mode)*/
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
}
