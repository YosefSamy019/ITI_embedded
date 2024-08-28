/*
 * BUZZER_int.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_BUZZER_BUZZER_INT_H_
#define HAL_BUZZER_BUZZER_INT_H_


/*
	Function Name        : HBUZZER_voidBUZZERInitial
	Function Returns     : void
	Function Arguments   : u8 A_u8BUZZER_ID
	Function Description : Define the BUZZER as OUTPUT
*/
void HBUZZER_voidBUZZERInitial (void) ;

/*
	Function Name        : HBUZZER_voidBUZZEROn
	Function Returns     : void
	Function Arguments   : u8 A_u8BUZZER_ID
	Function Description : Turn on BUZZER
*/
void HBUZZER_voidBUZZEROn (void) ;

/*
	Function Name        : HBUZZER_voidBUZZEROff
	Function Returns     : void
	Function Arguments   : u8 A_u8BUZZER_ID
	Function Description : Turn off BUZZER
*/
void HBUZZER_voidBUZZEROff (void) ;

/*
	Function Name        : HBUZZER_voidBUZZERToggle
	Function Returns     : void
	Function Arguments   : u8 A_u8BUZZER_ID
	Function Description : Reverse the status of BUZZER
*/
void HBUZZER_voidBUZZERToggle (void) ;

#endif /* HAL_BUZZER_BUZZER_INT_H_ */
