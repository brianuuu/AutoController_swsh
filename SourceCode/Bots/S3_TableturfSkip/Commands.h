#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press A once to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 1},
	
	//----------To Time [3,7]----------
	{DPAD_UP, 1},
	{NOTHING, 1},
	{A_SPAM, 4},
	{B, 1},
	{NOTHING, 10}
};