/*
 * SSD_prog.c
 *
 *  Created on: May 18, 2022
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SSD_int.h"

void HSSD_voidSsdInitial (u8 A_u8SsdId)
{
	switch (A_u8SsdId)
	{
		               /** set direction of common pin of ssd1 as output */
		case SSD1_ID : MDIO_voidSetPinDir  (SSD1EN_PORT , SSD1EN_PIN , SSD_OUTPUT) ; 
		
		               /** set direction of data pins of ssd1 as output */
		               MDIO_voidSetPortDir (SSD1_PORT , ALL_PINS_ONE) ;               break ;
					   
					   /** set direction of common pin of ssd2 as output */
		case SSD2_ID : MDIO_voidSetPinDir  (SSD2EN_PORT , SSD2EN_PIN , SSD_OUTPUT) ;
		
		               /** set direction of data pins of ssd2 as output */
					   MDIO_voidSetPortDir (SSD2_PORT , ALL_PINS_ONE) ;               break ;
		default      : /** Error */                                                   break ;
	}
}

void HSSD_voidSsdWrite (u8 A_u8SsdId , u8 A_u8Num)
{
	#if SSD_TYPE == COMM_CATHODE	 /// if type of ssd is common cathod
		if (A_u8Num > 9)
		{
			/**
			* error case and the defualt display is zero
			*/
			switch (A_u8SsdId)
			{                  /**make the common pin of ssd1 is low (turn on ssd1) */
				case SSD1_ID : MDIO_voidClrPinVal  (SSD1EN_PORT , SSD1EN_PIN) ;
				
				               /**Display number 0 (first element of data array) */
				               MDIO_voidSetPortVal (SSD1_PORT , R_u8SsdData [DISPLAY_0]) ; 
						       break ;
							   
							   /**make the common pin of ssd2 is low (turn on ssd2) */
				case SSD2_ID : MDIO_voidClrPinVal  (SSD2EN_PORT , SSD2EN_PIN) ;
				
				               /**Display number 0 (first element of data array) */
				               MDIO_voidSetPortVal (SSD2_PORT , R_u8SsdData [DISPLAY_0]) ;    
				               break ;
				default      : /** Error */                                                   
				               break ;
			}
		}
		else 
		{
			switch (A_u8SsdId)
			{
				               /**make the common pin of ssd1 is low (turn on ssd1) */
				case SSD1_ID : MDIO_voidClrPinVal  (SSD1EN_PORT , SSD1EN_PIN) ;
				
				               /**Display number*/
				               MDIO_voidSetPortVal (SSD1_PORT   , R_u8SsdData [A_u8Num]) ;   
							   break ;
							   
							   /**make the common pin of ssd2 is low (turn on ssd2) */
				case SSD2_ID : MDIO_voidClrPinVal  (SSD2EN_PORT , SSD2EN_PIN) ;
				
				               /**Display number*/
				               MDIO_voidSetPortVal (SSD2_PORT   , R_u8SsdData [A_u8Num]) ;   
				               break ;
				default      : /** Error */                                                   break ;
			}
		}							
	#elif SSD_TYPE == COMM_ANODE      /// if type of ssd is common andoe
		if (A_u8Num > DISPLAY_9)
		{
			/**
			* error case and the defualt display is zero
			*/
			switch (A_u8SsdId)
			{                  /**make the common pin of ssd1 is high (turn on ssd1) */
				case SSD1_ID : MDIO_voidSetPinVal  (SSD1EN_PORT , SSD1EN_PIN) ;
				
				               /**Display number 0 (first element of data array) */
				               MDIO_voidSetPortVal (SSD1_PORT , ~R_u8SsdData [DISPLAY_0]) ;     
							   break ;
							   
							   /**make the common pin of ssd2 is high (turn on ssd2) */
				case SSD2_ID : MDIO_voidSetPinVal  (SSD2EN_PORT , SSD2EN_PIN) ;
				
				               /**Display number 0 (first element of data array) */
				               MDIO_voidSetPortVal (SSD2_PORT , ~R_u8SsdData [DISPLAY_0]) ;     
							   break ;
				default      : /** Error */                                                      
				               break ;
			}
		}
		else 
		{
			switch (A_u8SsdId)
			{                  /**make the common pin of ssd1 is high (turn on ssd1) */
				case SSD1_ID : MDIO_voidSetPinVal  (SSD1EN_PORT , SSD1EN_PIN) ;
				
				               /**Display number*/
				               MDIO_voidSetPortVal (SSD1_PORT , ~R_u8SsdData [A_u8Num]) ;  
						       break ;
							   
							   /**make the common pin of ssd2 is high (turn on ssd2) */
				case SSD2_ID : MDIO_voidSetPinVal  (SSD2EN_PORT , SSD2EN_PIN) ;
				
				               /**Display number*/
				               MDIO_voidSetPortVal (SSD2_PORT , ~R_u8SsdData [A_u8Num]) ;  
						       break ;
				default      : /** Error */                                               
				               break ;
			}
		}
	#else 
		#error "select correct type of ssd"
	#endif
}

void HSSD_voidSsdOff (u8 A_u8SsdId)
{
	#if SSD_TYPE == COMM_CATHODE	 /// if type of ssd is common cathod
	    switch (A_u8SsdId)
	    {                   /**make the common pin of ssd1 is high (turn off ssd1) */
			 case SSD1_ID : MDIO_voidSetPinVal (SSD1_PORT , SSD1EN_PIN) ;      break ;
			 
							/**make the common pin of ssd2 is high (turn off ssd2) */
	    	 case SSD2_ID : MDIO_voidSetPinVal (SSD2_PORT , SSD2EN_PIN) ;      break ;
	    	 default      : /** Error */                                       break ;
	    }
	#elif SSD_TYPE == COMM_ANODE   /// if type of ssd is common anode
	    switch (A_u8SsdId)
	    {
			               /**make the common pin of ssd1 is low (turn off ssd1) */
	    	case SSD1_ID : MDIO_voidClrPinVal (SSD1_PORT , SSD1EN_PIN) ;      break ;
			
			               /**make the common pin of ssd2 is low (turn off ssd2) */
	    	case SSD2_ID : MDIO_voidClrPinVal (SSD2_PORT , SSD2EN_PIN) ;      break ;
	        default      : /** Error */                                       break ;                                                 
	    }
	#else 
		#error "select correct type of ssd"
	#endif	
}