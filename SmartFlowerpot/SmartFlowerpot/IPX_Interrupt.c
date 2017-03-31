/*
 * IPX_Interrupt.c
 *
 * Created: 22.03.2016 20:52:05
 *  Author: Dan
 */ 


#include "Global.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned int display_refresh_counter = 0;

void init_Interrupt(void)
{
	TCCR0 = 0x0b;
	TCNT0 = 0;
	OCR0 = 125;
	TIMSK = TIMSK | 0X02;
	TIFR = 0X02;
}


ISR(TIMER0_COMP_vect) /*RUNS EVERY 1MS*/
{
	display_refresh_counter ++;
	if (display_refresh_counter >= DISPLAY_REFRESH_RATE)
	{
		display_refresh_counter = 0;
		
	}
}