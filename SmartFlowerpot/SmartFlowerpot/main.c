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


int main(void)
{
	MENU = SENSOR_VALUES_MENU;
	MENU = CLOCK_MENU;
	
	humidity_level_sensor_1 = 0;
	humidity_level_sensor_2 = 0;
	
	sei();
	init_Interrupt();
	ADC_Init();
	init_LCD_Display();
	
	display_clock_title();
	
    while (1) 
    {
    }
}

