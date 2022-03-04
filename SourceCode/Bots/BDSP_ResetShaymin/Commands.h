#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press A once to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 1},
	
	//----------Loop [3,16]----------
	{A, 1},				// Talk to Shaymin
	{NOTHING, 60},
	{A, 420},
	
	{DPAD_UP, 1},		// Not shiny: Run from battle
	{A, 64},
	
	{DPAD_DOWN, 1},		// Shiny: Goto pokemon summary
	{A, 1},
	{NOTHING, 20},
	{A, 11},
	{DPAD_DOWN, 1},
	
	{A, 8},				// Not shiny: Shaymin disappear dialog, Shiny: Summary
	{PLUS, 6},
	{DPAD_DOWN, 46},
	{DPAD_UP, 46},
};