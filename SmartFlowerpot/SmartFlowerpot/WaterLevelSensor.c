/*
 * WaterLevelSensor.c
 *
 * Created: 4/9/2017 3:34:09 PM
 *  Author: ScorpionIPX
 */ 


#include "Global.h"
#include <avr/io.h>
#include "WaterLevelSensor.h"


void init_ipx_water_level_sensor()
{
	// set pins PB2-PB7 as input pins
	WATER_LEVEL_SENSOR_DDR &= ~((1 << WATER_SENSOR_LEVEL_1) | (1 << WATER_SENSOR_LEVEL_2) | (1 << WATER_SENSOR_LEVEL_3) | (1 << WATER_SENSOR_LEVEL_4) | (1 << WATER_SENSOR_LEVEL_5) | (1 << WATER_SENSOR_LEVEL_6));
	// activate pull up resistor
	WATER_LEVEL_SENSOR_PORT |= (1 << WATER_SENSOR_LEVEL_1) | (1 << WATER_SENSOR_LEVEL_2) | (1 << WATER_SENSOR_LEVEL_3) | (1 << WATER_SENSOR_LEVEL_4) | (1 << WATER_SENSOR_LEVEL_5) | (1 << WATER_SENSOR_LEVEL_6);
}

void read_tank_water_level()
{
	unsigned char level = 1;
	level = (WATER_LEVEL_SENSOR_PIN >> WATER_SENSOR_LEVEL_6) & 1;
	if(level == 0)
	{
		WATER_LEVEL = 6;
		return;
	}
	level = (WATER_LEVEL_SENSOR_PIN >> WATER_SENSOR_LEVEL_5) & 1;
	if(level == 0)
	{
		WATER_LEVEL = 5;
		return;
	}
	level = (WATER_LEVEL_SENSOR_PIN >> WATER_SENSOR_LEVEL_4) & 1;
	if(level == 0)
	{
		WATER_LEVEL = 4;
		return;
	}
	level = (WATER_LEVEL_SENSOR_PIN >> WATER_SENSOR_LEVEL_3) & 1;
	if(level == 0)
	{
		WATER_LEVEL = 3;
		return;
	}
	level = (WATER_LEVEL_SENSOR_PIN >> WATER_SENSOR_LEVEL_2) & 1;
	if(level == 0)
	{
		WATER_LEVEL = 2;
		return;
	}
	level = (WATER_LEVEL_SENSOR_PIN >> WATER_SENSOR_LEVEL_1) & 1;
	if(level == 0)
	{
		WATER_LEVEL = 1;
		return;
	}
	WATER_LEVEL = 0;
}