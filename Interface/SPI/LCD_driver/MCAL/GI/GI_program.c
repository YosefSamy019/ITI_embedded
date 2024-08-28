/*
 * GI_program.c
 *
 * Created: 10/08/2024 10:25:22 ص
 *  Author: a24e4
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GI_register.h"
#include "GI_config.h"
#include "GI_interface.h"
#include "GI_private.h"

void MGI_void_Enable(void){
	SET_BIT(SREG_REG,SREG_I_BIT);	
}

void MGI_void_Disable(void){
	CLR_BIT(SREG_REG,SREG_I_BIT);
}