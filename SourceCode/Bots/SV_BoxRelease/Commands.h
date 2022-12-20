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
	
	//----------Box [5,13]----------
	{A_SPAM, 4},
	{NOTHING, 4},
	{UP, 3},
	{DPAD_UP, 3},
	{A_SPAM, 8},
	{NOTHING, 4},
	{DPAD_UP, 3},
	{A_SPAM, 36},
	{DPAD_RIGHT, 3},
	
	//----------Next row [14,15]----------
	{RIGHT, 3},
	{DPAD_DOWN, 3},
	
	//----------Next box [16,18]----------
	{DOWN, 3},
	{DPAD_RIGHT, 3},
	{DOWN, 3},
};