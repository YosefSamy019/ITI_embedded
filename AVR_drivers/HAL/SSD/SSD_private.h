/*
 * SSD_private.h
 *
 *  Created on: May 24, 2022
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_SSD_SSD_PRIVATE_H_
#define HAL_SSD_SSD_PRIVATE_H_

static u8 R_u8SsdData [] = {
	0x3f,    /**0*/
	0x06,    /**1*/
	0x5b,    /**2*/
	0x4f,    /**3*/
	0x66,    /**4*/
	0x6d,    /**5*/
	0x7d,    /**6*/
	0x07,    /**7*/
	0x7f,    /**8*/
	0x6f     /**9*/
} ;

/**
 * Displaying on ssd
*/
#define DISPLAY_0      0
#define DISPLAY_1      1
#define DISPLAY_2      2
#define DISPLAY_3      3
#define DISPLAY_4      4
#define DISPLAY_5      5
#define DISPLAY_6      6
#define DISPLAY_7      7
#define DISPLAY_8      8
#define DISPLAY_9      9

/**
* ID of SSD
*/
#define SSD1_ID       1
#define SSD2_ID       2

/**
* Define the type of ssd
*/
#define COMM_CATHODE  1
#define COMM_ANODE    2

/**
* Direction of SSD
*/
#define SSD_OUTPUT    1

#endif /* HAL_SSD_SSD_PRIVATE_H_ */
