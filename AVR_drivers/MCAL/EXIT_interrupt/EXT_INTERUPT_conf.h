/*
 * EXT_INTERUPT_conf.h
 *
 *  Created on: Jun 2, 2022
 *      Author: Mohamed Ramadan
 */

#ifndef MCAL_EXT_INTERUPT_EXT_INTERUPT_CONF_H_
#define MCAL_EXT_INTERUPT_EXT_INTERUPT_CONF_H_

/** Options 
    *ENABLE
    *DISABLE
 */
#define MEXTI0  ENABLE
#define MEXTI1  DISABLE
#define MEXTI2  DISABLE

/** Options of EXTI0_SENCE
    *LOW_LEVEL	
    *ON_CHANGE	
    *FALLING_EDG
    *RISING_EDGE
 */
#define EXTI0_SENCE  FALLING_EDGE

/** Options of EXTI1_SENCE
    *LOW_LEVEL	
    *ON_CHANGE	
    *FALLING_EDG
    *RISING_EDGE
 */
#define EXTI1_SENCE  FALLING_EDGE

/** Options of EXTI2_SENCE	
    *FALLING_EDG
    *RISING_EDGE
 */
#define EXTI2_SENCE  FALLING_EDGE


#endif /*MCAL_EXT_INTERUPT_EXT_INTERUPT_CONF_H_*/