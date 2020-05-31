#ifndef _C128KEYS_H
#define _C128KEYS_H

#define KEY_NONE	0xFF
#define KEY_SPECIAL	0x80

#define KBD_COL0	4
#define KBD_COL1	5
#define KBD_COL2	6
#define KBD_COL3	7
#define KBD_COL4	8
#define KBD_COL5	9
#define KBD_COL6	10
#define KBD_COL7	0
#define KBD_K0		1
#define KBD_K1		2
#define KBD_K2		3

#define KBD_ROW0	0
#define KBD_ROW1	1
#define KBD_ROW2	2
#define KBD_ROW3	7
#define KBD_ROW4	4
#define KBD_ROW5	5
#define KBD_ROW6	6
#define KBD_ROW7	3

#define K(c, r)		(((KBD_ROW ##r) << 4) | (KBD_COL ##c))
#define X(c, r)		(((KBD_ROW ##r) << 4) | (KBD_K ##c))
#define S(k)		(KEY_SPECIAL | (k))

enum
{
	KEY_SHIFT = KEY_SPECIAL + 1,
	KEY_SHFTLOCK,
	KEY_CAPSLOCK,
	KEY_4080,
	KEY_RESTORE,
	KEY_CURSMODE
};

#define KEY_ESC			X(1, 0)
#define KEY_TAB			X(0, 3)
#define KEY_ALT			X(2, 0)
//#define KEY_CAPS		S(2)

#define KEY_HELP		X(0, 0)
#define KEY_LINEFEED	X(1, 3)
//#define KEY_4080		S(3)
#define KEY_NOSCROLL	X(2, 7)

#define KEY_UP			X(2, 3)
#define KEY_DOWN		X(2, 4)
#define KEY_LEFT		X(2, 5)
#define KEY_RIGHT		X(2, 6)

#define KEY_F1			K(0, 4)
#define KEY_F3			K(0, 5)
#define KEY_F5			K(0, 6)
#define KEY_F7			K(0, 3)

#define KEY_1			K(7, 0)
#define KEY_2			K(7, 3)
#define KEY_3			K(1, 0)
#define KEY_4			K(1, 3)
#define KEY_5			K(2, 0)
#define KEY_6			K(2, 3)
#define KEY_7			K(3, 0)
#define KEY_8			K(3, 3)
#define KEY_9			K(4, 0)
#define KEY_0			K(4, 3)

#define KEY_A			K(1, 2)
#define KEY_B			K(3, 4)
#define KEY_C			K(2, 4)
#define KEY_D			K(2, 2)
#define KEY_E			K(1, 6)
#define KEY_F			K(2, 5)
#define KEY_G			K(3, 2)
#define KEY_H			K(3, 5)
#define KEY_I			K(4, 1)
#define KEY_J			K(4, 2)
#define KEY_K			K(4, 5)
#define KEY_L			K(5, 2)
#define KEY_M			K(4, 4)
#define KEY_N			K(4, 7)
#define KEY_O			K(4, 6)
#define KEY_P			K(5, 1)
#define KEY_Q			K(7, 6)
#define KEY_R			K(2, 1)
#define KEY_S			K(1, 5)
#define KEY_T			K(2, 6)
#define KEY_U			K(3, 6)
#define KEY_V			K(3, 7)
#define KEY_W			K(1, 1)
#define KEY_X			K(2, 7)
#define KEY_Y			K(3, 1)
#define KEY_Z			K(1, 4)

#define KEY_PLUS		K(5, 0)
#define KEY_MINUS		K(5, 3)
#define KEY_POUND		K(6, 0)
#define KEY_AT			K(5, 6)
#define KEY_ASTERISK	K(6, 1)
#define KEY_CARET		K(6, 6)
#define KEY_COLON		K(5, 5)
#define KEY_SEMICOLON	K(6, 2)
#define KEY_EQUAL		K(6, 5)
#define KEY_COMMA		K(5, 7)
#define KEY_PERIOD		K(5, 4)
#define KEY_SLASH		K(6, 7)
#define KEY_LEFTARR		K(7, 1)

#define KEY_SPACE		K(7, 4)
#define KEY_RETURN		K(0, 1)

#define KEY_CLRHOME		K(6, 3)
#define KEY_INSDEL		K(0, 0)
#define KEY_RUNSTOP		K(7, 7)
#define KEY_COMMODORE	K(7, 5)
#define KEY_CURV		K(0, 7)
#define KEY_CURH		K(0, 2)

#define KEY_LSHIFT		KEY_SHIFT	//K(1, 7)
#define KEY_RSHIFT		K(6, 4)
#define KEY_CTRL		K(7, 2)

#define KEY_KP_1		X(0, 7)
#define KEY_KP_2		X(0, 4)
#define KEY_KP_3		X(1, 7)
#define KEY_KP_4		X(0, 5)
#define KEY_KP_5		X(0, 2)
#define KEY_KP_6		X(1, 5)
#define KEY_KP_7		X(0, 6)
#define KEY_KP_8		X(0, 1)
#define KEY_KP_9		X(1, 6)
#define KEY_KP_0		X(2, 1)
#define KEY_KP_PLUS		X(1, 1)
#define KEY_KP_MINUS	X(1, 2)
#define KEY_KP_PERIOD	X(2, 2)
#define KEY_KP_ENTER	X(1, 4)

#endif /* _C128KEYS_H */
