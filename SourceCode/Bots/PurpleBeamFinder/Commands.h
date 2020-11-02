#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Put wishing piece [3,20]----------
	{LCLICK, 1},
	{NOTHING, 10},
	{LCLICK, 1},
	{NOTHING, 10},
	{LCLICK, 1},
	{NOTHING, 10},
	{LCLICK, 1},
	{NOTHING, 10},
	{LCLICK, 1},
	{NOTHING, 10},
	{A, 37},		// Talk
	{NOTHING, 1},
	{A, 35},		// There doesn't seem to be anything in the den... Want to throw in a Wishing Piece?
	{NOTHING, 1},
	{A, 1},			// Would you like to save your adventure so far?
	{NOTHING, 27},
	{HOME, 1},
	{NOTHING, 300},
	
	//----------Soft reset [21,30]----------
	{X, 1},			// Close game
	{NOTHING, 8},
	{A, 1},			// Comfirm close game
	{NOTHING, 120},
	{A, 1},			// Choose game
	{NOTHING, 150},
	{A, 1},			// Pick User
	{NOTHING, 820},
	{A, 1},			// Enter game
	{NOTHING, 460}
};
