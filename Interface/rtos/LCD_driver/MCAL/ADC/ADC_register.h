/*
 * ADC_register.h
 *
 * Created: 10/08/2024 02:36:38 م
 *  Author: a24e4
 */ 


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_




#define ADMUX_REG (*((volatile u8*)0x27))
#define ADMUX_ADLAR_BIT 5

#define ADCSRA_REG (*((volatile u8*)0x26))
#define ADCSRA_ADEN_BIT 7
#define ADCSRA_ADATE_BIT 5
#define ADCSRA_ADSC_BIT 6
#define ADCSRA_ADIF_BIT 4
#define ADCSRA_ADIE_BIT 3


#define ADCH_REG (*((volatile u8*)0x25))

#define ADCL_REG (*((volatile u8*)0x24))

#define SFIOR_REG (*((volatile u8*)0x50))


#endif /* ADC_REGISTER_H_ */