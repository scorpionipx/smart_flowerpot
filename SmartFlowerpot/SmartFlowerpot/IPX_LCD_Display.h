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

#define LCD_DELAY_MS 3         // DELAY BETWEEN DATA SENT TO LCD
#define LCD_INIT_DELAY_MS 8    // DELAY BETWEEN DATA SENT TO LCD WHEN INITIALIZING

void put_Char_LCD_Display(int ch, int type);
void init_LCD_Display(void);
void display_umidity_level_title();
void display_umidity_level_values();
void display_clock_title();
void put_string(const char *_string);
void display_clock_values();
void display_initializing_message();
void display_values();
void display_tank_water_level_title();
void display_tank_water_level();
void init_custom_characters();
void init_custom_character_level();
void display_error_title();
void display_battery_title();
void display_temperature_title();
void display_temperature_values();

#endif /* IPX_LCD_DISPLAY_H_ */