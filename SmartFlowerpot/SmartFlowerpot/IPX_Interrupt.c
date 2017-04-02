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
#include "IPX_LCD_Display.h"
#include "driverAdc.h"

#define INTERRUPT_200MS 200
#define INTERRUPT_10MS 10

#define READ_SENSORS_VALUES_PERIOD SENSORS_READ_INTERVAL / INTERRUPT_200MS

unsigned int display_refresh_counter = 500;
unsigned int read_humidity_counter = 0;

volatile int interruptCnt = 0;

//10 ms timer
void init_interrupt_10ms(void)
{
	/* clear timer on compare mode , output normal port , 256 prescaler */
	TCCR0 = (1u << WGM01) | (1u << CS02) | (1u << CS00);
	/* reset counter */
	TCNT0=0x00;
	
	/* 10 ms interrupt */
	OCR0 = 156;
	
	/* enable compare A interrupt */
	TIMSK = (1u << OCIE0);
	
}

// 10ms ISR
ISR(TIMER0_COMP_vect)
{
	TIFR |= (1u << OCF0); /* clear output compare interrupt flag */
	interruptCnt++;
}

// 200 ms timer
void init_interrupt_200ms()
{
	// set up timer with prescaler = 64 and CTC mode
	TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);
	
	// initialize counter
	TCNT1 = 0;
	
	// initialize compare value
	OCR1A = 49999;
	
	// enable compare interrupt
	TIMSK |= (1 << OCIE1A);
}

// 200ms ISR
ISR (TIMER1_COMPA_vect)
{
	// toggle led here
	PORTB ^= (1 << 0);
	display_umidity_level_values(humidity_level_sensor_1, humidity_level_sensor_2);
	read_humidity_counter ++;
	if (read_humidity_counter >= READ_SENSORS_VALUES_PERIOD)
	{
		read_humidity_counter = 0;
		read_humidity_level(SENSOR_1);
		read_humidity_level(SENSOR_2);
	}
}
