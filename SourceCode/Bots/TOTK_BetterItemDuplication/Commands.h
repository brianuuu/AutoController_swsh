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
	{A, 30},
	
	// Shield surf
	{NOTHING, 10},
	{ZL|X, 1},
	{NOTHING, 1},
	{ZL|A, 1},
	
	// Dupe
	{NOTHING, 10},
	{PLUS, 1},
	{NOTHING, 10},
	{X, 1},
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
	// Pick items up
	{NOTHING, 20},
	{DOWN, 1},
	{NOTHING, 10},
	{A, 1},
	{NOTHING, 4},
	{A, 1},
	{NOTHING, 4},
	{A, 1},
	{NOTHING, 4},
	{A, 1},
	{NOTHING, 4},
	{A, 1}
	
	
	
};