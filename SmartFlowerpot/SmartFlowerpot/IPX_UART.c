/*
 * IPX_UART.c
 *
 * Created: 02.04.2016 00:49:25
 *  Author: Dan
 */ 

#include "Global.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "IPX_UART.h"

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#define UART_DELAY 3

unsigned char received_command;

void init_UART(void)
{
	UCSRB = (1 << RXEN) | (1 << TXEN);   // Turn on the transmission and reception circuitry
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Use 8-bit character sizes

	UBRRH = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
	UBRRL = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register

	UCSRB |= (1 << RXCIE); // Enable the USART Recieve Complete interrupt (USART_RXC)
}

ISR(USART_RXC_vect)
{
	received_command = UDR; // Fetch the received byte value into the variable "ByteReceived"
	//UDR = received_command; // Echo back the received byte back to the computer
}

void send_uart_8bits_data(unsigned char ID, unsigned char data)
{
	// mark start of transmission
	UDR = 0;
	_delay_ms(UART_DELAY);
	UDR = 0;
	_delay_ms(UART_DELAY);
	
	UDR = ID;
	_delay_ms(UART_DELAY);
	UDR = data;
	_delay_ms(UART_DELAY);
}