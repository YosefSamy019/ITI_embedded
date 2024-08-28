/*
 * ICU_interface.h
 *
 * Created: 13/08/2024 09:42:06 ص
 *  Author: a24e4
 */ 


#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

void MICU_voidInit(void);

u64 MICU_u64ReadTimeHighMicro(void);

u64 MICU_u64ReadTimeLowMicro(void);

//0 --> 100
u8 MICU_u8ReadDutyCycle(void);


#endif /* ICU_INTERFACE_H_ */