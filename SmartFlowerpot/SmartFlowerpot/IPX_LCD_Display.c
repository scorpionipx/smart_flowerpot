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

#define MAX_CHARS_PER_ROW 16

void init_custom_characters();
void init_custom_character_level();

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
	init_custom_characters();
}

void init_custom_character_level()
{
	switch(WATER_LEVEL)
	{
		case 0:
		{
			// tank water level 0
			put_Char_LCD_Display(80, 0);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			break;
		}
		case 1:
		{
			// tank water level 1
			put_Char_LCD_Display(80, 0);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			break;
		}
		case 2:
		{
			// tank water level 2
			put_Char_LCD_Display(80, 0);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			break;
		}
		case 3:
		{
			// tank water level 3
			put_Char_LCD_Display(80, 0);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			break;
		}
		case 4:
		{
			// tank water level 4
			put_Char_LCD_Display(80, 0);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			break;
		}
		case 5:
		{
			// tank water level 5
			put_Char_LCD_Display(80, 0);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			break;
		}
		case 6:
		{
			// tank water level 6
			put_Char_LCD_Display(80, 0);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b11111, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			break;
		}
		default:
		{
			// tank water level 0
			put_Char_LCD_Display(80, 0);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b00000, 1);
			put_Char_LCD_Display(0b11111, 1);
			break;
		}
	}
}

void init_custom_characters()
{
	// tank water level start character
	put_Char_LCD_Display(64, 0);
	put_Char_LCD_Display(0b00001, 1);
	put_Char_LCD_Display(0b00001, 1);
	put_Char_LCD_Display(0b00001, 1);
	put_Char_LCD_Display(0b00001, 1);
	put_Char_LCD_Display(0b00011, 1);
	put_Char_LCD_Display(0b00111, 1);
	put_Char_LCD_Display(0b01101, 1);
	put_Char_LCD_Display(0b11001, 1);
	
	// tank water level end character
	put_Char_LCD_Display(72, 0);
	put_Char_LCD_Display(0b10000, 1);
	put_Char_LCD_Display(0b10000, 1);
	put_Char_LCD_Display(0b10000, 1);
	put_Char_LCD_Display(0b10000, 1);
	put_Char_LCD_Display(0b11000, 1);
	put_Char_LCD_Display(0b11100, 1);
	put_Char_LCD_Display(0b10110, 1);
	put_Char_LCD_Display(0b10011, 1);
}

// display string
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
	int index;
	
	put_Char_LCD_Display(0x01,0); // clear LCD
	
	put_Char_LCD_Display(0x80, 0);
	put_string(SENSOR_1_TITLE);
	for(index = 0; index<MAX_CHARS_PER_ROW-(strlen(SENSOR_1_TITLE)) - 1; index++)
	{
		put_Char_LCD_Display(' ', 1);
	}
	
	put_Char_LCD_Display(0xC0, 0);
	put_string(SENSOR_2_TITLE);
	for(index = 0; index<MAX_CHARS_PER_ROW-(strlen(SENSOR_2_TITLE)) - 1; index++)
	{
		put_Char_LCD_Display(' ', 1);
	}
}

// displays error title
void display_error_title()
{	
	put_Char_LCD_Display(0x01,0); // clear LCD
	
	put_Char_LCD_Display(0x80, 0);
	put_string(ERROR_TITLE);
}

// displays battery level title
void display_battery_title()
{
	put_Char_LCD_Display(0x01,0); // clear LCD
	
	put_Char_LCD_Display(0x80, 0);
	put_string(BATTERY_TITLE);
}

void display_error()
{
	put_Char_LCD_Display(0xC0, 0);
	put_string(ERROR);
}

// display tank water level title
void display_tank_water_level_title()
{
	put_Char_LCD_Display(0x01,0); // clear LCD
	
	put_Char_LCD_Display(0x80, 0); // go to row 0, column 0
	put_string(TANK_WATER_LEVEL_TITLE);
}

void display_tank_water_level()
{
	init_custom_character_level(WATER_LEVEL);
	put_Char_LCD_Display(0xC0, 0);
	put_Char_LCD_Display(SPECIAL_CHARACTER_TANK_LEVEL_START, 1);
	for(short i = 0; i < 8; i++)
	{
		put_Char_LCD_Display(SPECIAL_CHARACTER_TANK_WATER_LEVEL, 1);
	}
	put_Char_LCD_Display(SPECIAL_CHARACTER_TANK_LEVEL_END, 1);
}

// self made itoa
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
void display_umidity_level_values()
{
	int sensor_1_display_offset = strlen(SENSOR_1_TITLE);
	int sensor_2_display_offset = strlen(SENSOR_2_TITLE);
	
	put_Char_LCD_Display(0x80 + sensor_1_display_offset, 0);
	put_string(humidity_level_int_value_to_string(humidity_level_sensor_1));
	put_string(HUMIDITY_LEVEL_UNIT);
	put_string("  ");
	
	put_Char_LCD_Display(0xC0 + sensor_2_display_offset, 0);
	put_string(humidity_level_int_value_to_string(humidity_level_sensor_2));
	put_string(HUMIDITY_LEVEL_UNIT);
	put_string("  ");
}


void display_clock_title()
{	
	put_Char_LCD_Display(0x01,0);
	
	put_Char_LCD_Display(0x80, 0);
	put_string(CLOCK_DATE_TITLE);
	
	put_Char_LCD_Display(0xC0, 0);
	put_string(CLOCK_TIME_TITLE);
}

void display_initializing_message()
{
	put_Char_LCD_Display(0x01,0);
	
	put_Char_LCD_Display(0x80, 0);
	put_string("Initializing...");
}

void display_clock_values()
{
	int clock_date_display_offset = strlen(CLOCK_DATE_TITLE);
	int clock_time_display_offset = strlen(CLOCK_TIME_TITLE) + 1;
	
	put_Char_LCD_Display(0x80 + clock_date_display_offset, 0);
	put_string(" 30 APR 2017");
	
	put_Char_LCD_Display(0xC0 + clock_time_display_offset, 0);
	put_Char_LCD_Display('0' + CLOCK.H/10, 1);
	put_Char_LCD_Display('0' + CLOCK.H%10, 1);
	put_Char_LCD_Display(':', 1);
	put_Char_LCD_Display('0' + CLOCK.M/10, 1);
	put_Char_LCD_Display('0' + CLOCK.M%10, 1);
	put_Char_LCD_Display(':', 1);
	put_Char_LCD_Display('0' + CLOCK.S/10, 1);
	put_Char_LCD_Display('0' + CLOCK.S%10, 1);
}

void display_values()
{
	switch(MENU)
	{
		case CLOCK_MENU:
		{
			display_clock_values();
			break;
		}
		case BATTERY_LEVEL_MENU:
		{
			put_Char_LCD_Display(0xC0, 0);
			put_string("battery");
			break;
		}
		case SENSOR_VALUES_MENU:
		{
			display_umidity_level_values();
			break;
		}
		case ERROR_MENU:
		{
			display_error();
			break;
		}
		case TANK_WATER_LEVEL_MENU:
		{
			display_tank_water_level();
			break;
		}
		default:
		{
			put_Char_LCD_Display(0xC0, 0);
			put_string("fatal error");
			break;
		}
	}
}

