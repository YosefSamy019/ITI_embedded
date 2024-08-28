/*
 * SSD_int.h
 *
 *  Created on: May 24, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

#include "SSD_private.h"
#include "SSD_conf.h"

/**
	Function Name        : HSSD_voidSsdInitial
	Function Returns     : void
	Function Arguments   : u8 A_u8SsdId
	Function Description : make the port of SSD is output
*/
void HSSD_voidSsdInitial (u8 A_u8SsdId) ;

/**
	Function Name        : HSSD_voidSsdWrite
	Function Returns     : void
	Function Arguments   : u8 A_u8SsdId , u8 A_u8Num
	Function Description : display number at SSD
*/
void HSSD_voidSsdWrite (u8 A_u8SsdId , u8 A_u8Num) ;

/**
	Function Name        : HSSD_voidSsdOff
	Function Returns     : void
	Function Arguments   : u8 A_u8SsdId
	Function Description : turn off SSD
*/
void HSSD_voidSsdOff (u8 A_u8SsdId) ;


#endif /* HAL_SSD_SSD_INT_H_ */
