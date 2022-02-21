#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press A once to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 1},
	
	//----------Loop [3,18]----------
	{HOME, 1},
	{NOTHING, 21},
	{X, 1},
	{A_SPAM, 1040}, // Enter game & temple
	
	{UP|LCLICK, 1},
	{UP, 430},
	{UP|LCLICK, 1},
	{RIGHT, 120},
	{DOWN, 40},
	{ZL, 1},		// Flip camera
	{NOTHING, 10},
	{RDOWN, 6},
	{UP|LEFT, 100},
	{UP|LCLICK, 1},
	{UP, 80},
	{NOTHING, 100},
};