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

void put_string(const char *_string)
{
	int ch_index;
	for(ch_index=0;ch_index<strlen(_string);ch_index++)
	{
		put_Char_LCD_Display(_string[ch_index], 1);
	}
}

// displays humidity percentage title
void display_umidity_level_title()
{
	put_Char_LCD_Display(0x80, 0);
	put_string(SENSOR_1_TITLE);
	put_Char_LCD_Display(0xC0, 0);
	put_string(SENSOR_2_TITLE);
}

const char * humidity_level_int_value_to_string(int value)
{
	int first_digit;
	int second_digit;
	int third_digit;
	
	char digit_1 = '\0';
	char digit_2 = '\0';
	char digit_3 = '\0';
	char digit_4 = '\0';
	
	static char humidity_level[4];
	
	first_digit = (value/100)%10;
	second_digit = (value/10)%10;
	third_digit = value%10;
	
	if(first_digit == 0)
	{
		if(second_digit == 0)
		{
			digit_1 = third_digit + '0';
			digit_2 = '\0';
		}
		else
		{
			digit_1 = second_digit + '0';
			digit_2 = third_digit + '0';
			digit_3 = '\0';
		}
	}
	else
	{
		digit_1 = first_digit + '0';
		digit_2 = second_digit + '0';
		digit_3 = third_digit + '0';
		digit_4 = '\0';
	}
	
	humidity_level[0] = digit_1;
	humidity_level[1] = digit_2;
	humidity_level[2] = digit_3;
	humidity_level[3] = digit_4;
	
	return humidity_level;
}

// displays humidity percentage level read from every sensor
void display_umidity_level_values(int umidity_level_sensor_1, int umidity_level_sensor_2)
{
	int sensor_1_display_offset = strlen(SENSOR_1_TITLE);
	int sensor_2_display_offset = strlen(SENSOR_2_TITLE);
	
	put_Char_LCD_Display(0x80 + sensor_1_display_offset, 0);
	put_string(humidity_level_int_value_to_string(umidity_level_sensor_1));
	put_string(HUMIDITY_LEVEL_UNIT);
	put_Char_LCD_Display(0xC0 + sensor_2_display_offset, 0);
	put_string(humidity_level_int_value_to_string(umidity_level_sensor_2));
	put_string(HUMIDITY_LEVEL_UNIT);
}
