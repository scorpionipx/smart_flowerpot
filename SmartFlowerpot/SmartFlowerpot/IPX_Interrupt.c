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

unsigned int display_refresh_counter = 500;
unsigned int read_humidity_counter = 0;

void init_Interrupt(void)
{
	TCCR0 = 0x0b;
	TCNT0 = 0;
	OCR0 = 250;
	TIMSK = TIMSK | 0X02;
	TIFR = 0X02;
}


ISR(TIMER0_COMP_vect) /*RUNS EVERY .5MS*/
{
	display_refresh_counter ++;
	if (display_refresh_counter >= DISPLAY_REFRESH_RATE)
	{
		display_refresh_counter = 0;
		switch(MENU)
		{
			case SENSOR_VALUES_MENU:
			{
				display_umidity_level_values(MENU, humidity_level_sensor_2);
				break;
			}
			case CLOCK_MENU:
			{
				display_clock_values();
				break;
			}
			default:
			{
				put_string("error");
				break;
			}
		}
	}
	read_humidity_counter ++;
	if(read_humidity_counter >= SENSORS_READ_INTERVAL)
	{
		read_humidity_level(SENSOR_1);
		read_humidity_level(SENSOR_2);
	}
}