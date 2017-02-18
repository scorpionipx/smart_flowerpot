/* Includes */
/*============================================================================*/
#include "Global.h" // always include this first!!!
#include <avr/io.h>
#include <util/delay.h>
#include "DigitalLED.h"
/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/


/* Private functions prototypes */
/*============================================================================*/
void DisplayDIGIT(uint8 dig);
void SelectSegment(uint8 seg);
/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/
void DigitalDisplayInit(void)
{
	
	DDRC = 0xFF;
	DDRB = 0xFF;
	PORTC = 0xFF; //all pins are output
	PORTB |= (1<<PSEL0)|(1<<PSEL1)|(1<<PSEL2)|(1<<PSEL3);
	ClearDisplayLED();
}



void DisplayDIGIT(uint8 dig)
{
	switch (dig)
	{
		case 0:  SEG_PORT = 0xFF & SEGA & SEGB & SEGC & SEGD & SEGE & SEGF;        break;
		case 1:  SEG_PORT = 0xFF & SEGB & SEGC;                                    break;
		case 2:	 SEG_PORT = 0xFF & SEGA & SEGB & SEGD & SEGE & SEGG;               break;
		case 3:	 SEG_PORT = 0xFF & SEGA & SEGB & SEGC & SEGD & SEGG;               break;
		case 4:  SEG_PORT = 0xFF & SEGB & SEGC & SEGF & SEGG;                      break;
		case 5:	 SEG_PORT = 0xFF & SEGA & SEGC & SEGD & SEGF & SEGG;               break;
		case 6:	 SEG_PORT = 0xFF & SEGA & SEGC & SEGD & SEGE & SEGF & SEGG;        break;
		case 7:	 SEG_PORT = 0xFF & SEGA & SEGB & SEGC;                             break;
		case 8:	 SEG_PORT = 0xFF & SEGA & SEGB & SEGC & SEGD & SEGE & SEGF & SEGG; break;
		case 9:	 SEG_PORT = 0xFF & SEGA & SEGB & SEGC & SEGD & SEGF & SEGG;    	   break;
		default: SEG_PORT &=DOT; /*dot*/                                           break;
	}
	
}
void SelectSegment(uint8 seg)
{
	switch (seg)
	{
		case 0: SEL_PORT |= ~SEL1 | ~SEL2 | ~SEL3; //turn off other selections
				SEL_PORT &= SEL0;				    //turn on requested selection
				break;
		case 1: 
				/*SEL_PORT |= ~SEL0 | ~SEL2 | ~SEL3; //turn off other selections
				SEL_PORT &= SEL1;*/
				break;
		case 2: SEL_PORT |= ~SEL0 | ~SEL2 | ~SEL3; //turn off other selections
				SEL_PORT &= SEL2;
				break;
		case 3:	SEL_PORT |= ~SEL0 | ~SEL1 | ~SEL2; //turn off other selections
				SEL_PORT &= SEL3;
				break;
		default: SEL_PORT &=SEL0 & SEL1 & SEL2 & SEL3; /*dot*/ break;
	}
	
}

void ClearDisplayLED(void)
{
	SEG_PORT = 0xFF;
	SEL_PORT |= ~SEL0 | ~SEL1 | ~SEL2 | ~SEL3;
}
void DisplaySingleDigit(uint8 dig, uint8 seg)
{
	SelectSegment(seg);
	DisplayDIGIT(dig);
}

void DisplayNumber(uint16 no,uint16 duration)
{
	uint8 digit;
	uint16 localNo;
	if (duration<20) duration = 20;
	while(duration>0)
	{
		//todo: take also into consideration the time to display
		localNo = no;
		ClearDisplayLED();
		digit = localNo % 10;
		localNo=localNo/10;
		DisplaySingleDigit(digit, 3);
		_delay_ms(5);
		
		ClearDisplayLED();
		digit = localNo % 10;
		localNo=localNo/10;
		DisplaySingleDigit(digit, 2);
		_delay_ms(5);
		
		ClearDisplayLED();
		digit = localNo % 10;
		localNo=localNo/10;
		DisplaySingleDigit(digit, 1);
		_delay_ms(5);
		
		ClearDisplayLED();
		DisplaySingleDigit((uint8)localNo, 0);
		_delay_ms(5);
		duration = duration - 20; //we wait for 5*4 = 20 ms (excluding the display time and digit calculation)
	}

	
}
/* Exported functions */
/*============================================================================*/




/* Notice: the file ends with a blank new line to avoid compiler warnings */
