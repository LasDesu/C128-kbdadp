/*
 * timer.c
 *
 *  Created on: 10 янв. 2016 г.
 *      Author: las
 */

#include <stm32f10x_it.h>
#include <stm32f10x.h>
#include "timer.h"


// ----------------------------------------------------------------------------

volatile timer_ticks_t timer_ticks;

// ----------------------------------------------------------------------------

void
timer_init( void )
{
	timer_ticks = 0;
	// Use SysTick as reference for the delay loops.
	SysTick_Config (SystemCoreClock / TIMER_FREQUENCY_HZ);
}

void
timer_sleep( timer_ticks_t ticks )
{
	timer_ticks_t wait_till = timer_ticks + ticks;

	// Busy wait until the SysTick decrements the counter to zero.
	while ( wait_till > timer_ticks )
		;
}

void timer_usleep( unsigned pause )
{
	timer_sleep( pause );
}

void timer_msleep( unsigned pause )
{
	timer_sleep( pause * 1000 );
}

timestamp_t timer_timestamp()
{
	return timer_ticks;
}

int timer_expired_ms( timestamp_t ts, unsigned timeout )
{
	return timer_ticks >= (ts + timeout * 1000ull);
}

// ----- SysTick_Handler() ----------------------------------------------------

void
SysTick_Handler (void)
{
	timer_ticks ++;
}
