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
	display_umidity_level_title();
	display_umidity_level_values(8, 87);
    while (1) 
    {
    }
}

