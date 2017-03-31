/*
 * SmartFlowerpot.c
 *
 * Created: 2/18/2017 4:13:13 PM
 * Author : ScorpionIPX
 */ 

#include "Global.h"
#include <avr/io.h>
#include "IPX_LCD_Display.h"


int main(void)
{
	init_LCD_Display();
	put_Char_LCD_Display(0xC0, 0);
	put_Char_LCD_Display('P', 1);
	put_Char_LCD_Display('a', 1);
	put_Char_LCD_Display('u', 1);
	put_Char_LCD_Display('l', 1);
	put_Char_LCD_Display('i', 1);
	put_Char_LCD_Display('c', 1);
	put_Char_LCD_Display('i', 1);
    while (1) 
    {
    }
}

