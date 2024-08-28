/*
 * EXT_INT_0_program.c
 *
 * Created: 10/08/2024 10:32:03 ص
 *  Author: a24e4
 */ 


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "EXT_INT_config.h"
#include "EXT_INT_interface.h"
#include "EXT_INT_private.h"
#include "EXT_INT_register.h"


static ptr2voidCallback G_ptr2voidCallback_INT_0_callBack = NULL;
static ptr2voidCallback G_ptr2voidCallback_INT_1_callBack = NULL;
static ptr2voidCallback G_ptr2voidCallback_INT_2_callBack = NULL;

void MEXT_INT_0_voidInit(void){
	#if MEXT_INT_0_INPUT_DIRECTION == MEXT_INT_PIN_INPUT
		MDIO_voidSetPinDir(MEXT_INT_0_PIN,INPUT);
	#else
		MDIO_voidSetPinDir(MEXT_INT_0_PIN,INPUT_PULL_UP);
	#endif
}
	
void MEXT_INT_0_voidEnable(void){
	SET_BIT(GICR_REG,GICR_INT0_BIT);
}
	
void MEXT_INT_0_voidDisable(void){
	CLR_BIT(GICR_REG,GICR_INT0_BIT);
}
	
void MEXT_INT_0_voidSenseControl(MEXT_INT_0_Sense_Control_t A_MEXT_INT_0_Sense_Control_t_control){
	switch(A_MEXT_INT_0_Sense_Control_t_control){
		case MEXT_INT_0_Sense_LowLevel: 
			CLR_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
			CLR_BIT(MCUCR_REG,MCUCR_ISC01_BIT);
			break;

		case MEXT_INT_0_Sense_AnyChange:
			SET_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
			CLR_BIT(MCUCR_REG,MCUCR_ISC01_BIT);			
			break;

		case MEXT_INT_0_Sense_FallingEdge:
			CLR_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
			SET_BIT(MCUCR_REG,MCUCR_ISC01_BIT);
			break;

		case MEXT_INT_0_Sense_RisingEdge:
			SET_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
			SET_BIT(MCUCR_REG,MCUCR_ISC01_BIT);
			break;	
	}
}

void MEXT_INT_0_voidSetCallback( ptr2voidCallback A_ptr2voidCallback_callBack ){
	G_ptr2voidCallback_INT_0_callBack = A_ptr2voidCallback_callBack;
}


	
	
	

void MEXT_INT_1_voidInit(void){
		#if MEXT_INT_1_INPUT_DIRECTION == MEXT_INT_PIN_INPUT
			MDIO_voidSetPinDir(MEXT_INT_1_PIN,INPUT);
		#else
			MDIO_voidSetPinDir(MEXT_INT_1_PIN,INPUT_PULL_UP);
		#endif
}
void MEXT_INT_1_voidEnable(void){
		SET_BIT(GICR_REG,GICR_INT1_BIT);
}
void MEXT_INT_1_voidDisable(void){
		CLR_BIT(GICR_REG,GICR_INT1_BIT);
}
void MEXT_INT_1_voidSenseControl(MEXT_INT_1_Sense_Control_t A_MEXT_INT_1_Sense_Control_t_control){
	switch(A_MEXT_INT_1_Sense_Control_t_control){
		case MEXT_INT_1_Sense_LowLevel:
		CLR_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
		CLR_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
		break;

		case MEXT_INT_1_Sense_AnyChange:
		SET_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
		CLR_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
		break;

		case MEXT_INT_1_Sense_FallingEdge:
		CLR_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
		SET_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
		break;

		case MEXT_INT_1_Sense_RisingEdge:
		SET_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
		SET_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
		break;
	}
}

void MEXT_INT_1_voidSetCallback( ptr2voidCallback A_ptr2voidCallback_callBack ){
		G_ptr2voidCallback_INT_1_callBack = A_ptr2voidCallback_callBack;
}




void MEXT_INT_2_voidInit(void){
	#if MEXT_INT_2_INPUT_DIRECTION == MEXT_INT_PIN_INPUT
	MDIO_voidSetPinDir(MEXT_INT_2_PIN,INPUT);
	#else
	MDIO_voidSetPinDir(MEXT_INT_2_PIN,INPUT_PULL_UP);
	#endif	
}

void MEXT_INT_2_voidEnable(void){
		SET_BIT(GICR_REG,GICR_INT2_BIT);
}

void MEXT_INT_2_voidDisable(void){
		CLR_BIT(GICR_REG,GICR_INT2_BIT);
}

void MEXT_INT_2_voidSenseControl(MEXT_INT_2_Sense_Control_t A_MEXT_INT_2_Sense_Control_t_control){
	switch(A_MEXT_INT_2_Sense_Control_t_control){
		case MEXT_INT_2_Sense_FallingEdge:
		CLR_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);
		break;

		case MEXT_INT_2_Sense_RisingEdge:
		SET_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);
		break;
	}
}

void MEXT_INT_2_voidSetCallback( ptr2voidCallback A_ptr2voidCallback_callBack ){
			G_ptr2voidCallback_INT_2_callBack = A_ptr2voidCallback_callBack;

}









void __vector_1 (void) __attribute__ ((signal,used, externally_visible));
void __vector_1 (void){
	if(G_ptr2voidCallback_INT_0_callBack != NULL){
		G_ptr2voidCallback_INT_0_callBack();
	}
}


void __vector_2 (void) __attribute__ ((signal,used, externally_visible));
void __vector_2 (void){
	if(G_ptr2voidCallback_INT_1_callBack != NULL){
		G_ptr2voidCallback_INT_1_callBack();
	}
}


void __vector_3 (void) __attribute__ ((signal,used, externally_visible));
void __vector_3 (void){
	if(G_ptr2voidCallback_INT_2_callBack != NULL){
		G_ptr2voidCallback_INT_2_callBack();
	}
}