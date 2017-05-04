/*
 * IPX_Buttons.c
 *
 * Created: 4/17/2017 1:16:52 PM
 *  Author: ScorpionIPX
 */ 

#include "Global.h"
#include "IPX_Buttons.h"
#include "IPX_LCD_Display.h"
#include "Menu.h"
#include <util/delay.h>

// INITIALIZE uC PORT FOR BUTTONS READING AND SET BUTTONS DEFAULT VALUE TO FALSE (RELEASED)
void init_buttons()
{
	// SET PORT DIRECTION
	BUTTONS_DDR &= ~(1 << BUTTON_1_PIN | 1 << BUTTON_2_PIN);
	
	// SET DEFAULT VALUE
	BUTTONS_PORT &= ~(1 << BUTTON_1_PIN | 1 << BUTTON_2_PIN);
	
	// GLOBAL BUTTONS STATE TRACKING INITIALIZING
	BUTTON_1_PRESSED = FALSE;
	BUTTON_2_PRESSED = FALSE;
}

//    FUNCTION READS BUTTONS' STATES AND TAKES ACTION ACCORDINGLY TO MACHINE STATE
//    IF A BUTTON IS READ AS PRESSED (VALUE == TRUE), THE FOLLOWING BUTTONS' VALUES 
// WON'T BE READ ANYMORE FOR (BUTTONS_DELAY * 10 MS) (DEFINED IN IPX_BUTTONS.H)
//    BUTTONS PRIORITY: BUTTON_1 -> BUTTON_2 -> BUTTON_3 -> BUTTON_4 -> NO_BUTTON
//    PRESSED_BUTTON USED ONLY FOR TESTING, CAN BE REMOVED 

//    BUTTONS FUNCTIONS:
/*
  =====================================================================================
|| BUTTON // STATE            ANY
  =============================================
||   BUTTON_1   ||       PREVIOUSMENU          ||
||   BUTTON_2   ||         NEXT MENU           ||
  ============================================
*/
void read_buttons()
{
	BUTTON_1_PRESSED = BUTTON_1_VALUE;
	if(BUTTON_1_PRESSED)
	{
		_delay_ms(5);
		next_menu();
		return;
	}
	
	BUTTON_2_PRESSED = BUTTON_2_VALUE;
	if(BUTTON_2_PRESSED)
	{
		return;
	}
}
