/*

 * main.c
 *
 *  Created on: Aug 23, 2024
 *      Author: Mahmoud Osman
 */

#include "MCAL/DIO/DIO_int.h"
#include "MCAL/DIO2/DIO/DIO.h"
#include "util/delay.h"
#include "HAL/KEY_PAD/KP_int.h"
#include "HAL/LCD/LCD_int.h"
#include "MCAL/UART/UART_int.h"
#include "MCAL/EEPROM/EEPROM.h"
#include "HAL/Servo_motor/Servo_int.h"
u8 password[4]={'1','2','3','4'};
u8 User_Password[50];
u8 i=0,flag1=0;
u8 flag2=0;
u8 flag3=0;
u8 key;
int main(){
	EEPROM_writeByte (0x21 ,'1') ;
	EEPROM_writeByte (0x22 ,'2') ;
	EEPROM_writeByte (0x23 ,'3') ;
	EEPROM_writeByte (0x24 ,'4') ;
	HLCD_voidInit();
	HKP_voidKpInt();
	MUART_voidInit();
	//LEDS

	DIO_PinMode(PC_0,OUTPUT);
	DIO_PinMode(PC_1,OUTPUT);

	HSevo_voidMoveTO(0);

	while(1){
		key=HKP_u8GetPressedKey();
		if(key!=255 && flag1==0){
			HLCD_voidSendData(key);
			if(key!='=')
			{
			User_Password[i]=key;
			HLCD_voidSendData(User_Password[i]);
			i++;
			}
			else {
				flag1=1;
				i=0;
			}
		}
		//start check
		if(flag1==1){
			for(int i=0;i<4;i++){
				if(User_Password[i]!=EEPROM_readByte(0x21+i))
				{
					flag2=1;
				}
			}
		}
		if(flag1==1 && flag3==0){
		if(flag2==0){
			DIO_digitalWrite(PC_0,HIGH);
			DIO_digitalWrite(PC_1,LOW);
			_delay_ms(700);
			DIO_digitalWrite(PC_0,LOW);
			DIO_digitalWrite(PC_1,LOW);
			MUART_voidSendData('A');
			HSevo_voidMoveTO(90);
			_delay_ms(1000);
			HSevo_voidMoveTO(0);
		}
		else{
			DIO_digitalWrite(PC_0,LOW);
			DIO_digitalWrite(PC_1,HIGH);
			_delay_ms(700);
			DIO_digitalWrite(PC_0,LOW);
			DIO_digitalWrite(PC_1,LOW);
			MUART_voidSendData('G');
		}
		flag2=0;
		flag1=0;
		flag3=0;
		}


}
}

