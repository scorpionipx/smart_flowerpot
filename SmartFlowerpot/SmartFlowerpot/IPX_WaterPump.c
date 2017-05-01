/*
 * IPX_WaterPump.c
 *
 * Created: 5/1/2017 6:52:15 PM
 *  Author: ScorpionIPX
 */ 

#include "Global.h"
#include <avr/io.h>
#include "IPX_WaterPump.h"

void init_water_pump_control()
{
	WATER_PUMP_DDR |= 1 << WATER_PUMP_PIN;
	WATER_PUMP_TURN_OFF;
}