#include "driverAdc.h"

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

void read_humidity_level(int sensor)
{
	switch(sensor)
	{
		case 1:
		{
			humidity_level_sensor_1 = (((uint32_t)ADC_GetValue(0) * 100) / 1023);
		}
		case 2:
		{
			humidity_level_sensor_2 = (((uint32_t)ADC_GetValue(1) * 100) / 1023);
		}
		default:
		{
			break;
		}
	}
}