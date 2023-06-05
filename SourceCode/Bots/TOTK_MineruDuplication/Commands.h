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
	
	//----------Loop [3,4]----------
	
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
	{NOTHING, 5},
	{A, 1},
	{NOTHING, 3},
	{A, 1},
	{NOTHING, 3},
	{A, 1},
	{NOTHING, 3},
	{A, 1},
	{NOTHING, 3},
	{A, 1},
	{NOTHING, 3},
	{A, 1}
	
	
	
};