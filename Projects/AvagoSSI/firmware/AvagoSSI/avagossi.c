/*
 * avagossi.c
 *
 *  Created on: May 1, 2013
 *      Author: cody
 */


#include "avagossi.h"

int main(void)
{
	rcc_clock_setup_in_hsi_out_24mhz(); // Initialize system clock
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPBEN);
	led_initialize();
	aeat9k_initialize();
	aeat9k_read_blocking();
	int i;
	while(1)
	{
		led_toggle();
		for(i = 0; i<80000; i++)
		{
			__asm__("NOP");
		}
	}
	return 0;
}
