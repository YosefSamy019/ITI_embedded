/*
 * BUZZER_prog.c
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "BUZZER_int.h"
#include "BUZZER_private.h"
#include "BUZZER_conf.h"

void HBUZZER_voidBUZZERInitial (void)
{
	/** select direction of buzzer as output */
    MDIO_voidSetPinDir(BUZZER_PORT , BUZZER_PIN , BUZZER_OUTPUT) ; 
}

void HBUZZER_voidBUZZEROn (void)
{
	/**make buzzer on (it's pin is high)*/
	MDIO_voidSetPinVal(BUZZER_PORT , BUZZER_PIN) ; 
}

void HBUZZER_voidBUZZEROff (void)
{
	/**make buzzer off (it's pin is low)*/
	MDIO_voidClrPinVal(BUZZER_PORT , BUZZER_PIN) ; 
}

void HBUZZER_voidBUZZERToggle (void)
{
	/**inverse the status of buzzer*/
	MDIO_voidTogPinVal(BUZZER_PORT , BUZZER_PIN) ; 
}
