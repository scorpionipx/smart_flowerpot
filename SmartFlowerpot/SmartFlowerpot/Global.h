#ifndef GLOBAL_H_
#define GLOBAL_H_

/* Includes */
/*============================================================================*/

/* Constants and types */
/*============================================================================*/
#define F_CPU		16000000L //clock freq-must be define before including util/delay.h

// Soil moisture level threshold for sensor no. 1 when water pump should be turned on 
#define SOIL_MOISTURE_LOW_LEVEL_THRESHOLD_S1 30
// Soil moisture level threshold for sensor no. 2 when water pump should be turned on
#define SOIL_MOISTURE_LOW_LEVEL_THRESHOLD_S2 30
// Average soil moisture level threshold when water pump should be turned on
#define SOIL_MOISTURE_LOW_LEVEL_THRESHOLD_AVERAGE 35

// Time between display refresh rate, measured in ms
#define DISPLAY_REFRESH_RATE 1500

// Timer between humidity level data acquisition, measured in ms 
#define SENSORS_READ_INTERVAL 1000

// Strings to display for humidity level
#define SENSOR_1_TITLE "Sensor 1: "
#define SENSOR_2_TITLE "Sensor 2: "

#define HUMIDITY_LEVEL_UNIT "%"

// Sensor entity
#define SENSOR_1 1
#define SENSOR_2 2

// Strings to display for clock
#define CLOCK_DATE_TITLE "Date"
#define CLOCK_TIME_TITLE "Time"

// Menus 
#define SENSOR_VALUES_MENU 0
#define CLOCK_MENU 1

typedef signed char sint8;
typedef unsigned char uint8;
typedef signed int sint16;
typedef unsigned int uint16;
typedef signed long sint32;
typedef unsigned long uint32;

/* Exported Variables */
/*============================================================================*/
unsigned int humidity_level_sensor_1;
unsigned int humidity_level_sensor_2;
char MENU;

#endif /* GLOBAL_H_ */ 

/* Notice: the file ends with a blank new line to avoid compiler warnings */
