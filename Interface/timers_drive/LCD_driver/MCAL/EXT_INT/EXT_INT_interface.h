/*
 * EXT_INT_interface.h
 *
 * Created: 10/08/2024 10:32:14 ص
 *  Author: a24e4
 */ 


#ifndef EXT_INT_INTERFACE_H_
#define EXT_INT_INTERFACE_H_

typedef enum{
	MEXT_INT_0_Sense_LowLevel,
	MEXT_INT_0_Sense_AnyChange,
	MEXT_INT_0_Sense_FallingEdge,
	MEXT_INT_0_Sense_RisingEdge
}MEXT_INT_0_Sense_Control_t ;


typedef enum{
	MEXT_INT_1_Sense_LowLevel,
	MEXT_INT_1_Sense_AnyChange,
	MEXT_INT_1_Sense_FallingEdge,
	MEXT_INT_1_Sense_RisingEdge
}MEXT_INT_1_Sense_Control_t ;

typedef enum{
	MEXT_INT_2_Sense_FallingEdge,
	MEXT_INT_2_Sense_RisingEdge
}MEXT_INT_2_Sense_Control_t ;


void MEXT_INT_0_voidInit(void);
void MEXT_INT_0_voidEnable(void);
void MEXT_INT_0_voidDisable(void);
void MEXT_INT_0_voidSenseControl(MEXT_INT_0_Sense_Control_t A_MEXT_INT_0_Sense_Control_t_control);
void MEXT_INT_0_voidSetCallback( ptr2voidCallback A_ptr2voidCallback_callBack );


void MEXT_INT_1_voidInit(void);
void MEXT_INT_1_voidEnable(void);
void MEXT_INT_1_voidDisable(void);
void MEXT_INT_1_voidSenseControl(MEXT_INT_1_Sense_Control_t A_MEXT_INT_1_Sense_Control_t_control);
void MEXT_INT_1_voidSetCallback( ptr2voidCallback A_ptr2voidCallback_callBack );


void MEXT_INT_2_voidInit(void);
void MEXT_INT_2_voidEnable(void);
void MEXT_INT_2_voidDisable(void);
void MEXT_INT_2_voidSenseControl(MEXT_INT_2_Sense_Control_t A_MEXT_INT_2_Sense_Control_t_control);
void MEXT_INT_2_voidSetCallback( ptr2voidCallback A_ptr2voidCallback_callBack );



#endif /* EXT_INT_INTERFACE_H_ */