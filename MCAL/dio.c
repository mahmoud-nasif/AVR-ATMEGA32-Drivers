#include "DIO_Interface.h"

extern const   DIO_PinStatus_type PinStatusArray[TOTAL_PINS];

void DIO_InitPin(DIO_Pin_type Pin,DIO_PinStatus_type Status)
{
	u8 PinNum_InPort;
	DIO_Port_type Port;
	
	Port=Pin/8;
	PinNum_InPort=Pin%8;
	
	switch (Status)
	{
		case OUTPUT:
		switch (Port)
		{
			case PA:
			SET_BIT(DDRA,PinNum_InPort);
			break;
			case PB:
			SET_BIT(DDRB,PinNum_InPort);
			break;
			case PC:
			SET_BIT(DDRC,PinNum_InPort);
			break;
			case PD:
			SET_BIT(DDRD,PinNum_InPort);
			break;
		}
		break;
		case INLLUP:
		switch (Port)
		{
			case PA:
			CLEAR_BIT(DDRA,PinNum_InPort);
			SET_BIT(PORTA,PinNum_InPort);
			break;
			case PB:
			CLEAR_BIT(DDRB,PinNum_InPort);
			SET_BIT(PORTB,PinNum_InPort);
			break;
			case PC:
			CLEAR_BIT(DDRC,PinNum_InPort);
			SET_BIT(PORTC,PinNum_InPort);
			break;
			case PD:
			CLEAR_BIT(DDRD,PinNum_InPort);
			SET_BIT(PORTD,PinNum_InPort);
			break;
		}
		break;
		case INFREE:
		switch (Port)
		{
			case PA:
			CLEAR_BIT(DDRA,PinNum_InPort);
			CLEAR_BIT(PORTA,PinNum_InPort);
			break;
			case PB:
			CLEAR_BIT(DDRB,PinNum_InPort);
			CLEAR_BIT(PORTB,PinNum_InPort);
			break;
			case PC:
			CLEAR_BIT(DDRC,PinNum_InPort);
			CLEAR_BIT(PORTC,PinNum_InPort);
			break;
			case PD:
			CLEAR_BIT(DDRD,PinNum_InPort);
			CLEAR_BIT(PORTD,PinNum_InPort);
			break;
		}break ; 
		
	}
	
	
}
	


	void DIO_Init(void)
	{
		 DIO_Pin_type i;
		 for (i=PINA0;i<TOTAL_PINS;i++)
		 {
			 DIO_InitPin(i,PinStatusArray[i]);
		 }

	}
	
	void DIO_WritePort(DIO_Port_type Port,u8 Value)
	{
		switch (Port)
		{
			case PA:
			PORTA = Value;
			break;
			case PB:
			PORTB=Value;
			break;
			case PC:
			PORTC=Value;
			break;
			case PD:
			PORTD=Value;
			break;
		}
	}
	/*void DIO_WriteBitsInPort(DIO_Port_type Port,u8 Value,u8 Mask)
	{
		switch (Port)
		{
			case PA:
			CLEAR_BITS_REG(PORTA,Mask);
			SET_BITS_REG(PORTA,Value&Mask);
			break;
			case PB:
			CLEAR_BITS_REG(PORTB,Mask);
			SET_BITS_REG(PORTB,Value&Mask);
			break;
			case PC:
			CLEAR_BITS_REG(PORTC,Mask);
			SET_BITS_REG(PORTC,Value&Mask);
			break;
			case PD:
			CLEAR_BITS_REG(PORTD,Mask);
			SET_BITS_REG(PORTD,Value&Mask);
			break;
		}
	}*/
	u8 DIO_ReadPort(DIO_Port_type Port)
	{
		switch (Port)
		{
			case PA:
			return PINA;
			break;
			case PB:
			return PINB;
			break;
			case PC:
			return PINC;
			break;
			case PD:
			return PIND;
			break;
			default:
			return 0x00;
			break;
		}
	}
	void DIO_WritePin(DIO_Pin_type Pin,DIO_Voltage_type Value)
	{
		u8 PinNum_InPort=Pin%8;
		DIO_Port_type Port=Pin/8;
		switch (Port)
		{
			case PA:
			if (HIGH==Value)
			{
				SET_BIT(PORTA,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTA,PinNum_InPort);
			}
			break;
			case PB:
			if (HIGH==Value)
			{
				SET_BIT(PORTB,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTB,PinNum_InPort);
			}
			break;
			case PC:
			if (HIGH==Value)
			{
				SET_BIT(PORTC,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTC,PinNum_InPort);
			}
			break;
			case PD:
			if (HIGH==Value)
			{
				SET_BIT(PORTD,PinNum_InPort);
			}
			else
			{
				CLEAR_BIT(PORTD,PinNum_InPort);
			}
			break;
		}
	}
	void DIO_TogglePin(DIO_Pin_type Pin)
	{
		u8 PinNum_InPort=Pin%8;
		DIO_Port_type Port=Pin/8;
		switch (Port)
		{
			case PA:
			TOGGLE_BIT(PORTA,PinNum_InPort);
			break;
			case PB:
			TOGGLE_BIT(PORTB,PinNum_InPort);
			break;
			case PC:
			TOGGLE_BIT(PORTC,PinNum_InPort);
			break;
			case PD:
			TOGGLE_BIT(PORTD,PinNum_InPort);
			break;
		}
	}
	DIO_Voltage_type DIO_ReadPin(DIO_Pin_type Pin)
	{
		u8 PinNum_InPort=Pin%8;
		DIO_Port_type Port=Pin/8;
		switch (Port)
		{
			case PA:
			return READ_BIT(PINA,PinNum_InPort);
			break;
			case PB:
			return READ_BIT(PINB,PinNum_InPort);
			break;
			case PC:
			return READ_BIT(PINC,PinNum_InPort);
			break;
			case PD:
			return READ_BIT(PIND,PinNum_InPort);
			break;
			default:
			return 0x00;
			break;
		}
	}

