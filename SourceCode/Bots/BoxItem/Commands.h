#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Release Pokemon [3,16]----------
	{A, 10},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 10},
	{A, 10},
	{NOTHING, 20},
	{A, 1},
	{NOTHING, 1},
	{NOTHING, 1},
	{NOTHING, 1},
	{NOTHING, 1},
	{NOTHING, 25},
	
	//----------Movement [17,50]----------
	// Next box [17-36]
	{LEFT, 1},
	{NOTHING, 1},
	{LEFT, 1},
	{NOTHING, 1},
	{LEFT, 1},
	{NOTHING, 1},
	{LEFT, 1},
	{NOTHING, 1},
	{LEFT, 1},
	{NOTHING, 1},
	{UP, 1},
	{NOTHING, 1},
	{UP, 1},
	{NOTHING, 1},
	{UP, 1},
	{NOTHING, 1},
	{UP, 1},
	{NOTHING, 1},
	{R, 1},
	{NOTHING, 20},
	
	// Next Pokemon [37-38]
	{RIGHT, 1},
	{NOTHING, 1},
	
	// Next Row [39-50]
	{LEFT, 1},
	{NOTHING, 1},
	{LEFT, 1},
	{NOTHING, 1},
	{LEFT, 1},
	{NOTHING, 1},
	{LEFT, 1},
	{NOTHING, 1},
	{LEFT, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
};