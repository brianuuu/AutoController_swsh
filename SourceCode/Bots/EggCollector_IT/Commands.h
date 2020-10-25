#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Loop [3,17]----------
	{RIGHT, 10},	// Cycle
	{B, 1},
	{RIGHT, 110},
	{DOWN, 1},
	{LEFT, 210},
	{UP, 70},
	
	{A, 32},		// Talk
	{NOTHING, 1},
	{A, 40},		// Talk
	{NOTHING, 1},
	{A, 120},		// Yes
	{NOTHING, 1},
	{B, 60},		// You received an Egg from the Nursery worker!
	{NOTHING, 1},
	{B, 50},		// The Egg has been sent to a Box!
	{NOTHING, 1},
	{B, 5},			// Take good care of it, and raise it well!
	
	{HOME, 1},
	{NOTHING, 1},
};