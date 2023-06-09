#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,6]----------
	// Press trigger to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 60},
	{L|R, 1},
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 60},
	
	//----------Complete [7,8]----------
	{HOME,1},
	{NOTHING, 4},
	
	//----------Loop [9,20]----------
	// Shield surf
	{ZL|B|X, 3},
	{ZL|A, 1},
	{NOTHING, 5},
	
	// Dupe
	{PLUS, 10},
	{NOTHING, 1},
	{X, 1},
	{NOTHING, 1},
	{A_SPAM, 10},
	{Y|B, 1},
	{NOTHING, 25},
	
	// Pick items up
	{DOWN, 1},
	{A_SPAM, 12}
};