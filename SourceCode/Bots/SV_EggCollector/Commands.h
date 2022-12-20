#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press A once to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 1},
	
	//----------Complete [3,4]----------
	{HOME,1},
	{NOTHING, 4},
	
	//----------Sandwich [3,30]----------
	// move up to table (5,6)
	{UP, 5},		// move up to basket
	{NOTHING, 5},
	
	// make sandwich (7,10)
	{A, 24},
	{NOTHING, 4},
	{A, 100},
	{NOTHING, 10},
	
	// move to peanut butter sandwich (11,32)
	{DPAD_RIGHT, 1},
	{NOTHING, 4},
	{DPAD_DOWN, 1},
	{NOTHING, 4},
	
	// make sandwich itself (15,32)
	{A_SPAM, 40},	// confirm
	{NOTHING, 150},
	{UP, 30},		// put bananas
	{DOWN, 4},
	{DOWN | A, 12},
	{UP, 30},
	{DOWN, 4},
	{DOWN | A, 12},
	{UP, 30},
	{DOWN, 4},
	{DOWN | A, 12},
	{UP, 30},
	{A_SPAM, 320},	// put top bread & pin
	{NOTHING, 400},
	{A, 4},
	{NOTHING, 20},
	{DOWN, 1},		// move down to basket
	{NOTHING, 20},
	
	//----------Collect Egg [33,35]----------
	{NOTHING, 3330}, // delay until 3 min
	{A_SPAM, 360},
	{B_SPAM, 60},
};