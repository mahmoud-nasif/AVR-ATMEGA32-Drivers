
#ifndef ADS_H_
#define ADS_H_

#include "StdTyps.h"
#include "MemMap.h"
#include "Utils.h"

typedef enum {
	VREF_VCC ,
	VREF_AREF,
	VREF_V256
	}ADC_Vref_Type;
	
	typedef enum {
		ADC_Scaler_2=1 , 
		ADC_Scaler_4 , 
		ADC_Scaler_8 , 
		ADC_Scaler_16 , 
		ADC_Scaler_32 , 
		ADC_Scaler_64 , 
		ADC_Scaler_128    
	}ADC_Scaler_Type;
	
	
	typedef enum {
		CH_0=0 ,
		CH_1 ,
		CH_2 ,
		CH_3 ,
		CH_4 ,
		CH_5 ,
		CH_6 ,
		CH_7 
		}ADC_CH_Type;
	
	
void ADC_Init(ADC_Vref_Type vref , ADC_Scaler_Type scaler) ;  
u16 ADC_Read(ADC_CH_Type ch) ; 
void ADC_StartConversion(ADC_CH_Type ch);
u16 ADC_GetRead(void);
u8 ADC_GetReadNoBlock(u16 *pdata);





#endif /* ADS_H_ */