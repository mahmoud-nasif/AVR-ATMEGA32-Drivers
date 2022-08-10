

 #define F_CPU 8000000UL
 #include <util/delay.h>


#include "Stdtyps.h"
#include "MemMap.h"
#include "Utils.h"
#include "stepper.h"
#include "DIO_Interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "ADC.h"
#include "Sensors.h"
#include "EXInterrupt.h"
void func1(void)
{
	DIO_TogglePin(PIND0) ; 
}

int main(void)
{
	//sei()  ; 
	DIO_Init() ; 
	LCD_Init(); 
	ADC_Init(VREF_VCC,ADC_Scaler_64) ;
	
	EXI_SetCallBack(EX_INT0,func1) ; 
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE)  ;
	EXI_Enable(EX_INT0) ;
	u8 x=0 ;
	
	
	
	while (1)
	{
		
		
		
		
		
	}

}


