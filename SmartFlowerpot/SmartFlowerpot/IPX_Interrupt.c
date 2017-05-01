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
#include "Menu.h"
#include "WaterLevelSensor.h"
#include "IPX_UART.h"
#include "IPX_Buttons.h"
#include "IPX_Clock.h"

#define TOGGLE_PWR_LED PORTB ^= (1 << 0)

#define INTERRUPT_200MS 200
#define INTERRUPT_10MS 10
#define SECOND 5

#define READ_SENSORS_VALUES_PERIOD SENSORS_READ_INTERVAL / INTERRUPT_200MS
#define READ_TANK_WATER_LEVEL_PERIOD TANK_WATER_LEVEL_READ_INTERVAL / INTERRUPT_200MS

unsigned int read_humidity_counter = 0;
unsigned int read_tank_water_level_counter = 201;
unsigned int seconds_counter = 0;

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
	display_values();
	seconds_counter ++;
	
	if(seconds_counter >= SECOND)
	{
		seconds_counter = 0;
		increment_clock();
		TOGGLE_PWR_LED;
	}
	
	read_humidity_counter ++;
	if (read_humidity_counter >= READ_SENSORS_VALUES_PERIOD)
	{
		read_humidity_counter = 0;
		read_humidity_level(SENSOR_1);
		read_humidity_level(SENSOR_2);
	}
	read_tank_water_level_counter ++;
	if (read_tank_water_level_counter >= READ_TANK_WATER_LEVEL_PERIOD)
	{
		read_tank_water_level_counter = 0;
		read_buttons();
		
		read_tank_water_level();
		read_temperature();
		send_uart_data_tank_water_level();
		send_uart_data_humidity_sensor_1();
		send_uart_data_humidity_sensor_2();
	}
}
