/*
 * DCMotor_prog.c
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "DCMotor_int.h"
#include "DCMotor_conf.h"


void HDC_voidInt   (void) 
{
	#if PIN_DC_T1 == PIN_DC_T2
	    #error "PIN_DC_T1 & PIN_DC_T2 are the same pin"
	#else
		/** Set direction of PORT_DC_T1 to output */
	    MDIO_voidSetPinDir (PORT_DC_T1 , PIN_DC_T1 , DIO_HIGH) ;
		/** Set direction of PORT_DC_T2 to output */
	    MDIO_voidSetPinDir (PORT_DC_T2 , PIN_DC_T2 , DIO_HIGH) ;
	#endif
}
void HDC_voidRoCw  (void) 
{
	#if PIN_DC_T1 == PIN_DC_T2
	    #error "PIN_DC_T1 & PIN_DC_T2 are the same pin"
	#else
		/** value of PIN_DC_T1 is one & value of PIN_DC_T2 is zero */
	    MDIO_voidSetPinVal (PORT_DC_T1 , PIN_DC_T1) ;
	    MDIO_voidClrPinVal (PORT_DC_T2 , PIN_DC_T2) ;
	#endif
}
void HDC_voidRoCcw (void) 
{
	#if PIN_DC_T1 == PIN_DC_T2
	    #error "PIN_DC_T1 & PIN_DC_T2 are the same pin"
	#else
		/** value of PIN_DC_T1 is zero & value of PIN_DC_T2 is one */
	    MDIO_voidClrPinVal (PORT_DC_T1 , PIN_DC_T1) ;
	    MDIO_voidSetPinVal (PORT_DC_T2 , PIN_DC_T2) ;
	#endif
}
void HDC_voidStop  (void) 
{
	#if PIN_DC_T1 == PIN_DC_T2
	    #error "PIN_DC_T1 & PIN_DC_T2 are the same pin"
	#else
		/** value of PIN_DC_T1 is zero & value of PIN_DC_T2 is zero */
	    MDIO_voidClrPinVal (PORT_DC_T1 , PIN_DC_T1) ;
	    MDIO_voidClrPinVal (PORT_DC_T2 , PIN_DC_T2) ;
	#endif
}