/*
 * US_program.c
 *
 * Created: 24/08/2024 09:02:24 م
 *  Author: a24e4
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/ICU/ICU_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DELAY/DELAY_interface.h"

#include "US_config.h"
#include "US_interface.h"
#include "US_private.h"

void HUS_voidInit(void){
	MICU_voidInit();
	MDIO_voidSetPinDir(HUS_TRIGGER_PIN,OUTPUT);
}

u32 HUS_u32ReadDistanceCM(void){
	u32 L_u64Distance;
	u64 L_u64Time;
		
	MDIO_voidSetPinVal(HUS_TRIGGER_PIN,HIGH);
	MDELAY_void_micro(100);
	MDIO_voidSetPinVal(HUS_TRIGGER_PIN,LOW);
	MDELAY_void_micro(100);

	L_u64Time = MICU_u64ReadTimeHighMicro();
	L_u64Distance = (L_u64Time * HUS_WAVE_SPEED * 0.5) / 10000;
	
	return L_u64Distance;
}
