/*
 * WDT_int.h
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */
 
#ifndef MCAL_WDT_WDT_INT_H_
#define MCAL_WDT_WDT_INT_H_

/*WDT prescaller*/
#define WDT_16ms3   0
#define WDT_32ms5   1
#define WDT_65ms0    2
#define WDT_0s13    3
#define WDT_0s26    4
#define WDT_0s52    5
#define WDT_1s0     6
#define WDT_2s1     7

/*
	Function Name        : MWDT_voidTurnOn
	Function Returns     : void
	Function Arguments   : void
	Function Description : turn on WDT after desired time
*/
void MWDT_voidTurnOn  (u8 A_u8TimeOut);

/*
	Function Name        : MWDT_voidTurnOff
	Function Returns     : void
	Function Arguments   : void
	Function Description : disable WDT
*/
void MWDT_voidTurnOff (void);

#endif /* MCAL_WDT_WDT_INT_H_ */