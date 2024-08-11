/*
 * LCD_driver.c
 *
 * Created: 04/08/2024 08:24:43 ص
 * Author : a24e4
 */ 

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DELAY/DELAY_interface.h"

#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_patterns.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/BUTTON/BUTTON_config.h"

#include "HAL/LED/LED_config.h"
#include "HAL/LED/LED_interface.h"

#include "HAL/KEYPAD/KEYPAD_congif.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"

#define LCD_RS PinB0
#define LCD_RW PinB1
#define LCD_E  PinB2

#define MAX_SI 100

typedef struct {
	u32 L_u32data;
	u8 L_u1isNumber:1;	
	u8 L_u1ignore:1;

}CalcNode_t ;

s32 Fun_s32Calc(u8 A_u8Op,s32 A_s32Op1,s32 A_s32op2);

int main(void)
{
	HLCD_t L_lcd;
	HKEYPAD_t L_kp;
	u8 L_u8Buffer[MAX_SI];
	CalcNode_t L_CalcArr[MAX_SI];
	u8 L_u8ABufferSize=0;
	u8 L_u8CalcArrSize = 0;
	u8 L_u8Temp;
	s32 L_s32Sum=0;
	
	u8 L_u8ActiceFalg = 1;
	
	do{
		MDIO_voidInit();
		
		Pin_t dataPins[] = {PinA7,PinA6,PinA5,PinA4,PinA3,PinA2,PinA1,PinA0};
		L_lcd = HLCD_HLCD_t_LcdCreate(LCD_RS,LCD_RW,LCD_E,dataPins);
		
		HLCD_void_DisplayOn(&L_lcd);
		HLCD_void_CursorOn(&L_lcd);
		HLCD_void_CursorBlinkOn(&L_lcd);
		
		Pin_t colPins[] = {PinC4,PinC5,PinC6,PinC7};
		Pin_t rowPins[] = {PinC0,PinC1,PinC2,PinC3};
		L_kp = HKEYPAD_HKEYPAD_t_Create(rowPins,colPins);
		
	}while(0);
	
	
	
	do 
	{
		L_u8Temp = HKEYPAD_u8_getChar(&L_kp);
		
		if(L_u8ActiceFalg==0){
			if(L_u8Temp =='C'){
			HLCD_void_ClearDisplay(&L_lcd);
			HLCD_void_ReturnHome(&L_lcd);
					HLCD_void_CursorOn(&L_lcd);
					HLCD_void_CursorBlinkOn(&L_lcd);
			L_u8ABufferSize = 0;
			L_u8ActiceFalg  = 1;
			}
			
			continue;
		}
		
		
	
		
		if(L_u8ABufferSize < MAX_SI){
			if(L_u8Temp >= '0' && L_u8Temp <= '9'){
				L_u8Buffer[L_u8ABufferSize] = L_u8Temp;
				L_u8ABufferSize++;
				HLCD_void_WriteCharacter(&L_lcd,L_u8Temp);
				
			}else if(L_u8Temp == '+' || L_u8Temp == '-' || L_u8Temp =='/' || L_u8Temp == '*'){
				if(L_u8ABufferSize>0 && L_u8Buffer[L_u8ABufferSize-1] >= '0' && L_u8Buffer[L_u8ABufferSize-1] <= '9'){
					
					L_u8Buffer[L_u8ABufferSize] = L_u8Temp;
					L_u8ABufferSize++;
					HLCD_void_WriteCharacter(&L_lcd,L_u8Temp);
				}
			}
			
			
		}
		
		if(L_u8Temp == 'C'){
			HLCD_void_ClearDisplay(&L_lcd);
			HLCD_void_ReturnHome(&L_lcd);
			L_u8ABufferSize = 0;
			L_u8ActiceFalg  = 1;
		}else if(L_u8Temp == '='){
			//assemble buffer array
			L_u8CalcArrSize = 0;
			L_CalcArr[0].L_u32data = 0;
			
			for (L_u8Temp =0 ; L_u8Temp < L_u8ABufferSize ;L_u8Temp++)
			{
				if(L_u8Buffer[L_u8Temp] >= '0'
					&& L_u8Buffer[L_u8Temp] <= '9'
				){
					L_CalcArr[L_u8CalcArrSize].L_u32data = 10*L_CalcArr[L_u8CalcArrSize].L_u32data + L_u8Buffer[L_u8Temp] - '0';
					L_CalcArr[L_u8CalcArrSize].L_u1isNumber = 1;
				}else if (L_u8Buffer[L_u8Temp] == '+' || L_u8Buffer[L_u8Temp] == '-' || L_u8Buffer[L_u8Temp] =='/' || L_u8Buffer[L_u8Temp] == '*'){
					L_u8CalcArrSize++;
					
					L_CalcArr[L_u8CalcArrSize].L_u32data = L_u8Buffer[L_u8Temp];
					L_CalcArr[L_u8CalcArrSize].L_u1isNumber = 0;
					
					L_u8CalcArrSize++;
					L_CalcArr[L_u8CalcArrSize].L_u32data = 0;
				}
			}
			
		/*				HLCD_void_setCursor(&L_lcd,0,1);

			HLCD_void_WriteNumber(&L_lcd,L_CalcArr[0].L_u32data);
			HLCD_void_WriteCharacter(&L_lcd,' ');
			
			HLCD_void_WriteNumber(&L_lcd,L_CalcArr[1].L_u32data);
			HLCD_void_WriteCharacter(&L_lcd,' ');		
				
			HLCD_void_WriteNumber(&L_lcd,L_CalcArr[2].L_u32data);
			HLCD_void_WriteCharacter(&L_lcd,' ');			
			
			continue;*/
			
			//calculate buffer array
			L_s32Sum = L_CalcArr[0].L_u32data;
			for (L_u8Temp =1 ; L_u8Temp < L_u8CalcArrSize ;L_u8Temp++)
			{
				if(L_CalcArr[L_u8Temp].L_u1isNumber){
					
				}else {
					L_s32Sum = Fun_s32Calc(L_CalcArr[L_u8Temp].L_u32data,L_s32Sum,L_CalcArr[L_u8Temp+1].L_u32data);
					L_CalcArr[L_u8Temp].L_u1ignore = 1;
					L_CalcArr[L_u8Temp+1].L_u1ignore = 1;
					L_u8Temp+=1;

				}
				
			}
			
			HLCD_void_setCursor(&L_lcd,0,1);
			HLCD_void_WriteNumber(&L_lcd,L_s32Sum);
			HLCD_void_CursorOff(&L_lcd);
			HLCD_void_CursorBlinkOff(&L_lcd);
			L_u8ActiceFalg =0;
			
		}
		
		
		
	} while (1);
}



s32 Fun_s32Calc(u8 A_u8Op,s32 A_s32Op1,s32 A_s32op2){
	s32 L_s32Ret = 0;
	switch(A_u8Op){
		case '+':  L_s32Ret = A_s32Op1 + A_s32op2; break;
		case '-':  L_s32Ret = A_s32Op1 - A_s32op2; break;
		case '*':  L_s32Ret = A_s32Op1 * A_s32op2; break;
		case '/':  L_s32Ret = A_s32Op1 / A_s32op2; break;
	}
	
	return L_s32Ret;
}