/*
 * ecu_2.c
 *
 * Created: 23/08/2024 10:30:07 م
 * Author : a24e4
 */ 

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/DELAY/DELAY_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GI/GI_interface.h"
#include "MCAL/ICU/ICU_interface.h"
#include "MCAL/TIMER_2/TIMER_2_interface.h"
#include "MCAL/UART/UART_interface.h"

#include "HAL/BUTTON/BUTTON_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/LED/LED_interface.h"
#include "HAL/BUZZER/BUZZER_interface.h"
#include "HAL/US/US_interface.h"

#define POWER_CHAR  'A'

#define ABS(a) ( (a)>0 ? (a) : -1*(a) )
 
enum {sysOn,sysOff}							G_ESystemPower;
enum {gearD,gearN,gearP,gearR}				G_EGearBox;
enum {BAS_ON,BAS_OFF}						G_EBAS;
enum {SL_ON,SL_OFF}							G_ESL;
enum {CCS_ON,CCS_OFF}						G_ECCS;
enum {DRIVE_MONITOR_ON,DRIVE_MONITOR_OFF}	G_EDRIVE_MONITOR;

HLed_t G_ledBAS, G_ledSL, G_ledCCS;
HLCD_t G_lcd;
HBUTTON_t G_buttonSL, G_buttonCSS, G_buttonGearBox;
HBUZZER_t G_alarm; 

u64 G_u64MillisCounter = 0;
u8 G_u8GasDutyCycle = 0; //0 --> 100
u64 G_U64MillmetersCounter = 0;

u64 G_u64TimeSnappedWhenLastChange = 0;

u32 G_u32US_Distance;

void App_voidInit();
void App_checkInput();
void App_voidUpdate();
void App_LCD();
void UART_onReceive(u32);
void Timer2_callback();

int main(void)
{
   App_voidInit();
  // UART_onReceive('A');

   while(1) 
   {
	   
	 
	   if(G_ESystemPower == sysOn){
		    App_checkInput();
			App_voidUpdate();
			App_LCD();
	   }
   }
}

void App_voidInit(){
	//init vars
	G_ESystemPower = sysOff;
	G_EGearBox = gearN;
	G_EBAS = BAS_OFF;
	G_ESL = SL_OFF;
	G_ECCS = CCS_OFF;
	G_EDRIVE_MONITOR = DRIVE_MONITOR_OFF;
	
	//init peripherals
	MDIO_voidInit();
	MADC_voidInit();
	MUART_voidInit();
	MTIMER_2_voidInit();
	MUART_voidSetRXCallback(UART_onReceive);
	MTIMER_2_voidSetCallback(Timer2_callback);
	
	HUS_voidInit();
	
	
	//init var
	G_ledBAS = HLED_HLed_t_Create(PinD3,HLED_ActiveHigh);
	G_ledSL = HLED_HLed_t_Create(PinC2,HLED_ActiveHigh);
	G_ledCCS = HLED_HLed_t_Create(PinC7,HLED_ActiveHigh);
	
	Pin_t L_arrLcdDataPins[] ={PinA7,PinA6,PinA5,PinA4,PinC3,PinC5,PinC1,PinC0};
	G_lcd = HLCD_HLCD_t_LcdCreate(PinB1,PinB2,PinB3,L_arrLcdDataPins);

	G_buttonSL = HBUTTON_HBUTTON_t_Create(PinB0,HBUTTON_inputInternalPullUp);
	G_buttonCSS = HBUTTON_HBUTTON_t_Create(PinD5,HBUTTON_inputInternalPullUp);
	G_buttonGearBox = HBUTTON_HBUTTON_t_Create(PinD2,HBUTTON_inputInternalPullUp);

	G_alarm = HBUZZER_HBUZZER_t_Create(PinA3,HBUZZER_ActiveHigh);

	HLCD_void_DisplayOn(&G_lcd);


	//enable GI
	MGI_void_Enable();
}

void App_checkInput(){
	u32 L_u32Temp;
	
	//------ SL -------
	static u8 L_SL_Old, L_SL_New;
	
	L_SL_New = HBUTTON_HBUTTON_state_t_getButtonState(&G_buttonSL);
	if(L_SL_New == HBUTTON_pressed && L_SL_Old == HBUTTON_free){
		G_u64TimeSnappedWhenLastChange = G_u64MillisCounter;
		if(G_ESL == SL_ON){
			G_ESL = SL_OFF;
		}else if(G_EGearBox == gearD){
			G_ESL = SL_ON;
		}else{
			G_ESL = SL_OFF;
		}
	}
	L_SL_Old = L_SL_New;
	//-------------------------
	
	//------ CCS -------
	static u8 L_CCS_Old, L_CCS_New;
	
	L_CCS_New = HBUTTON_HBUTTON_state_t_getButtonState(&G_buttonCSS);
	if(L_CCS_New == HBUTTON_pressed && L_CCS_Old == HBUTTON_free){
		G_u64TimeSnappedWhenLastChange = G_u64MillisCounter;
		if(G_ECCS == CCS_ON){
			G_ECCS = CCS_OFF;
		}else if(G_EGearBox == gearD){
			G_ECCS = CCS_ON;
		}else{
			G_ECCS = CCS_OFF;
		}
	}
	L_CCS_Old = L_CCS_New;
	//-------------------------
	
	//------ GEAR BOX -------
	
	static u8 L_GearBox_Old, L_GearBox_New;
	
	L_GearBox_New = HBUTTON_HBUTTON_state_t_getButtonState(&G_buttonGearBox);
	if(L_GearBox_New == HBUTTON_pressed && L_GearBox_Old == HBUTTON_free){
		G_u64TimeSnappedWhenLastChange = G_u64MillisCounter;
		switch(G_EGearBox){
			case gearN: G_EGearBox = gearD; break;
			case gearD: G_EGearBox = gearP; break;
			case gearP: G_EGearBox = gearR; break;
			case gearR: G_EGearBox = gearN; break;
		}
			
	}
	L_GearBox_Old = L_GearBox_New;
	
	//-------------------------

	
	//------- Gas Pot ---------
	static L_u32GasDCOld =  0;
	G_u8GasDutyCycle = (MADC_u32ReadVoltage(MADC_SINGLE_CHANNEL_1) * 100 / 1023);
	
	if((G_u64MillisCounter / 500) % 2){
		L_u32Temp = ABS(G_u8GasDutyCycle - L_u32GasDCOld);
		//if change is > 10%, so the ADC is changed
		if(L_u32Temp > 5){
			G_u64TimeSnappedWhenLastChange = G_u64MillisCounter;
			G_ECCS = CCS_OFF;
		}
		L_u32GasDCOld = G_u8GasDutyCycle;
	}
	/// todo dont forget drive monitier G_u64TimeSnappedWhenLastChange = G_U64MillmetersCounter;

	
	//-------------------------
		
}

void App_voidUpdate(){
	u32 L_u32Temp,L_u64Temp;
	
	//----- US ---------
	G_u32US_Distance = HUS_u32ReadDistanceCM();
	//------------------

	
	//----- BAS --------
	if(G_EGearBox == gearD){
		G_EBAS = BAS_ON;
		
		if(G_u32US_Distance > 10){
			HLED_void_TurnOff(&G_ledBAS);
		}else if(L_u32Temp > 5){
			//toggle each 100ms
			if( (G_u64MillisCounter/100)%2 ){
				HLED_void_TurnOff(&G_ledBAS);
			}else{
				HLED_void_TurnOn(&G_ledBAS);
			}
		}else{
			HLED_void_TurnOn(&G_ledBAS);
		}
		
	}else{
		G_EBAS = BAS_OFF;
		HLED_void_TurnOff(&G_ledBAS);
	}
	
	//------------------
	
	
	//----- SL --------
	if (G_ESL == SL_ON){
		HLED_void_TurnOn(&G_ledSL);
	}else{
		HLED_void_TurnOff(&G_ledSL);
	}
	if(G_EGearBox != gearD){
		G_ESL = SL_OFF;
	}
	//------------------
	
	
	//----- CCS --------
	if (G_ECCS == CCS_ON){
		HLED_void_TurnOn(&G_ledCCS);
	}else{
		HLED_void_TurnOff(&G_ledCCS);
	}
	
	if(G_EGearBox != gearD){
		G_ECCS = CCS_OFF;
	}
	//------------------

	//----- Drive Monitor --------
	if (G_EGearBox == gearD){
		G_EDRIVE_MONITOR = DRIVE_MONITOR_ON;
	}else{
		G_EDRIVE_MONITOR = DRIVE_MONITOR_OFF;
	}
	
	if(G_EDRIVE_MONITOR == DRIVE_MONITOR_ON){
		if(G_u64MillisCounter > G_u64TimeSnappedWhenLastChange){
			L_u64Temp = G_u64MillisCounter - G_u64TimeSnappedWhenLastChange;
			if(L_u64Temp > 5000){
				//alarm enable
				if((L_u64Temp / 100 ) % 2 ){
					HBUZZER_void_TurnOn(&G_alarm);
				}else{
					HBUZZER_void_TurnOff(&G_alarm);
				}
				
			}else{
				//alarm off
				HBUZZER_void_TurnOff(&G_alarm);
			}
		}else {
			HBUZZER_void_TurnOff(&G_alarm);
		}
	}else{
		HBUZZER_void_TurnOff(&G_alarm);
	}
	//-----------------------------

}

void App_LCD(){
	HLCD_void_setCursor(&G_lcd,0,0);
	HLCD_void_WriteString(&G_lcd,"BAS:");
	if(G_EBAS == BAS_ON){
		HLCD_void_WriteString(&G_lcd," ON");
	}else{
		HLCD_void_WriteString(&G_lcd,"OFF");
	}
	
	HLCD_void_WriteString(&G_lcd," ");
	
	HLCD_void_WriteString(&G_lcd,"SL:");
	if(G_ESL == SL_ON){
		HLCD_void_WriteString(&G_lcd," ON");
	}else{
		HLCD_void_WriteString(&G_lcd,"OFF");
	}
	
	HLCD_void_WriteString(&G_lcd," ");
	
	switch(G_EGearBox){
		case gearD: HLCD_void_WriteCharacter(&G_lcd,'D'); break;
		case gearN: HLCD_void_WriteCharacter(&G_lcd,'N'); break;
		case gearP: HLCD_void_WriteCharacter(&G_lcd,'P'); break;
		case gearR: HLCD_void_WriteCharacter(&G_lcd,'R'); break;
	}
	
	HLCD_void_setCursor(&G_lcd,0,1);
	
	HLCD_void_WriteString(&G_lcd,"CCS:");
	if(G_ECCS == CCS_ON){
		HLCD_void_WriteString(&G_lcd," ON");
	}else{
		HLCD_void_WriteString(&G_lcd,"OFF");
	}
	HLCD_void_WriteString(&G_lcd," ");
	
	if( (G_u64MillisCounter  / 1000) % 2){
		HLCD_void_WriteString(&G_lcd,"KM:");
		HLCD_void_WriteNumber(&G_lcd,G_U64MillmetersCounter/ 10000);
	}else{
		HLCD_void_WriteString(&G_lcd,"US:");
		HLCD_void_WriteNumber(&G_lcd,G_u32US_Distance);
	}
	
	HLCD_void_WriteString(&G_lcd,"     ");
	
	

}

void UART_onReceive(u32 A_u32Data){
	if(A_u32Data == POWER_CHAR){
		G_ESystemPower = sysOn;
	}
}

void Timer2_callback(){
	G_u64MillisCounter++;
	
	if(G_ESystemPower == sysOn){
		G_U64MillmetersCounter = G_U64MillmetersCounter + G_u8GasDutyCycle;
	}
}