/*
 |=========================================================================
 |
 | Project   : Electromobility_SW
 |
 | Module    : Driver ADC
 | |
 | Purpose   : Main functions for ADC handling
 | |
 | Created   : 13.05.2016
 | 
 |=========================================================================
*/
 
#ifndef _driver_adc_h_
#define _driver_adc_h_

#include "Global.h" // always include this first!!!
#include <avr/io.h>


void ADC_Init(void);
uint16_t ADC_GetValue(uint8_t ch);
void read_humidity_level(int sensor);
void read_temperature();

#endif /*_driver_adc_h_*/