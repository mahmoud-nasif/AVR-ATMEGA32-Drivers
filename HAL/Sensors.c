#include "Sensors.h"

u8 POT_VoltRead(void)
{
	u16 adc = ADC_Read(POT_CH) ;
	u16 volt = ((u32)5000*adc)/1024  ;
	return volt ;
	
}

u16 Temp_Read(void)
{
	u16 adc = ADC_Read(LM35) ; 
	u16 volt = ((u32)5000*adc)/1024  ;
	u16 temp = volt / 10 ; 
	return temp ; 
	
}