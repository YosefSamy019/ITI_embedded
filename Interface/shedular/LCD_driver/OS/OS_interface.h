/*
 * OS_interface.h
 *
 * Created: 23/08/2024 04:43:17 ص
 *  Author: a24e4
 */ 


#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_


void OS_void_init(void);
void OS_void_addTask(ptr2voidCallback function,u32 A_u32Periodicity, u32 A_u32FirstDelay);
void OS_void_removeTask(ptr2voidCallback A_ptrFunction);
void OS_void_clearAllTasks(void);
void OS_void_enable(void);
void OS_void_disable(void);


#endif /* OS_INTERFACE_H_ */