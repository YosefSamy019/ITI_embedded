/*
 * OS_private.h
 *
 * Created: 23/08/2024 04:43:27 ص
 *  Author: a24e4
 */ 


#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_

typedef struct {
	ptr2voidCallback function;
	u32 periodicity;
	u32 delay;
}Task;



#endif /* OS_PRIVATE_H_ */