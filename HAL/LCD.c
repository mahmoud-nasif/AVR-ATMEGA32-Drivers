#include "LCD.h"
#if(LCD_MODE==_8_BIT)
void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW) ; 
	DIO_WritePin(RW,LOW) ; 
	DIO_WritePort(LCD_PORT,command) ; 
	DIO_WritePin(EN,HIGH) ; 
	_delay_ms(2) ; 
	DIO_WritePin(EN,LOW) ; 
	_delay_ms(2) ; 
	
}

void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH) ;
	DIO_WritePin(RW,LOW) ;
	DIO_WritePort(LCD_PORT,data) ;
	DIO_WritePin(EN,HIGH) ;
	_delay_ms(2) ;
	DIO_WritePin(EN,LOW) ;
	_delay_ms(2) ;
	
}

void LCD_Init(void)
{
	_delay_ms(50) ; 
	LCD_WriteCommand(0X38) ; //select 8 bit mode , font 5*7 , 2 lines 
	_delay_ms(1) ; 
	LCD_WriteCommand(0X0C) ; //cursor 
	_delay_ms(1) ; 
	LCD_WriteCommand(0X01) ; //clear 
	_delay_ms(2) ; 
	LCD_WriteCommand(0x06) ; //DD ram address increase
	_delay_ms(1) ;
}

#elif (LCD_MODE==_4_BIT)

void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW) ;
	DIO_WritePin(RW,LOW) ;
	DIO_WritePin( D7 , READ_BIT(command,7) ) ; 
	DIO_WritePin( D6, READ_BIT(command,6) ) ;
	DIO_WritePin( D5 , READ_BIT(command,5) ) ;
	DIO_WritePin( D4 , READ_BIT(command,4) ) ;
	DIO_WritePin(EN,HIGH) ;
	_delay_ms(1) ;
	DIO_WritePin(EN,LOW) ;
	_delay_ms(1) ;
	DIO_WritePin( D7 , READ_BIT(command,3) ) ;
	DIO_WritePin( D6, READ_BIT(command,2) ) ;
	DIO_WritePin( D5 , READ_BIT(command,1) ) ;
	DIO_WritePin( D4 , READ_BIT(command,0) ) ;
	DIO_WritePin(EN,HIGH) ;
	_delay_ms(1) ;
	DIO_WritePin(EN,LOW) ;
	_delay_ms(1) ;
	
}

void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH) ;
	DIO_WritePin(RW,LOW) ;
	DIO_WritePin( D7 , READ_BIT(data,7) ) ;
	DIO_WritePin( D6, READ_BIT(data,6) ) ;
	DIO_WritePin( D5 , READ_BIT(data,5) ) ;
	DIO_WritePin( D4 , READ_BIT(data,4) ) ;
	DIO_WritePin(EN,HIGH) ;
	_delay_ms(1) ;
	DIO_WritePin(EN,LOW) ;
	_delay_ms(1) ;
	DIO_WritePin( D7 , READ_BIT(data,3) ) ;
	DIO_WritePin( D6, READ_BIT(data,2) ) ;
	DIO_WritePin( D5 , READ_BIT(data,1) ) ;
	DIO_WritePin( D4 , READ_BIT(data,0) ) ;
	DIO_WritePin(EN,HIGH) ;
	_delay_ms(1) ;
	DIO_WritePin(EN,LOW) ;
	_delay_ms(1) ;
	
}

void LCD_Init(void)
{
	_delay_ms(50) ;
	LCD_WriteCommand(0X02) ; 
	_delay_ms(1) ; 
	LCD_WriteCommand(0X28) ; //select 4 bit mode , font 5*7 , 2 lines
	_delay_ms(1) ;
	LCD_WriteCommand(0X0C) ; //cursor
	_delay_ms(1) ;
	LCD_WriteCommand(0X01) ; //clear
	_delay_ms(2) ;
	LCD_WriteCommand(0x06) ; //DD ram address increase
	_delay_ms(1) ;
}
#endif

void LCD_WriteString(u8 *str)
{
	u8 i = 0 ;
	
	while(str[i])
	{
		LCD_WriteData(str[i]) ;
		i++ ;
	}
}

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch) ;
}

void LCD_WriteNumber(u64 num)
{
	u8 arr[16]={0} ,i=0,j ;
	if(num==0)
	{
		LCD_WriteData('0') ;
	}
	else
	{
		while(num>0)
		{
			arr[i] = (num % 10) + '0'  ;
			i++ ;
			num = num / 10 ;
		}
		for(j=i ; j>0 ; j--)
		{
			LCD_WriteData(arr[j-1]) ;
		}
	}
	
	
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0X01) ;
}

void LCD_GoTo(u8 line , u8 x)
{
	if(line==1)
	{
		LCD_WriteCommand(0X80 + x) ;
	}
	else if(line==2)
	{
		LCD_WriteCommand(0X80 + 0X40 + x) ;
	}
}

void LCD_CreateCharacter(u8*pattern,u8 address)
{
	u8 i ;
	LCD_WriteCommand(0x40+address*8) ;
	for(i=0;i<8;i++)
	{
		LCD_WriteData(pattern[i]) ;
	}
}

void LCD_WriteNumberInBinary(u8 num)
{
	s8 i ; 
	
	for(i=7 ; i>=0 ; i--)
	{
		LCD_WriteData(((num>>i) & 1)+'0' ) ; 
	}
	
	
}


