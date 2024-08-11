/*
 * DCMotor_int.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */
 
#ifndef HAL_DC_MOTOR_DCMOTOR_INT_H_
#define HAL_DC_MOTOR_DCMOTOR_INT_H_

/*
	Function Name        : HDC_voidInt
	Function Returns     : void
	Function Arguments   : void
	Function Description : intialize LCD
*/
void HDC_voidInt   (void) ;

/*
	Function Name        : HDC_voidRoCw
	Function Returns     : void
	Function Arguments   : void
	Function Description : rotate DC motor in counter wise
*/
void HDC_voidRoCw  (void) ;

/*
	Function Name        : HDC_voidRoCcw
	Function Returns     : void
	Function Arguments   : void
	Function Description : rotate DC motor in counter clock wise
*/
void HDC_voidRoCcw (void) ;

/*
	Function Name        : HDC_voidStop
	Function Returns     : void
	Function Arguments   : void
	Function Description : turn off DC motor
*/
void HDC_voidStop  (void) ;


#endif  /*HAL_DC_MOTOR_DCMOTOR_INT_H_*/