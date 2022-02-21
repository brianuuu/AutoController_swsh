#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press A once to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 1},
	
	//----------Loop [3,21]----------
	{HOME, 1},
	{NOTHING, 21},
	{X, 1},
	{A_SPAM, 1040}, // Enter game & cave
	
	{UP|LCLICK, 1},
	{UP, 80},
	{UP|LEFT, 30},
	{LEFT, 10},
	{A, 1},			// Get on Sneasler
	{UP, 40},
	{PLUS, 20},		// Get off Sneasler
	{UP|LEFT, 90},
	{UP|RIGHT, 20},
	{ZL, 1},		// Reset camera
	{NOTHING, 10},
	{RRIGHT, 4},
	{UP|LCLICK, 1},
	{UP, 120},
	{NOTHING, 100},
};