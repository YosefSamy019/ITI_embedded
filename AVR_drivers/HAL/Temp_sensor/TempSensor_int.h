/*
 * TempSensor_int.h
 *
 * Created: 8/1/2022 
 *  Author: mohammed ramadan
 */
 
#ifndef HAL_TEMPSENSOR_TEMPSENSOR_INT_H_
#define HAL_TEMPSENSOR_TEMPSENSOR_INT_H_

/*
	Function Name        : HTempSensor_voidInt
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize Temperature sensor 
*/
void HTempSensor_voidInt (void) ;

/*
	Function Name        : HTempSensor_u16ReadTemp
	Function Returns     : u16
	Function Arguments   : void
	Function Description : measure Temperature 
*/
u16 HTempSensor_u16ReadTemp (void) ;

#endif  /*HAL_TEMPSENSOR_TEMPSENSOR_INT_H_*/