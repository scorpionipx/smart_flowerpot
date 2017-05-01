#include "Global.h"
#include <avr/io.h>
#include "driverAdc.h"
#include <math.h>

#define SERIES_RESISTOR 10000 // SERIES RESISTOR VALUE(OHMS)
#define RT_25 10000 // NTC RESISTANCE AT 25 °C
#define B_25_100 4100 // NTC parameter
#define RECIPROCAL_T25_10000 3354 // (1 / 25 °C (measured as kelvin) <=> 1 / 298.15) * 10000
#define K_TO_C_100 27315// conversion factor
#define TEMP_OFFSET_100 -120 // temperature offset * 10000

void ADC_Init(void)
{
		DDRA = 0x00;
	    // AREF = AVcc
	    ADMUX = (1<<REFS0);
	    
	    // ADC Enable and prescaler of 128
	    // 16000000/128 = 125000
	    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

// read ADC value
uint16_t ADC_GetValue(uint8_t ch)
{
	// select the corresponding channel 0~7
	// ANDing with '7' will always keep the value
	// of 'ch' between 0 and 7
	ch &= 0b00000111;  // AND operation with 7
	ADMUX = (ADMUX & 0xF8)|ch;     // clears the bottom 3 bits before ORing
	
	// start single conversion
	// write '1' to ADSC
	ADCSRA |= (1<<ADSC);
	
	// wait for conversion to complete
	// ADSC becomes '0' again
	// till then, run loop continuously
	while(ADCSRA & (1<<ADSC));
	
	return (ADC);
}

// temperature is read as a 5 digit positive number, 2 decimals precission
void read_temperature()
{
	unsigned int VOLTAGE;
	unsigned int NTC_RESISTANCE;
	long int LN_NTC_RT25_10000; // (ln(NTC_res / RT_25)) * 10000
	long int LN_B25_100_10000; // ((ln(NTC_res / RT_25)) * 10000) / B_25_100
	long int RECIPROCAL_TEMPERATURE; // 1 / TEMPERATURE
	
	VOLTAGE = (((uint32_t)ADC_GetValue(2) * 5000) / 1023);
	NTC_RESISTANCE = (uint32_t) SERIES_RESISTOR * VOLTAGE / (5000 - VOLTAGE);
	
	LN_NTC_RT25_10000 = (sint32) (log((double) NTC_RESISTANCE / RT_25) * 10000);
	LN_B25_100_10000 = (sint32) LN_NTC_RT25_10000 * 100 / B_25_100;
	RECIPROCAL_TEMPERATURE = (sint32) LN_B25_100_10000 + RECIPROCAL_T25_10000;
	TEMPERATURE = (sint32) 100000000 / RECIPROCAL_TEMPERATURE;
	TEMPERATURE -= K_TO_C_100;
	TEMPERATURE += TEMP_OFFSET_100;
}

void read_humidity_level(int sensor)
{
	switch(sensor)
	{
		case 1:
		{
			humidity_level_sensor_1 = (((uint32_t)ADC_GetValue(0) * 100) / 1023);
			break;
		}
		case 2:
		{
			humidity_level_sensor_2 = (((uint32_t)ADC_GetValue(1) * 100) / 1023);
			break;
		}
		default:
		{
			break;
		}
	}
}