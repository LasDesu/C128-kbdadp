/*
 * timer.h
 *
 *  Created on: 10 янв. 2016 г.
 *      Author: las
 */

#ifndef TIMER_H_
#define TIMER_H_

#define TIMER_FREQUENCY_HZ 1000000
typedef uint64_t timer_ticks_t;
typedef timer_ticks_t timestamp_t;

void timer_init( void );
void timer_sleep( timer_ticks_t ticks );

void timer_usleep( unsigned pause );
void timer_msleep( unsigned pause );

timestamp_t timer_timestamp();
int timer_expired_ms( timestamp_t ts, unsigned timeout );

#endif /* TIMER_H_ */
