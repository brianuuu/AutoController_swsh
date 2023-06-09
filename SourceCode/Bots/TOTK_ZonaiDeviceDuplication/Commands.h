#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
		
	// Press A once to connect
	{NOTHING, 100},
	{A, 10},
	{NOTHING, 30},
	{A, 10},
	{NOTHING, 30},
	{A, 10},
	
	// Dupe
	{PLUS, 10},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{Y|B, 1},
	{NOTHING, 1}
};