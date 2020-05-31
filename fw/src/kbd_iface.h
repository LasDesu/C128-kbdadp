/*
 * kbd_iface.h
 *
 *  Created on: 19 апр. 2018 г.
 *      Author: las
 */

#ifndef KBD_IFACE_H_
#define KBD_IFACE_H_

#define KBD_GPIO_OFF 5

#define PLED_CAPS	4
#define PLED_NUM	2
#define PLED_SCROLL	1

extern unsigned char kbd_flags;

int kbd_loop();

void key_press( unsigned col, unsigned char mask );
void key_release( unsigned col, unsigned char mask );

void key_caps_set( int state );
void key_4080_set( int state );
void key_restore_set( int state );

void key_update_flags();

int kbd_process( unsigned char scan );
void kbd_scan_reset();
int kbd_set_leds( unsigned char lights );

void ps2_clock_out();
void ps2_clock_set( unsigned state );
void ps2_clock_in();
unsigned ps2_clock_get();

void ps2_data_out();
void ps2_data_set( unsigned state );
void ps2_data_in();
unsigned ps2_data_get();

void dbg_kbd_led_set( unsigned state );

#endif /* KBD_IFACE_H_ */
