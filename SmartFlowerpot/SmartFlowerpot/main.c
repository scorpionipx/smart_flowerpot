/*
 * SmartFlowerpot.c
 *
 * Created: 2/18/2017 4:13:13 PM
 * Author : ScorpionIPX
 */ 

#include "Global.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "IPX_LCD_Display.h"
#include "driverAdc.h"
#include "IPX_Interrupt.h"

void init_globals();

int main(void)
{
	init_globals();
	
	DDRB |= (1 << 0);
	
	init_interrupt_10ms();
	init_interrupt_200ms();
	ADC_Init();
	init_LCD_Display();
	
	display_initializing_message();
	_delay_ms(1000);
	display_umidity_level_title();
	sei();
	
    while (1) 
    {
    }
}

void init_globals()
{
	MENU = CLOCK_MENU;
	
	humidity_level_sensor_1 = 0;
	humidity_level_sensor_2 = 0;
}