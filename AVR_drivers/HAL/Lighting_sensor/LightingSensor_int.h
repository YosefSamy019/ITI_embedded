/*
 * LightingSensor_int.h
 *
 * Created: 8/1/2022 
 *  Author: mohammed ramadan
 */
 
#ifndef HAL_LIGHTINGSENSOR_LIGHTINGSENSOR_INT_H_
#define HAL_LIGHTINGSENSOR_LIGHTINGSENSOR_INT_H_

/*
	Function Name        : HLightingSensor_voidInt
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize LDR sensor 
*/
void HLightingSensor_voidInt (void) ;

/*
	Function Name        : HLightingSensor_u16ReadTemp
	Function Returns     : u16
	Function Arguments   : void
	Function Description : measure Denesity of light 
*/
f32 HLightingSensor_f32MeasureVout (void) ;

#endif  /*HAL_LIGHTINGSENSOR_LIGHTINGSENSOR_INT_H_*/