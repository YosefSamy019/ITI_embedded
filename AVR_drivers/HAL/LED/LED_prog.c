/*
 * LED_prog.c
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LED_int.h"

void HLED_voidLedInitial (u8 A_u8LED_ID)
{
	switch (A_u8LED_ID)
	{                  /**make direction of LED_1 is output*/
		case LED1_ID : MDIO_voidSetPinDir(LED1_PORT , LED1_PIN , LED_OUTPUT) ; break ;
		
		               /**make direction of LED_2 is output*/
		case LED2_ID : MDIO_voidSetPinDir(LED2_PORT , LED2_PIN , LED_OUTPUT) ; break ;
		
		               /**make direction of LED_3 is output*/
		case LED3_ID : MDIO_voidSetPinDir(LED3_PORT , LED3_PIN , LED_OUTPUT) ; break ;
		
		               /**make direction of LED_4 is output*/
		case LED4_ID : MDIO_voidSetPinDir(LED4_PORT , LED4_PIN , LED_OUTPUT) ; break ;
		
		               /**make direction of LED_5 is output*/
		case LED5_ID : MDIO_voidSetPinDir(LED5_PORT , LED5_PIN , LED_OUTPUT) ; break ;
		
		               /**make direction of LED_6 is output*/
		case LED6_ID : MDIO_voidSetPinDir(LED6_PORT , LED6_PIN , LED_OUTPUT) ; break ;
		
		               /**make direction of LED_7 is output*/
		case LED7_ID : MDIO_voidSetPinDir(LED7_PORT , LED7_PIN , LED_OUTPUT) ; break ;
		
		               /**make direction of LED_8 is output*/
		case LED8_ID : MDIO_voidSetPinDir(LED8_PORT , LED8_PIN , LED_OUTPUT) ; break ;
		default      : /** Error */                                            break ;
	}
}

void HLED_voidLedOn (u8 A_u8LED_ID)
{
	switch (A_u8LED_ID)
	{
		               /**turn on LED_1*/
		case LED1_ID : MDIO_voidSetPinVal(LED1_PORT , LED1_PIN) ; break ;
		
		               /**turn on LED_2*/
		case LED2_ID : MDIO_voidSetPinVal(LED2_PORT , LED2_PIN) ; break ;
		
		               /**turn on LED_3*/
		case LED3_ID : MDIO_voidSetPinVal(LED3_PORT , LED3_PIN) ; break ;
		
		               /**turn on LED_4*/
		case LED4_ID : MDIO_voidSetPinVal(LED4_PORT , LED4_PIN) ; break ;
		
		               /**turn on LED_5*/
		case LED5_ID : MDIO_voidSetPinVal(LED5_PORT , LED5_PIN) ; break ;
		
		               /**turn on LED_6*/
		case LED6_ID : MDIO_voidSetPinVal(LED6_PORT , LED6_PIN) ; break ;
		
		               /**turn on LED_7*/
		case LED7_ID : MDIO_voidSetPinVal(LED7_PORT , LED7_PIN) ; break ;
		
		               /**turn on LED_8*/
		case LED8_ID : MDIO_voidSetPinVal(LED8_PORT , LED8_PIN) ; break ;
		default      : /** Error */                               break ;
	}
}

void HLED_voidLedOff (u8 A_u8LED_ID)
{
	switch (A_u8LED_ID)
	{                  /**turn off LED_1*/
		case LED1_ID : MDIO_voidClrPinVal(LED1_PORT , LED1_PIN) ; break ;
		
		               /**turn off LED_2*/
		case LED2_ID : MDIO_voidClrPinVal(LED2_PORT , LED2_PIN) ; break ;
		
		               /**turn off LED_3*/
		case LED3_ID : MDIO_voidClrPinVal(LED3_PORT , LED3_PIN) ; break ;
		
		               /**turn off LED_4*/
		case LED4_ID : MDIO_voidClrPinVal(LED4_PORT , LED4_PIN) ; break ;
		
		               /**turn off LED_5*/
		case LED5_ID : MDIO_voidClrPinVal(LED5_PORT , LED5_PIN) ; break ;
		
		               /**turn off LED_6*/
		case LED6_ID : MDIO_voidClrPinVal(LED6_PORT , LED6_PIN) ; break ;
		
		               /**turn off LED_7*/
		case LED7_ID : MDIO_voidClrPinVal(LED7_PORT , LED7_PIN) ; break ;
		
		               /**turn off LED_8*/
		case LED8_ID : MDIO_voidClrPinVal(LED8_PORT , LED8_PIN) ; break ;
		default      : /** Error */                               break ;
	}
}

void HLED_voidLedToggle (u8 A_u8LED_ID)
{
	switch (A_u8LED_ID)
	{
		               /**inverse status of LED_1*/
		case LED1_ID : MDIO_voidTogPinVal(LED1_PORT , LED1_PIN) ; break ;
		
		               /**inverse status of LED_2*/
		case LED2_ID : MDIO_voidTogPinVal(LED2_PORT , LED2_PIN) ; break ;
		
		               /**inverse status of LED_3*/
		case LED3_ID : MDIO_voidTogPinVal(LED3_PORT , LED3_PIN) ; break ;
		
		               /**inverse status of LED_4*/
		case LED4_ID : MDIO_voidTogPinVal(LED4_PORT , LED4_PIN) ; break ;
		
		               /**inverse status of LED_5*/
		case LED5_ID : MDIO_voidTogPinVal(LED5_PORT , LED5_PIN) ; break ;
		
		               /**inverse status of LED_6*/
		case LED6_ID : MDIO_voidTogPinVal(LED6_PORT , LED6_PIN) ; break ;
		
		               /**inverse status of LED_7*/
		case LED7_ID : MDIO_voidTogPinVal(LED7_PORT , LED7_PIN) ; break ;
		
		               /**inverse status of LED_8*/
		case LED8_ID : MDIO_voidTogPinVal(LED8_PORT , LED8_PIN) ; break ;
		default      : /** Error */                               break ;
	}
}
