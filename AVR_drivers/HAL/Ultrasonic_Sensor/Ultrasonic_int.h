/*
 * Ultrasonic_int.h
 *
 *  Created on: Jun 2, 2022
 *      Author: Mohamed Ramadan
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_INT_H_
#define HAL_ULTRASONIC_ULTRASONIC_INT_H_

/*
	Function Name        : HUltrasonic_voidInt
	Function Returns     : void
	Function Arguments   : void
	Function Description : intialize Ultrasonic sensor
*/
void HUltrasonic_voidInt (void) ;

/*
	Function Name        : HUltrasonic_u16CalcDistance
	Function Returns     : u16
	Function Arguments   : void
	Function Description : calc distance between object and ultrasonic
*/
u16 HUltrasonic_u16CalcDistance (void) ;

#endif /*HAL_ULTRASONIC_ULTRASONIC_INT_H_*/