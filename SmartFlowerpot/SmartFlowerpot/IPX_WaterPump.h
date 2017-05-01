/*
 * IPX_WaterPump.h
 *
 * Created: 5/1/2017 6:52:37 PM
 *  Author: ScorpionIPX
 */ 


#ifndef IPX_WATERPUMP_H_
#define IPX_WATERPUMP_H_

#include "avr/io.h"

#define WATER_PUMP_DDR DDRD
#define WATER_PUMP_PORT PORTD
#define WATER_PUMP_PIN PD5

#define WATER_PUMP_TURN_ON WATER_PUMP_PORT |= 1 << WATER_PUMP_PIN         // TURN ON WATER PUMP
#define WATER_PUMP_TURN_OFF WATER_PUMP_PORT &= ~(1 << WATER_PUMP_PIN)     // TURN OFF WATER PUMP
#define WATER_PUMP_TOGGLE WATER_PUMP_PORT ^= 1 << WATER_PUMP_PIN     // TOGGLE WATER PUMP

void init_water_pump_control();

#endif /* IPX_WATERPUMP_H_ */