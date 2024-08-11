/*
 * LightingSensor_prog.c
 *
 * Created: 8/1/2022 
 *  Author: mohammed ramadan
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "LightingSensor_conf.h"
#include "LightingSensor_int.h"

void HLightingSensor_voidInt (void)
{
	/*Initialize ADC*/
	MADC_voidInt() ;
}

f32 HLightingSensor_f32MeasureVout (void)
{
	f32 L_f32Volt ;
	/*start conversion of ADC*/
	MADC_voidStartConversion(LIGHTING_SENSOR_CHANNEL) ;
	
	/*calc volt*/
	/*
	volt = step * read_val ;
	step = Vref / resolution
	for Vref = 5 , n of bits = 10 --> resolution = 1024
	volt = read_val * 5 / 1024 (v)
	volt = 0.0048828 * read_val (v)
	*/
	L_f32Volt = MADC_u16GetADCData() * 0.0048828 ;
	return L_f32Volt ;
}