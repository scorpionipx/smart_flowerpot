/*
 * IPX_Buttons.h
 *
 * Created: 4/17/2017 1:17:12 PM
 *  Author: ScorpionIPX
 */ 

/*
	PIN CONFIGURATION

     BUTTON_1 - PC2, 25th
	 BUTTON_2 - PC3, 26th
	 BUTTON_3 - PC4, 27th
	 BUTTON_4 - PC5, 28th
*/


#ifndef IPX_BUTTONS_H_
#define IPX_BUTTONS_H_

#include "avr/io.h"

#define BUTTONS_PORT PORTD
#define BUTTONS_PIN PIND
#define BUTTONS_DDR DDRD

#define BUTTON_1_PIN PD6
#define BUTTON_2_PIN PD7

#define BUTTON_1_VALUE ((BUTTONS_PIN >> BUTTON_1_PIN) & 1)
#define BUTTON_2_VALUE ((BUTTONS_PIN >> BUTTON_2_PIN) & 1)

void init_buttons();
void read_buttons();

#endif /* IPX_BUTTONS_H_ */