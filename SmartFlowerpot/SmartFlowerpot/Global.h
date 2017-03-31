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


typedef signed char sint8;
typedef unsigned char uint8;
typedef signed int sint16;
typedef unsigned int uint16;
typedef signed long sint32;
typedef unsigned long uint32;

/* Exported Variables */
/*============================================================================*/


#endif /* GLOBAL_H_ */ 

/* Notice: the file ends with a blank new line to avoid compiler warnings */
