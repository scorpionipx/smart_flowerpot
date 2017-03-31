/*
 * IPX_LCD_Display.c
 *
 * Created: 22.03.2016 16:53:29
 *  Author: Dan
 */ 

#include "Global.h"
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>


void put_Char_LCD_Display(int ch, int type)
{
	PORTC = (PORTC&0x0F)|(ch&0xF0);
	PORTC = (PORTC&0xFE)|(type&0x01);
	PORTC = PORTC|0x02;
	_delay_ms(5);
	PORTC &= 0xFC;
	PORTC = (PORTC&0x0F)|((ch<<4)&0xF0);
	PORTC = (PORTC&0xFE)|(type&0x01);
	PORTC = PORTC|0x02;
	_delay_ms(5);
	PORTC &= 0xFC;
}

void init_LCD_Display(void)
{
	DDRC = 0xFF;
	put_Char_LCD_Display(0x03,0);
	_delay_ms(5);
	put_Char_LCD_Display(0x03,0);
	_delay_ms(5);
	put_Char_LCD_Display(0x03,0);
	_delay_ms(5);
	put_Char_LCD_Display(0x02,0);
	_delay_ms(5);
	put_Char_LCD_Display(0x0C,0);
	_delay_ms(5);
	put_Char_LCD_Display(0x01,0);
	_delay_ms(5);
	put_Char_LCD_Display(0x80,0);
	_delay_ms(5);
	put_Char_LCD_Display(0x01,0);//clear display
}
