#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press A once to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 1},
	
	//----------Loop----------
	{RIGHT | B, 1},
	{RIGHT, 130},
	{NOTHING, 1},
	{LEFT | B, 1},
	{LEFT, 132},
	{NOTHING, 1},
};