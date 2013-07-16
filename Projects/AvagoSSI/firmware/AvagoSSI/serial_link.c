/*
 * serial_link.c
 *
 *  Created on: May 1, 2013
 *      Author: cody
 */


#include "serial_link.h"

/*
volatile char * output_buffer[10]; // Buffer Storage
volatile u8 output_string_index;	// Outer Index
volatile u8 output_char_index;		// Inner index

volatile char * input_buffer[10]; 	// Buffer Storage
volatile u8 input_string_index;		// Outer Index
volatile u8 input_char_index;		// Inner Index
*/

/**
 *
 */
void serial_initialize(u32 baud)
{
	usart_set_baudrate(USART, baud);
	usart_set_databits(USART, 8);
	usart_set_stopbits(USART, USART_STOPBITS_1);
	usart_set_parity(USART, USART_PARITY_NONE);
	usart_set_flow_control(USART, USART_FLOWCONTROL_NONE);
	usart_enable(USART);
	usart_enable_rx_interrupt(USART);
	//usart_enable_tx_interrupt(USART);
}

/**
 *
 */
/*
void flush_tx_buffer(void)
{

}*/

/**
 *
 */
/*
void send_string (char * string)
{

}*/

/**
 *
 */
void send_string_blocking(char * string)
{
	u16 len = strlen(string);
	u16 i;
	for(i = 0; i < len; i++)
	{
		usart_send_blocking(USART, string[i]);
	}
}

/**
 *
 */
bool send_byte(u8 byte)
{
	if(USART_SR(USART) & USART_SR_TXE)
	{
		USART_DR(USART) =  byte;
		return true;
	}
	return false;
}

/**
 *
 */
void isr_usart2(void)
{
	USART_SR(USART) &= ~(USART_SR_RXNE); // Clear Rx Flag
	// Check and clear flag
}

