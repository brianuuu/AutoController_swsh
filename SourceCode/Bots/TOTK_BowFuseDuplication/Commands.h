#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,6]----------
	// Press A once to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 60},
	{L|R, 1},
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 60},
	
	//----------Loop [7,28]----------
	// fuse material
	{ZR, 1},
	{ZR|DPAD_UP, 4},
	{ZR, 5},
	{X, 15},
	{PLUS, 15},
	
	// drop 1st bow, equip 2nd
	{DPAD_LEFT, 1},
	{A, 1},
	{DPAD_DOWN, 1},
	{A, 10},
	{DPAD_RIGHT, 1},
	{A_SPAM, 6},
	{NOTHING, 10},
	
	// quick pause
	{B, 3},
	{PLUS, 15},
	
	// drop 2nd bow
	{DPAD_LEFT, 1},
	{A, 1},
	{DPAD_DOWN, 1},
	{A, 10},
	
	// pick up bows
	{B, 10},
	{DOWN, 1},
	{A_SPAM, 10},
	{UP, 1},
	
	//----------Complete [29,30]----------
	{HOME,1},
	{NOTHING, 4}
};