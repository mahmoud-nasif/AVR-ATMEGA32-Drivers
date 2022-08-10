#include "ADC.h"

static u8 flag=0 ; 


void ADC_Init(ADC_Vref_Type vref , ADC_Scaler_Type scaler)
{
	switch(vref)
	{
		case VREF_VCC :
		SET_BIT(ADMUX,REFS0) ; 
		CLEAR_BIT(ADMUX,REFS1);
		break ; 
		
		case VREF_AREF :
		CLEAR_BIT(ADMUX,REFS0) ;
		CLEAR_BIT(ADMUX,REFS1);
		break ;
		
		case VREF_V256 :
		SET_BIT(ADMUX,REFS0) ;
		SET_BIT(ADMUX,REFS1);
		break ;
			
	}
	
	ADCSRA =ADCSRA & 0xF8  ;
	scaler =scaler & 0x07 ;
	ADCSRA =ADCSRA | scaler ; 
	
	

	SET_BIT(ADCSRA,ADEN) ; 
	
	
	
}


u16 ADC_Read(ADC_CH_Type ch)
{
	//select ch 
	ADMUX=ADMUX & 0XE0 ; 
	ADMUX=ADMUX |ch    ;
	
	//start conversion
	SET_BIT(ADCSRA,ADSC) ; 
	while(READ_BIT(ADCSRA,ADSC))   ;
	return ADC  ;
	
	 
}

void ADC_StartConversion(ADC_CH_Type ch)
{
	if(flag==0)
	{
			ADMUX=ADMUX & 0XE0 ;
			ADMUX=ADMUX |ch    ;
			SET_BIT(ADCSRA,ADSC) ;
			flag=1 ; 
	}

}

u16 ADC_GetRead(void)
{
	while(READ_BIT(ADCSRA,ADSC))   ;
	flag=0 ; 
	return ADC  ;
	
}

u8 ADC_GetReadNoBlock(u16 *pdata)
{
	if(READ_BIT(ADCSRA,ADSC)==0)
	{
		*pdata = ADC ; 
		flag=0 ; 
		return 1 ; 
	}
	else
	{
		return 0 ; 
	}
}