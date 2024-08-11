#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(num,bit) ((num)|= (1u<<(bit)))
#define TOG_BIT(num,bit) ((num)^= (1u<<(bit))) 
#define CLR_BIT(num,bit) ((num)&= ~(1u<<(bit))) 
#define GET_BIT(num,bit) (((num)>>(bit))&0x01) 

#endif