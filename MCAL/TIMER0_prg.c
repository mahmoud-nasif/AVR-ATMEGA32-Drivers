/*
 * TIMER0_prg.c
 *
 *  Created on: Aug 24, 2021
 *      Author: user
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../APP/Mode1.h"

#include "../DIO/DIO_int.h"
#include "../DIO/DIO_pri.h"
#include "../GIE/GIE_int.h"
#include "TIMER0_int.h"
#include "TIMER0_pri.h"
#include "TIMER0_cfg.h"

u16 count = 0;
u32 time = 0;

void TIMER0_Init(void)
{
	/*scale 1024*/
		SET_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
		/* timer tick time = 1024usec  , time over flow (256) = 0.26 sec ,no.of.overflow (1sec) = 1sec/0.26 sec = 3.84 overflow */
		/*0.84 *256 = 215 counts */
		/*preload = 256 - (0.84 *256) = 41 */
		TCNT0 =0; /*preload value*/
		OCR0  = 245;
		SET_BIT(TCCR0,3);    /*SET ctc mode*/
		SET_BIT(TCCR0,7);
		GIE_Enable();   /*set global interupt enable*/
		SET_BIT(TIMSK,1);   /*timer ctc interrupt enable*/
}

void __vector_10(void)
{
	count++; //1
	if(count == 32)   //reached to 1 sec
	{

		time++;
		count = 0 ;
	}


}

