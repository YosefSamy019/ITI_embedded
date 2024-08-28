/*
 * OS_program.c
 *
 * Created: 23/08/2024 04:43:04 ص
 *  Author: a24e4
 */ 
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/TIMER_0/TIMER_0_interface.h"

#include "OS_config.h"
#include "OS_interface.h"
#include "OS_private.h"

static Task G_arrTasks[OS_MAX_TASKS_NO];
static u8 G_u8TasksCounter = 0;

static void SCHEDULER_ISR(void);

void OS_void_init(void){
	MTIMER_0_voidInit();
	MTimer_0_voidSetCallback(SCHEDULER_ISR);
}

void OS_void_addTask(ptr2voidCallback function,u32 A_u32Periodicity, u32 A_u32FirstDelay){
	if(G_u8TasksCounter < OS_MAX_TASKS_NO){
		//check if task is added before
		u32 i=0;
		for(;i<G_u8TasksCounter;i++){
			if(G_arrTasks[i].function == function){
				break;
			}
		}
		
		G_arrTasks[i].function = function;
		G_arrTasks[i].periodicity = A_u32Periodicity;
		G_arrTasks[i].delay = A_u32FirstDelay;

		//increment the counter is the task is not repeated
		if(i == G_u8TasksCounter)G_u8TasksCounter++;
	}
}
void OS_void_removeTask(ptr2voidCallback A_ptrFunction){
	u32 i=0;
	
	if(G_u8TasksCounter > 0){
		for(;i<G_u8TasksCounter;i++){
			if(G_arrTasks[i].function  == A_ptrFunction){
				//remove task
				//clone last task in the array instead of task at index i then decrease tasks counter by one
				G_arrTasks[i] = G_arrTasks[G_u8TasksCounter-1];
				G_u8TasksCounter = G_u8TasksCounter - 1;
				break;
			}
		}
	}
}
void OS_void_clearAllTasks(void){
	G_u8TasksCounter = 0;
}
void OS_void_enable(void){
	MTimer_0_voidEnableClk();
}
void OS_void_disable(void){
	MTimer_0_voidDisableClk();
}


static void SCHEDULER_ISR(void){
	u8 i =0;
	for(;i<G_u8TasksCounter;i++){
		if(G_arrTasks[i].delay != 0){
			G_arrTasks[i].delay-- ;
		}else{
			G_arrTasks[i].function();
			G_arrTasks[i].delay = G_arrTasks[i].periodicity - 1;
		}
	}
}