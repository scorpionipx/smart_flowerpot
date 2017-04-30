/*
 * Menu.c
 *
 * Created: 4/8/2017 7:30:23 PM
 *  Author: ScorpionIPX
 */ 
#include "Global.h"
#include <string.h>
#include <util/delay.h>
#include "Global.h"
#include "IPX_LCD_Display.h"
#include "Menu.h"

void next_menu()
{
	switch(MENU)
	{
		case SENSOR_VALUES_MENU:
		{
			change_menu(CLOCK_MENU);
			break;
		}
		
		case CLOCK_MENU:
		{
			change_menu(TANK_WATER_LEVEL_MENU);
			break;
		}
		
		case TANK_WATER_LEVEL_MENU:
		{
			change_menu(BATTERY_LEVEL_MENU);
			break;
		}

		case BATTERY_LEVEL_MENU:
		{
			change_menu(SENSOR_VALUES_MENU);
			break;
		}
		
	}
}

void change_menu(char menu)
{
	if(menu == MENU)
	{
		return;
	}
	
	short int i;
	char menu_ok = FALSE;
	for(i = 0;i < 10; i++)
	{
		if (menu == MENUs[i])
		{
			menu_ok = TRUE;
			MENU = MENUs[i];
			break;
		}
	}
	if(menu_ok)
	{
		set_menu_title(MENU);
	}
	else
	{
		strcpy(ERROR, ERROR_WRONG_MENU);
		MENU = ERROR_MENU;
		set_menu_title(MENU);
	}
	_delay_ms(15);
}

void set_menu_title(char menu)
{
	switch(menu)
	{
		case ERROR_MENU:
		{
			display_error_title();
			break;
		}
		case BATTERY_LEVEL_MENU:
		{
			display_battery_title();
			break;
		}
		case SENSOR_VALUES_MENU:
		{
			display_umidity_level_title();
			break;
		}
		case CLOCK_MENU:
		{
			display_clock_title();
			break;
		}
		case TANK_WATER_LEVEL_MENU:
		{
			display_tank_water_level_title();
			break;
		}
		default:
		{
			strcpy(ERROR, ERROR_WRONG_MENU_TITLE);
			display_error_title();
			break;
		}
	}
}