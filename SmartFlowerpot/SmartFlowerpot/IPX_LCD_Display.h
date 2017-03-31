/*
 * IPX_LCD_Display.h
 *
 * Created: 22.03.2016 17:00:16
 *  Author: Dan
 */ 

/*PIN CONFIGURATION*/
/* D4 -> PC4          */
/* D5 -> PC5          */
/* D6 -> PC6          */
/* D7 -> PC7          */
/* RS -> PC0          */
/* E  -> PC1          */
/* SPEEDSENSOR -> PA0 */


#ifndef IPX_LCD_DISPLAY_H_
#define IPX_LCD_DISPLAY_H_

void put_Char_LCD_Display(int ch, int type);
void init_LCD_Display(void);
void display_Authors(void);
void display_Info(void);
void display_Duty_Cycle_L(void);
void display_Duty_Cycle_R(void);
void display_Speed(void);

#endif /* IPX_LCD_DISPLAY_H_ */