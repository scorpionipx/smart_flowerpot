/*
 * SmartFlowerpot.c
 *
 * Created: 2/18/2017 4:13:13 PM
 * Author : ScorpionIPX
 */ 

#include "Global.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "IPX_LCD_Display.h"
#include "driverAdc.h"
#include "IPX_Interrupt.h"


int main(void)
{
	humidity_level_sensor_1 = 0;
	humidity_level_sensor_2 = 0;
	
	sei();
	init_Interrupt();
	ADC_Init();
	init_LCD_Display();
	put_Char_LCD_Display(0xC0, 0);
	display_umidity_level_title();
	display_umidity_level_values(humidity_level_sensor_1, humidity_level_sensor_2);
	
    while (1) 
    {
    }
}

