/*
 * Math.h
 *
 * Created: 20/02/2024 23:20:08
 *  Author: PC
 */ 


#ifndef MATH_H_
#define MATH_H_
#define SET_BIT(PORT,BIT)  (PORT|=(1<<BIT))
#define CLR_BIT(PORT,BIT)  (PORT&=~(1<<BIT))
#define TOGGLE_BIT(PORT,BIT)  (PORT^=(1<<BIT))
#define GET_BIT(PIN,BIT) ((PIN>>BIT)&0X01)

#endif /* MATH_H_ */