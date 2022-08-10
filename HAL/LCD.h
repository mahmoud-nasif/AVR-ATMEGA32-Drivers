

#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL 
#include <util/delay.h>
#include "StdTyps.h"
#include "DIO_Interface.h"

#define    _4_BIT          0   
#define    _8_BIT          1
#define    LCD_MODE       _4_BIT  

///////////*4 BIT *////////
#define    D4        PIND4    
#define    D5        PIND5  
#define    D6        PIND6  
#define    D7        PIND7   
 


#define     LCD_PORT     PD
#define     RS           PINC0
#define     RW           PINC1 
#define     EN           PINC7   



void LCD_Init(void) ;
void LCD_WriteData(u8 data) ;
void LCD_WriteString(u8 *str);
void LCD_WriteChar(u8 ch) ; 
void LCD_WriteNumber(u64 num);
void LCD_Clear(void) ; 
void LCD_GoTo(u8 line , u8 x) ;

void LCD_CreateCharacter(u8*pattern,u8 address);
void LCD_WriteNumberInBinary(u8 num);






#endif /* LCD_H_ */