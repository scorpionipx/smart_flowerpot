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
#include "IPX_ADC.h"

void init_Strings(void)
{
	strcpy(authors,"                Nicolae-Danut Popa                 ");
	strcpy(info,"               Controlul motorului pas-cu-pas                 ");
}

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
	init_Strings();
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

void display_Info(void)
{
	put_Char_LCD_Display(0xC0,0);
	for(int i = 0;i < 16; i ++)
	{
		put_Char_LCD_Display(info[i + ch_index],1);
	}
	ch_index ++;
	if (ch_index >= 47)
	{
		ch_index = 0;
	}
	_delay_ms(250);
}

void display_Authors(void)
{
	put_Char_LCD_Display(0xC0,0);
	for(int i = 0;i < 16; i ++)
	{
		put_Char_LCD_Display(authors[i + ch_index],1);
	}
	ch_index ++;
	if (ch_index >= 35)
	{
		ch_index = 0;
	}
	_delay_ms(250);
}

void display_Duty_Cycle_L(void)
{
	unsigned int percentage = OCR1A/8;
	put_Char_LCD_Display(0xCC,0);
	put_Char_LCD_Display((percentage/100)%10 + 48,1);
	put_Char_LCD_Display((percentage/10)%10 + 48,1);
	put_Char_LCD_Display(percentage%10 + 48,1);
	_delay_ms(500);
}

void display_Duty_Cycle_R(void)
{
	unsigned int percentage = OCR1B/8;
	put_Char_LCD_Display(0xCC,0);
	put_Char_LCD_Display((percentage/100)%10 + 48,1);
	put_Char_LCD_Display((percentage/10)%10 + 48,1);
	put_Char_LCD_Display(percentage%10 + 48,1);
	_delay_ms(500);
}

void display_Speed(void)
{
	int voltage_mv = Get_ADC_Voltage();
	put_Char_LCD_Display(0xCB,0);
	put_Char_LCD_Display((voltage_mv/1000)%10 + 48,1);
	put_Char_LCD_Display((voltage_mv/100)%10 + 48,1);
	put_Char_LCD_Display((voltage_mv/10)%10 + 48,1);
	put_Char_LCD_Display(voltage_mv%10 + 48,1);
	_delay_ms(500);
}