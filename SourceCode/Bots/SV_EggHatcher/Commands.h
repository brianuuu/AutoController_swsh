#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press A once to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 1},
	
	//----------Complete [3,4]----------
	{HOME,2},
	{NOTHING, 4},
	
	//----------Box [5,29]----------
	// Pick up eggs (5,17)
	{RIGHT, 3},
	{MINUS, 3},
	{NOTHING, 3},
	{DOWN, 3},
	{DPAD_DOWN, 3},
	{DOWN, 3},
	{DPAD_DOWN, 3},
	{DOWN, 3},		// extra four press to prevent button drop
	{DPAD_DOWN, 3},
	{DOWN, 3},
	{DPAD_DOWN, 3},
	{A, 3},
	{NOTHING, 3},
	
	// put to team + quit (18,29)
	{LEFT, 3},
	{DPAD_LEFT, 3},
	{LEFT, 3},
	{DPAD_LEFT, 3},
	{LEFT, 3},
	{DPAD_LEFT, 3},
	{DOWN, 3},
	{A, 3},
	{NOTHING, 3},
	{B_SPAM, 10},
	{NOTHING, 25},
	{B, 20},
	
	//----------Hatch Eggs [30,46]----------
	{RIGHT, 260},	// 10240->2660
	{RIGHT, 380},	// 8960->2400
	{RIGHT, 220},	// 7680->2020
	{RIGHT, 400},	// 6400->1800
	{RIGHT, 280},	// 5120->1400
	{RIGHT, 360},	// 3840->1120
	{RIGHT, 260},	// 2560->760
	{RIGHT, 500},	// 1280->500
	
	{A_SPAM, 450},
	{RIGHT, 240},
	{A_SPAM, 450},
	{RIGHT, 240},
	{A_SPAM, 450},
	{RIGHT, 240},
	{A_SPAM, 450},
	{RIGHT, 240},
	{A_SPAM, 450},
	
	//----------Put eggs back [47,65]----------
	// Goto first mon in team (47,52)
	{X, 5},
	{NOTHING, 15},
	{A_SPAM, 10},
	{NOTHING, 60},
	{DPAD_LEFT, 3},
	{DOWN, 3},
	
	// pick up egg (see above)
	
	// Put mon back to box (53,61)
	{RIGHT, 3},
	{DPAD_RIGHT, 3},
	{RIGHT, 3},
	{DPAD_RIGHT, 3},
	{RIGHT, 3},
	{DPAD_RIGHT, 3},
	{UP, 3},
	{A, 3},
	{NOTHING, 3},
	
	// next box first column (62,66)
	{UP, 3},
	{DPAD_RIGHT, 3},
	{DOWN, 3},
	{DPAD_RIGHT, 3},
	{RIGHT, 3},
};