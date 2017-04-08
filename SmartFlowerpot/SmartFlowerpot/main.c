/*
 * SmartFlowerpot.c
 *
 * Created: 2/18/2017 4:13:13 PM
 * Author : ScorpionIPX
 */ 

#include "Global.h"
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "IPX_LCD_Display.h"
#include "driverAdc.h"
#include "IPX_Interrupt.h"
#include "Menu.h"

void general_init();
void init_globals();
void init_uC(void);

int main(void)
{
	general_init();
	
	init_interrupt_10ms();
	init_interrupt_200ms();
	ADC_Init();
	init_LCD_Display();
	
	
	display_initializing_message();
	_delay_ms(1000);
	change_menu(TANK_WATER_LEVEL_MENU);
	sei();
	
    while (1) 
    {
	}
}

void general_init()
{
	init_uC();
	init_globals();
}

void init_uC(void)
{
	DDRB |= (1 << 0);
}

void init_globals()
{
	MENUs[0] = ERROR_MENU;
	MENUs[1] = SENSOR_VALUES_MENU;
	MENUs[2] = CLOCK_MENU;
	MENUs[3] = TANK_WATER_LEVEL_MENU;
	MENUs[4] = UNDEFINED_MENU;
	MENUs[5] = UNDEFINED_MENU;
	MENUs[6] = UNDEFINED_MENU;
	MENUs[7] = UNDEFINED_MENU;
	MENUs[8] = UNDEFINED_MENU;
	MENUs[9] = UNDEFINED_MENU;
	
	strcpy(ERROR, ERROR_NO_ERROR);
	
	humidity_level_sensor_1 = 0;
	humidity_level_sensor_2 = 0;
}