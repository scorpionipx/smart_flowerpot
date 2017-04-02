/*
 |=========================================================================
 |
 | Project   : Electromobility_SW
 |
 | Module    : Driver Switch
 | |
 | Purpose   : Main functions for Switch handling
 | |
 | Created   : 13.05.2016
 | 
 |=========================================================================
*/

#include "Global.h" // always include this first!!!
#include <avr/io.h>
#include <util/delay.h>
#include "driverSwitch.h"
#include "driverAdc.h"

#define SWITCH_PORT               PORTB
#define SWITCH_PORT_DIR           DDRB


void Switch_Init(void)
{
	SWITCH_PORT_DIR &= ~((1u << SWITCH1) | (1u << SWITCH2) | (1u << SWITCH3) | (1u << SWITCH4));
}
