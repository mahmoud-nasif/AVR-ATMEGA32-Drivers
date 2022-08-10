#include "stepper.h"
#include "DIO_Interface.h"


#if(MOTOR_TYPE==UNI_POLER)
void STEBBER_UniPolerCW (void)
{
	    DIO_WritePin(COIL1A,HIGH) ; 
	    DIO_WritePin(COIL1B,LOW) ; 
	    DIO_WritePin(COIL2A,LOW) ; 
	    DIO_WritePin(COIL2B,LOW) ; 
	    _delay_ms(DELAY);
		DIO_WritePin(COIL1A,LOW) ;
		DIO_WritePin(COIL1B,HIGH) ;
		DIO_WritePin(COIL2A,LOW) ;
		DIO_WritePin(COIL2B,LOW) ;
		_delay_ms(DELAY) ;
		DIO_WritePin(COIL1A,LOW) ;
		DIO_WritePin(COIL1B,LOW) ;
		DIO_WritePin(COIL2A,HIGH) ;
		DIO_WritePin(COIL2B,LOW) ;
		_delay_ms(DELAY) ;
		DIO_WritePin(COIL1A,LOW) ;
		DIO_WritePin(COIL1B,LOW) ;
		DIO_WritePin(COIL2A,LOW) ;
		DIO_WritePin(COIL2B,HIGH) ;
		_delay_ms(DELAY);

}

void STEBBER_UniPolerUCW (void)
{
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,HIGH) ;
	_delay_ms(DELAY);
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,HIGH) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY) ;
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,HIGH) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY) ;
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(DELAY);
	
	
	

}

#elif (MOTOR_TYPE==BI_POLER)
void STEBBER_BipoleruCw (void)
{
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,HIGH) ;
	_delay_ms(10000);
		DIO_WritePin(COIL1A,LOW) ;
		DIO_WritePin(COIL1B,HIGH) ;
		DIO_WritePin(COIL2A,LOW) ;
		DIO_WritePin(COIL2B,LOW) ;
		_delay_ms(10000) ;
			DIO_WritePin(COIL1A,LOW) ;
			DIO_WritePin(COIL1B,LOW) ;
			DIO_WritePin(COIL2A,HIGH) ;
			DIO_WritePin(COIL2B,LOW) ;
			_delay_ms(10000) ;
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(10000);


	

}
void STEBBER_BipolerCw (void)
{
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(10000);
	DIO_WritePin(COIL1A,LOW) ;
		DIO_WritePin(COIL1B,LOW) ;
		DIO_WritePin(COIL2A,HIGH) ;
		DIO_WritePin(COIL2B,LOW) ;
		_delay_ms(10000) ;
		DIO_WritePin(COIL1A,LOW) ;
		DIO_WritePin(COIL1B,HIGH) ;
		DIO_WritePin(COIL2A,LOW) ;
		DIO_WritePin(COIL2B,LOW) ;
		_delay_ms(10000) ;
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,HIGH) ;
	_delay_ms(10000);
	
	


}

#endif

void STEBBER_CW_WithAngle(u16 angle)
{
	
	u16 n , i ; 
	n = (512*angle)/360 ; 
	
	for(i=0 ; i<n ; i++)
	{
		STEBBER_UniPolerCW() ;
	}
}
void STEBBER_UCW_WithAngle(u16 angle)
{
	
	u16 n , i ;
	n = (512*angle)/360 ;
	
	for(i=0 ; i<n ; i++)
	{
		STEBBER_UniPolerUCW() ;
	}
}