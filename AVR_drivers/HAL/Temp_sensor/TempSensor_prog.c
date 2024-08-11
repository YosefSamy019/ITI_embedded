/*
 * TempSensor_prog.c
 *
 * Created: 8/1/2022 
 *  Author: mohammed ramadan
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "TempSensor_conf.h"
#include "TempSensor_int.h"

void HTempSensor_voidInt (void)
{
	/*Initialize ADC*/
	MADC_voidInt() ;
}

u16 HTempSensor_u16ReadTemp (void)
{
	u16 L_u16Temp ;
	/*start conversion of ADC*/
	MADC_voidStartConversion(TEMP_CHANNEL) ;
	
	/*calc temperature*/
	/*
	volt = step * read_val ;
	step = Vref / resolution
	for internal Vref = 2.56 , n of bits = 10 --> resolution = 1024
	volt = read_val * 2.56 / 1024        (v)
	volt = read_val * 1000 * 2.56 / 1024 (mv)
	volt = 2.5 * read_val (mv)
	1 c --------> 10 (mv)
	Temp = volt (mv) / 10 (mv)
	Temp = 0.25 * read_val ;
	*/
	L_u16Temp = MADC_u16GetADCData() * 0.25 ;
	return L_u16Temp ;
}