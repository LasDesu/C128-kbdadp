/*
 * kbd_layout.c
 *
 *  Created on: 18 апр. 2018 г.
 *      Author: las
 */

#include "kbd_iface.h"

#include "c128keys.h"

static int kbd_break = 0;
static unsigned scan_prefix = 0;

static unsigned kbd_flags = 0;
#define LOCK_SHIFT	4
#define LOCK_CAPS	2
#define LOCK_4080	1
#define MOD_SHIFT	16

struct kbd_bind
{
	unsigned scan;
	unsigned char key;
};

static const unsigned char scan_set_main[] =
{
//		0				1				2				3				4				5				6				7
//		8				9				A				B				C				D				E				F
	KEY_NONE,		KEY_F1,			KEY_NONE,		KEY_HELP,		KEY_POUND,		KEY_COMMODORE,	KEY_RUNSTOP,	KEY_F7,			// 00
	KEY_NONE,		KEY_F3,			KEY_NOSCROLL,	KEY_LINEFEED,	KEY_CAPSLOCK,	KEY_TAB,		KEY_LEFTARR,	KEY_NONE,		// 08

	KEY_NONE,		KEY_ALT,		KEY_LSHIFT,		KEY_NONE,		KEY_CTRL,		KEY_Q,			KEY_1,			KEY_NONE,		// 10
	KEY_NONE,		KEY_NONE,		KEY_Z,			KEY_S,			KEY_A,			KEY_W,			KEY_2,			KEY_NONE,		// 18

	KEY_NONE,		KEY_C,			KEY_X,			KEY_D,			KEY_E,			KEY_4,			KEY_3,			KEY_NONE,		// 20
	KEY_NONE,		KEY_SPACE,		KEY_V,			KEY_F,			KEY_T,			KEY_R,			KEY_5,			KEY_NONE,		// 28

	KEY_NONE,		KEY_N,			KEY_B,			KEY_H,			KEY_G,			KEY_Y,			KEY_6,			KEY_NONE,		// 30
	KEY_NONE,		KEY_NONE,		KEY_M,			KEY_J,			KEY_U,			KEY_7,			KEY_8,			KEY_NONE,		// 38

	KEY_NONE,		KEY_COMMA,		KEY_K,			KEY_I,			KEY_O,			KEY_0,			KEY_9,			KEY_NONE,		// 40
	KEY_NONE,		KEY_PERIOD,		KEY_SLASH,		KEY_L,			KEY_COLON,		KEY_P,			KEY_MINUS,		KEY_NONE,		// 48

	KEY_NONE,		KEY_NONE,		KEY_SEMICOLON,	KEY_NONE,		KEY_AT,			KEY_PLUS,		KEY_NONE,		KEY_NONE,		// 50
	KEY_SHFTLOCK,	KEY_RSHIFT,		KEY_RETURN,		KEY_ASTERISK,	KEY_NONE,		KEY_CARET,		KEY_NONE,		KEY_NONE,		// 58

	KEY_NONE,		KEY_NONE,		KEY_NONE,		KEY_NONE,		KEY_NONE,		KEY_NONE,		KEY_INSDEL,		KEY_NONE,		// 60
	KEY_NONE,		KEY_KP_1,		KEY_NONE,		KEY_KP_4,		KEY_KP_7,		KEY_NONE,		KEY_NONE,		KEY_NONE,		// 68

	KEY_KP_0,		KEY_KP_PERIOD,	KEY_KP_2,		KEY_KP_5,		KEY_KP_6,		KEY_KP_8,		KEY_ESC,		KEY_NONE,		// 70
	KEY_F5,			KEY_KP_PLUS,	KEY_KP_3,		KEY_KP_MINUS,	KEY_NONE,		KEY_KP_9,		KEY_NONE,		KEY_NONE,		// 78

	KEY_NONE,		KEY_NONE,		KEY_NONE,		KEY_4080,		KEY_NONE,		KEY_NONE,		KEY_NONE,		KEY_NONE,		// 80
};

static const struct kbd_bind scan_set_extra[] =
{
	{ 0xE014, KEY_CTRL },		// right control
	{ 0xE011, KEY_ALT },		// right alt
	{ 0xE07D, KEY_CURV },		// page up
	{ 0xE07A, KEY_CURH },		// page down
	{ 0xE070, KEY_POUND },		// insert
	{ 0xE071, KEY_EQUAL },		// delete
	{ 0xE06C, KEY_CLRHOME },	// home
	{ 0xE07C, KEY_RESTORE },	// print screen
	{ 0xE01F, KEY_COMMODORE },	// left winkey
	{ 0, KEY_NONE }
};

static inline void update_shift()
{
	if ( kbd_flags & (LOCK_SHIFT | MOD_SHIFT) )
		key_press( KBD_COL1, 1 << KBD_ROW7 );
	else
		key_release( KBD_COL1, 1 << KBD_ROW7 );
}

void kbd_scan_reset()
{
	kbd_break = 0;
	scan_prefix = 0;
}

int kbd_process( unsigned char scan )
{
	unsigned char key = KEY_NONE;

	dbg_kbd_led_set( 0 );

	if ( scan == 0xF0 )
	{
		kbd_break = 1;
		return 0;
	}

	if ( scan == 0xE0 )
	{
		//scan_prefix <<= 8;
		scan_prefix = scan;
		return 0;
	}

	if ( !scan_prefix && (scan < sizeof(scan_set_main)) )
	{
		key = scan_set_main[scan];
	}
	else
	{
		const struct kbd_bind *b = scan_set_extra;
		unsigned pscan = scan | (scan_prefix << 8);

		while ( b->key != KEY_NONE )
		{
			if ( b->scan == pscan )
			{
				key = b->key;
				break;
			}

			b ++;
		}
	}

	if ( key != KEY_NONE )
	{
		if ( key & KEY_SPECIAL )
		{
			if ( key == KEY_SHIFT )
			{
				if ( kbd_break )
					kbd_flags &= ~MOD_SHIFT;
				else
					kbd_flags |= MOD_SHIFT;

				update_shift();
			}
			else if ( key == KEY_RESTORE )
			{
				key_restore_set( !kbd_break );
			}
			else if ( !kbd_break )
			{
				switch ( key )
				{
				case KEY_SHFTLOCK:
					kbd_flags ^= LOCK_SHIFT;
					update_shift();
					kbd_set_leds( kbd_flags & 7 );
					break;
				case KEY_CAPSLOCK:
					kbd_flags ^= LOCK_CAPS;
					key_caps_set( kbd_flags & LOCK_CAPS );
					kbd_set_leds( kbd_flags & 7 );
					break;
				case KEY_4080:
					kbd_flags ^= LOCK_4080;
					key_4080_set( kbd_flags & LOCK_4080 );
					kbd_set_leds( kbd_flags & 7 );
					break;
				}
			}
		}
		else
		{
			unsigned col, rows;

			col = key & 0xF;
			rows = 1 << (key >> 4);

			if ( kbd_break )
				key_release( col, rows );
			else
				key_press( col, rows );
		}
	}

	kbd_break = 0;
	scan_prefix = 0;
	dbg_kbd_led_set( 1 );

	return 0;
}
