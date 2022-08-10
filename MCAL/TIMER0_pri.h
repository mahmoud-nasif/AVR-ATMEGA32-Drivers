/*
 * TIMER0_pri.h
 *
 *  Created on: Aug 24, 2021
 *      Author: user
 */

#ifndef MCAL_TIMER0_TIMER0_PRI_H_
#define MCAL_TIMER0_TIMER0_PRI_H_


#define TCNT0      *((volatile u8*) 0x52)
#define TCCR0      *((volatile u8*) 0x53)
#define TIMSK      *((volatile u8*) 0x59)
#define OCR0       *((volatile u8*) 0x5C)

void __vector_10(void) __attribute__((signal)); /*for timer overflow*/


#endif /* MCAL_TIMER0_TIMER0_PRI_H_ */
