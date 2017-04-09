/*
 * WaterLevelSensor.h
 *
 * Created: 4/9/2017 3:35:33 PM
 *  Author: ScorpionIPX
 */ 


#ifndef WATERLEVELSENSOR_H_
#define WATERLEVELSENSOR_H_

#define WATER_LEVEL_SENSOR_PORT PORTB
#define WATER_LEVEL_SENSOR_PIN PINB
#define WATER_LEVEL_SENSOR_DDR DDRB

#define WATER_SENSOR_LEVEL_1 PB7
#define WATER_SENSOR_LEVEL_2 PB6
#define WATER_SENSOR_LEVEL_3 PB5
#define WATER_SENSOR_LEVEL_4 PB4
#define WATER_SENSOR_LEVEL_5 PB3
#define WATER_SENSOR_LEVEL_6 PB2

void init_ipx_water_level_sensor();
void read_tank_water_level();



#endif /* WATERLEVELSENSOR_H_ */