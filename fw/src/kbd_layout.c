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

#define LOCK_SHIFT	PLED_CAPS
#define LOCK_CAPS	PLED_SCROLL
#define CURS_MODE	PLED_NUM
#define LOCK_4080	8
#define MOD_SHIFT	16
unsigned char kbd_flags = CURS_MODE; /* enable 64 cursor keys emulation by default */

struct kbd_bind
{
	unsigned scan;
	unsigned char key;
};

#define PKEY_NONE KEY_NONE

/* keys layout */
#define PKEY_ESC		KEY_ESC

#define PKEY_F1			KEY_COMMODORE
#define PKEY_F2			KEY_RUNSTOP
#define PKEY_F3			KEY_POUND
#define PKEY_F4			KEY_CAPSLOCK
#define PKEY_F5			KEY_HELP
#define PKEY_F6			KEY_LINEFEED
#define PKEY_F7			KEY_4080
#define PKEY_F8			KEY_NOSCROLL
#define PKEY_F9			KEY_F1
#define PKEY_F10		KEY_F3
#define PKEY_F11		KEY_F5
#define PKEY_F12		KEY_F7

#define PKEY_TILDE		KEY_LEFTARR
#define PKEY_1			KEY_1
#define PKEY_2			KEY_2
#define PKEY_3			KEY_3
#define PKEY_4			KEY_4
#define PKEY_5			KEY_5
#define PKEY_6			KEY_6
#define PKEY_7			KEY_7
#define PKEY_8			KEY_8
#define PKEY_9			KEY_9
#define PKEY_0			KEY_0
#define PKEY_MINUS		KEY_MINUS
#define PKEY_EQUAL		KEY_PLUS
#define PKEY_BACKSLASH	KEY_CARET
#define PKEY_BACKSPACE	KEY_INSDEL

#define PKEY_TAB		KEY_TAB
#define PKEY_Q			KEY_Q
#define PKEY_W			KEY_W
#define PKEY_E			KEY_E
#define PKEY_R			KEY_R
#define PKEY_T			KEY_T
#define PKEY_Y			KEY_Y
#define PKEY_U			KEY_U
#define PKEY_I			KEY_I
#define PKEY_O			KEY_O
#define PKEY_P			KEY_P
#define PKEY_LBRACE		KEY_AT
#define PKEY_RBRACE		KEY_ASTERISK

#define PKEY_CAPSLOCK	KEY_SHFTLOCK
#define PKEY_A			KEY_A
#define PKEY_S			KEY_S
#define PKEY_D			KEY_D
#define PKEY_F			KEY_F
#define PKEY_G			KEY_G
#define PKEY_H			KEY_H
#define PKEY_J			KEY_J
#define PKEY_K			KEY_K
#define PKEY_L			KEY_L
#define PKEY_SEMICOLON	KEY_COLON
#define PKEY_QUOTE		KEY_SEMICOLON
#define PKEY_RETURN		KEY_RETURN

#define PKEY_LSHIFT		KEY_LSHIFT
#define PKEY_Z			KEY_Z
#define PKEY_X			KEY_X
#define PKEY_C			KEY_C
#define PKEY_V			KEY_V
#define PKEY_B			KEY_B
#define PKEY_N			KEY_N
#define PKEY_M			KEY_M
#define PKEY_COMMA		KEY_COMMA
#define PKEY_PERIOD		KEY_PERIOD
#define PKEY_SLASH		KEY_SLASH
#define PKEY_RSHIFT		KEY_RSHIFT

#define PKEY_LCTRL		KEY_CTRL
#define PKEY_LWIN		KEY_COMMODORE
#define PKEY_LALT		KEY_ALT
#define PKEY_SPACE		KEY_SPACE
#define PKEY_RALT		KEY_ALT
#define PKEY_RCTRL		KEY_CTRL

#define PKEY_PRTSRC		KEY_RESTORE
#define PKEY_SCRLOCK	KEY_NONE
#define PKEY_INSERT		KEY_POUND
#define PKEY_DELETE		KEY_EQUAL
#define PKEY_HOME		KEY_CLRHOME
#define PKEY_END		KEY_NONE
#define PKEY_PAGEUP		KEY_CURV
#define PKEY_PAGEDOWN	KEY_CURH

#define PKEY_UP			KEY_UP
#define PKEY_DOWN		KEY_DOWN
#define PKEY_LEFT		KEY_LEFT
#define PKEY_RIGHT		KEY_RIGHT

#define PKEY_NUMLOCK	KEY_CURSMODE	// C128 mode maybe?
#define PKEY_KP_0		KEY_KP_0
#define PKEY_KP_1		KEY_KP_1
#define PKEY_KP_2		KEY_KP_2
#define PKEY_KP_3		KEY_KP_3
#define PKEY_KP_4		KEY_KP_4
#define PKEY_KP_5		KEY_KP_5
#define PKEY_KP_6		KEY_KP_6
#define PKEY_KP_7		KEY_KP_7
#define PKEY_KP_8		KEY_KP_8
#define PKEY_KP_9		KEY_KP_9
#define PKEY_KP_PERIOD	KEY_KP_PERIOD
#define PKEY_KP_DIV		KEY_NONE
#define PKEY_KP_MUL		KEY_NONE
#define PKEY_KP_MINUS	KEY_KP_MINUS
#define PKEY_KP_PLUS	KEY_KP_PLUS
#define PKEY_KP_ENTER	KEY_KP_ENTER

/* create tables */
#include "ps2scans.h"

static inline void update_shift()
{
	if ( kbd_flags & (LOCK_SHIFT | MOD_SHIFT) )
		key_press( KBD_COL1, 1 << KBD_ROW7 );
	else
		key_release( KBD_COL1, 1 << KBD_ROW7 );
}

void key_update_flags()
{
	kbd_set_leds( kbd_flags & 7 );
	update_shift();
	key_caps_set( kbd_flags & LOCK_CAPS );
	key_4080_set( kbd_flags & LOCK_4080 );
}

void kbd_scan_reset()
{
	kbd_break = 0;
	scan_prefix = 0;
}

static inline void do_key( unsigned char key, char press )
{
	unsigned char col, rows;

	col = key & 0xF;
	rows = 1 << (key >> 4);

	if ( press )
		key_press( col, rows );
	else
		key_release( col, rows );
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
		if ( (scan < 0x68) || (scan >= 0x80) )
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
		else
		{
			key = scan_set_extra_68[scan - 0x68];
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
					break;
				case KEY_CURSMODE:
					kbd_flags ^= CURS_MODE;
					kbd_set_leds( kbd_flags & 7 );
					break;
				}
			}
		}
		else
		{
			unsigned char curs_emu = 0, curs_shift = 0;
			static unsigned char real_rshift = 0;

			/* save for cursor emulation */
			if ( key == KEY_RSHIFT )
				real_rshift = !kbd_break;

			/* cursor emulation for C64 */
			if ( kbd_flags & CURS_MODE )
			{
				switch ( key )
				{
				case KEY_LEFT:
					curs_shift = 1;
					/* no break */
				case KEY_RIGHT:
					curs_emu = KEY_CURH;
					break;
				case KEY_UP:
					curs_shift = 1;
					/* no break */
				case KEY_DOWN:
					curs_emu = KEY_CURV;
					break;
				}
			}

			if ( curs_emu )
			{
				/* do emulation */
				if ( kbd_break )
				{
					do_key( curs_emu, 0 );
					do_key( KEY_RSHIFT, real_rshift );
				}
				else
				{
					do_key( KEY_RSHIFT, curs_shift );
					do_key( curs_emu, 1 );
				}
			}
			else
			{
				/* do real key */
				do_key( key, !kbd_break );
			}
		}
	}

	kbd_break = 0;
	scan_prefix = 0;
	dbg_kbd_led_set( 1 );

	return 0;
}
