/*
 * SPI_conf.h
 *
 *  Created on: Aug 2, 2022
 *      Author: mohammed ramadan
 */

#ifndef MCAL_SPI_SPI_CONF_H_
#define MCAL_SPI_SPI_CONF_H_

/** select mode of SPI
  ** Options
      **SPI_MASTER
	  **SPI_SLAVE
 */
#define  SPI_MODE SPI_MASTER

/** select SPI clock rate
  ** Options
      **PRESCALLER_2  
	  **PRESCALLER_16 
	  **PRESCALLER_64 
	  **PRESCALLER_128
	  **PRESCALLER_2  
	  **PRESCALLER_8  
	  **PRESCALLER_32 
 */
#define SPI_CLOCK_RATE  PRESCALLER_16

#endif /* MCAL_SPI_SPI_CONF_H_ */