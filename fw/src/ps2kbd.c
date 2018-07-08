#include <unistd.h>
#include "timer.h"

#include "kbd_iface.h"

static int kbd_ready = 0;

#define ERR_OK		0
#define ERR_NOACK	1
#define ERR_TIMEOUT	2

static inline int ps2_wait_clock( unsigned state, unsigned timeout )
{
	timestamp_t ts = timer_timestamp();

	while ( ps2_clock_get() != state )
	{
		if ( timeout && timer_expired_ms( ts, timeout ) )
			return ERR_TIMEOUT;
	}

	return 0;
}

static inline int ps2_wait_data( unsigned state, unsigned timeout )
{
	timestamp_t ts = timer_timestamp();

	while ( ps2_data_get() != state )
	{
		if ( timeout && timer_expired_ms( ts, timeout ) )
			return ERR_TIMEOUT;
	}

	return 0;
}

static int ps2_get( unsigned char *pdata, int wait )
{
	unsigned char data = 0;
	unsigned i;
	int ret;

	ps2_data_in();
	ps2_clock_in();

	// start
	ret = ps2_wait_data( 0, wait ? 40 : 0 );
	if ( ret ) return ret;

	// start bit
	ret = ps2_wait_clock( 0, 5 );
	if ( ret ) return ret;
	ret = ps2_wait_clock( 1, 5 );
	if ( ret ) return ret;

	// get data
	for ( i = 0; i < 8; i ++ )
	{
		ret = ps2_wait_clock( 0, 5 );
		if ( ret ) return ret;

		data >>= 1;
		if ( ps2_data_get() )
			data |= 0x80;

		ret = ps2_wait_clock( 1, 5 );
		if ( ret ) return ret;
	}

	// parity bit - skip
	ret = ps2_wait_clock( 0, 5 );
	if ( ret ) return ret;
	ret = ps2_wait_clock( 1, 5 );
	if ( ret ) return ret;
	// stop bit - skip
	ret = ps2_wait_clock( 0, 5 );
	if ( ret ) return ret;
	ret = ps2_wait_clock( 1, 5 );
	if ( ret ) return ret;

	if ( pdata )
		*pdata = data;

	return 0;

}

static int ps2_send( unsigned char data )
{
	unsigned i, cksum;
	int ret;

	ps2_clock_out();
	ps2_clock_set( 0 );
	timer_usleep( 100 );
	ps2_data_out();
	ps2_data_set( 0 );
	timer_usleep( 5 );
	ps2_clock_set( 1 );
	timer_usleep( 5 );
	ps2_clock_in();

	ret = ps2_wait_clock( 0, 30 );
	if ( ret ) goto out;

	// send data
	cksum = 0;
	for ( i = 0; i < 8; i ++ )
	{
		ps2_data_set( data & 1 );
		if ( (data & 1) == 0 )
			cksum ++;
		data >>= 1;

		ret = ps2_wait_clock( 1, 5 );
		if ( ret ) goto out;

		ret = ps2_wait_clock( 0, 5 );
		if ( ret ) goto out;
	}

	// parity bit
	ps2_data_set( cksum & 1 ? 0 : 1 );
	ret = ps2_wait_clock( 1, 5 );
	if ( ret ) goto out;
	ret = ps2_wait_clock( 0, 5 );
	if ( ret ) goto out;

	// stop bit
	ps2_data_set( 1 );
	ret = ps2_wait_clock( 1, 5 );
	if ( ret ) goto out;
	ps2_data_in();
	ret = ps2_wait_clock( 0, 5 );
	if ( ret )
		return ret;

	if ( ps2_data_get() )
		return ERR_NOACK;

	ret = ps2_wait_data( 1, 5 );
	if ( ret )
		return ret;

	return ERR_OK;

out:
	ps2_data_in();
	return ret;
}

static int ps2_command( unsigned char data )
{
	unsigned char ans;
	unsigned try;
	int ret;

	for ( try = 0; try < 5; try ++ )
	{
		ret = ps2_send( data );
		if ( ret ) return ret;

		ret = ps2_get( &ans, 1 );
		if ( ret ) return ret;

		if ( ans == 0xFE )
			continue;	// resend

		if ( ans == 0xFA )
			break;	// acknowledge
	}

	return 0;
}

int kbd_set_leds( unsigned lights )
{
	int ret;

	// send Set/Reset Status Indicators (ED) command
	ret = ps2_command( 0xED );
	if ( ret ) return ret;
	// Turn off all LEDs
	ret = ps2_command( lights );
	if ( ret ) return ret;

	return 0;
}

static int kbd_reset()
{
	int ret;

	kbd_ready = 0;
	kbd_scan_reset();

	// blink LED
	dbg_kbd_led_set( 1 );
	timer_msleep( 250 );
	dbg_kbd_led_set( 0 );

	// send Reset (FF) command
	ret = ps2_command( 0xFF );
	if ( ret )
		goto reset_fail;

	// skip Self-test passed
	ret = ps2_get( NULL, 0 );
	if ( ret )
		goto reset_fail;

	// send Set Default (F6) command
	ret = ps2_command( 0xF6 );
	if ( ret )
		goto reset_fail;

	// send Enable (F4) command
	ret = ps2_command( 0xF4 );
	if ( ret )
		goto reset_fail;

	// send Set/Reset Status Indicators (ED) command
	ret = ps2_command( 0xED );
	if ( ret )
		goto reset_fail;
	// Turn off all LEDs
	ret = ps2_command( 0x00 );
	if ( ret )
		goto reset_fail;

	// enable LED
	dbg_kbd_led_set( 1 );

	kbd_ready = 1;

	return 0;

reset_fail:
	// pause 500ms
	timer_msleep( 500 );

	return ret;
}

int kbd_loop()
{
	unsigned char scan;
	int ret;

	if ( !kbd_ready )
		return kbd_reset();

	ret = ps2_get( &scan, 1 );
	/*if ( ret != ERR_TIMEOUT )
		return ps2_command( 0xFE );	// resend
	else*/ if ( ret )
		return ret;	// invalid

	if ( scan == 0xAA )
	{
		// got "self test passed" - keyboard reconnected?
		kbd_ready = 0;
		return 1;
	}

	return kbd_process( scan );
}
