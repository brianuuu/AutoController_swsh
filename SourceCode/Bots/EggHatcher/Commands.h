#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Finish [3,5]----------
	{NOTHING, 1},
	{HOME, 1},
	{NOTHING, 1},
	
	//----------Pick up eggs [6,28]----------
	// Go to correct column
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	
	// Select Eggs
	{A, 3},
	{UP, 3},
	{A, 3},
	
	// Put in party, exit
	{LEFT, 36},
	{DOWN, 2},
	{A, 5},	
	{B, 1},	
	{NOTHING, 68},
	{B, 1},	
	{NOTHING, 54},
	{B, 41},
	
	// Align with NPC
	{CAPTURE, 1},
	{NOTHING, 30},
	
	//----------Put hatched egg to box [29,52]----------
	{X, 22},	
	{A, 64},
	{R, 1},			// Goto Box
	{NOTHING, 70},
	{Y, 1},
	{NOTHING, 1},
	{Y, 3},			// Multiselect mode
	{LEFT, 2},
	{DOWN, 2},
	{A, 3},			// Pick up hatched mons
	{DOWN, 26},
	{A, 3},
	{DOWN, 26},		// Put them to the current box
	{RIGHT, 2},
	{A, 1},
	{NOTHING, 20},
	{A, 6},
	{B, 10},
	{DOWN, 1},		// Back to top left corner
	{NOTHING, 1},
	{DOWN, 1},	
	{NOTHING, 1},
	
	{R, 1},			// Next Box
	{NOTHING, 14},
	
	//----------Cycle Loop [53,58]----------
	{DOWN, 2},		// Cycle
	{LEFT, 20},
	{B, 1},
	{LEFT, 85},
	{UP, 8},
	{CAPTURE, 178},
	
	//----------Small Cycles [59,63]----------
	{LEFT, 35},		// Set up before last cycle loop
	
	{UP, 12},		// Small loops
	{RIGHT, 12},
	{DOWN, 12},
	{LEFT, 12},
	
	//----------Hatching Eggs x5 [64,66]----------
	{LEFT, 28},
	{B, 790},		// Wait long in case it was a shiny
	{A, 110},
	
	//----------Movement Fix After Hatch [67,68]----------
	{DOWN, 40},
	{CAPTURE, 90},
};