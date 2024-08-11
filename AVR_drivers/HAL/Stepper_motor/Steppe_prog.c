/*
 * Stepper_prog.c
 *
 * Created: 8/1/2022 
 *  Author: mohammed ramadan
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "Stepper_int.h"
#include "Stepper_conf.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void STPM_vInit(void)
{
	DIO_voidSetPinDir(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_OUTPUT);
	DIO_voidSetPinDir(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_OUTPUT);
	DIO_voidSetPinDir(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_OUTPUT);
	DIO_voidSetPinDir(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_OUTPUT);

	DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_HIGH);
	DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_HIGH);
	DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_HIGH);
	DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_PINK_PIN  , DIO_HIGH);
}

void STPM_vRCW(u16 A_u16Angle)
{
	u16 L_u16Counter;
	u16 L_u16Iterations = A_u16Angle / ANGLE_OF_ONE_STEP / NUMBER_OF_COILS + 1;
	for(L_u16Counter = 0; L_u16Counter < L_u16Iterations; L_u16Counter++) 
	{
		/* for first Activation */
		/* active c1 & deactive c2 , c3 , c4*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_LOW);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_HIGH);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_HIGH);
		_delay_ms(STEPER_DELAY);

		/* for second Activation */
		/* active c2 & deactive c1 , c3 , c4*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_LOW);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_HIGH);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_HIGH);
		_delay_ms(STEPER_DELAY);

		/* for third Activation */
		/* active c3 & deactive c1 , c2 , c4*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_LOW);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_HIGH);
		_delay_ms(STEPER_DELAY);

		/* for fourth Activation */
		/* active c4 & deactive c1 , c2 , c3*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_HIGH);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_LOW);
		_delay_ms(STEPER_DELAY);
	}
}

void STPM_vRCCW(u16 A_u16Angle)
{
	u16 L_u16Counter;
	u16 L_u16Iterations = A_u16Angle / ANGLE_OF_ONE_STEP / NUMBER_OF_COILS + 1;
	for(L_u16Counter = 0; L_u16Counter < L_u16Iterations; L_u16Counter++) 
	{
		/* for fourth Activation */
		/* active c4 & deactive c1 , c2 , c3*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_HIGH);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_LOW);
		_delay_ms(STEPER_DELAY);
		
		/* for third Activation */
		/* active c3 & deactive c1 , c2 , c4*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_LOW);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_HIGH);
		_delay_ms(STEPER_DELAY);
		
		/* for second Activation */
		/* active c2 & deactive c1 , c3 , c4*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_LOW);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_HIGH);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_HIGH);
		_delay_ms(STEPER_DELAY);
		
		/* for first Activation */
		/* active c1 & deactive c2 , c3 , c4*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_LOW);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_HIGH);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_HIGH);
		_delay_ms(STEPER_DELAY);
	}
}

void STPM_vRotateSteps(u16 A_u16Steps)
{
	u16 L_u8Iterator;
	for(L_u8Iterator = 0; L_u8Iterator <= A_u16Steps; L_u8Iterator++) 
	{
		/* for first Activation */
		/* active c1 & deactive c2 , c3 , c4*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_LOW);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_HIGH);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_HIGH);
		_delay_ms(STEPER_DELAY);

		/* for second Activation */
		/* active c2 & deactive c1 , c3 , c4*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_LOW);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_HIGH);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_HIGH);
		_delay_ms(STEPER_DELAY);

		/* for third Activation */
		/* active c3 & deactive c1 , c2 , c4*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_LOW);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_HIGH);
		_delay_ms(STEPER_DELAY);

		/* for fourth Activation */
		/* active c4 & deactive c1 , c2 , c3*/
		DIO_voidSetPinVal(STPM_BLUE_PORT  , STPM_BLUE_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_PINK_PORT  , STPM_PINK_PIN  , DIO_HIGH);
		DIO_voidSetPinVal(STPM_YELLOW_PORT, STPM_YELLOW_PIN, DIO_HIGH);
		DIO_voidSetPinVal(STPM_ORANGE_PORT, STPM_ORANGE_PIN, DIO_LOW);
		_delay_ms(STEPER_DELAY);
	}
}