/*
 * Stepper_int.h
 *
 * Created: 8/1/2022 
 *  Author: mohammed ramadan
 */
 
#ifndef HAL_STEPPER_MOTOR_STEPPER_INT_H_
#define HAL_STEPPER_MOTOR_STEPPER_INT_H_

/*
	Function Name        : HSTPM_voidInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize Stepper motor
*/
void HSTPM_voidInit(void);

/*
	Function Name        : HSTPM_voidRCW
	Function Returns     : void
	Function Arguments   : u16 A_u16Angle
	Function Description : Rotate Stepper motor counter wise
*/
void HSTPM_voidRCW(u16 A_u16Angle);

/*
	Function Name        : HSTPM_voidRCCW
	Function Returns     : void
	Function Arguments   : u16 A_u16Angle
	Function Description : Rotate Stepper motor counter clock wise
*/
void HSTPM_voidRCCW(u16 A_u16Angle);

/*
	Function Name        : HSTPM_voidRotateSteps
	Function Returns     : void
	Function Arguments   : u16 A_u16Steps
	Function Description : Move servo to desired steps
*/
void HSTPM_voidRotateSteps(u16 A_u16Steps);

#endif /*HAL_STEPPER_MOTOR_STEPPER_INT_H_*/