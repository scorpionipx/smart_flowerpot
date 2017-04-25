/*
 * IPX_UART.h
 *
 * Created: 02.04.2016 00:59:54
 *  Author: Dan
 */ 


#ifndef IPX_UART_H_
#define IPX_UART_H_

#include "Global.h"

#define TANK_WATER_LEVEL_ID 0x01     // ID FOR UART WATER LEVEL DATA
#define HUMIDITY_SENSOR_1_ID 0x02     // ID FOR UART WATER LEVEL DATA
#define HUMIDITY_SENSOR_2_ID 0x03     // ID FOR UART WATER LEVEL DATA

void init_UART(void);
void send_uart_8bits_data(unsigned char ID, unsigned char data);

#define send_uart_data_tank_water_level() send_uart_8bits_data(TANK_WATER_LEVEL_ID, WATER_LEVEL)
#define send_uart_data_humidity_sensor_1() send_uart_8bits_data(HUMIDITY_SENSOR_1_ID, (unsigned char)humidity_level_sensor_1)
#define send_uart_data_humidity_sensor_2() send_uart_8bits_data(HUMIDITY_SENSOR_2_ID, (unsigned char)humidity_level_sensor_2)

#endif /* IPX_UART_H_ */