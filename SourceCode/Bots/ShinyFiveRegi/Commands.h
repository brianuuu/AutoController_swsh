#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Encounter + Leave [3,11]----------
	{A, 20},
	{NOTHING, 1},
	{A, 28},
	{NOTHING, 1},
	{A, 9999},		// OVERWRITTEN, wait time, include start of battle music, refer to .c file line 340
	{UP, 1},
	{NOTHING, 1},
	{A, 260},
	{B, 5},
	
	//----------Regirock [12,23]----------
	{LEFT, 120},	// Goto the left up corner
	{DOWN, 73},
	{RIGHT, 82},
	{UP, 16},
	{LEFT, 50},
	{UP, 16},
	{RIGHT, 45},
	
	{A, 170},		// Something changed in the air...
	{NOTHING, 1},
	{A, 5},
	{UP_LEFT, 60},
	{UP, 30},
	
	//----------Regice [24,34]----------
	{LEFT, 120},	// Goto the left up corner
	{DOWN, 54},
	{RIGHT, 100},
	{DOWN_LEFT, 23},
	{LEFT, 34},
	{UP, 28},
	{UP_RIGHT, 10},
	
	{A, 170},		// Something changed in the air...
	{NOTHING, 1},
	{A, 5},
	{UP, 80},
	
	//----------Registeel [35,46]----------
	{LEFT, 120},	// Goto the left up corner
	{DOWN, 73},
	{RIGHT, 88},
	{UP, 16},
	{LEFT, 65},
	{UP, 16},
	{RIGHT, 50},
	
	{A, 170},		// Something changed in the air...
	{NOTHING, 1},
	{A, 5},
	{UP_LEFT, 60},
	{UP, 30},
	
	//----------Regieleki [47,58]----------
	{LEFT, 120},	// Goto the left up corner
	{RIGHT, 35},
	{DOWN, 64},
	{UP, 23},
	{RIGHT, 51},
	{DOWN, 15},
	{UP, 44},
	
	{A, 170},		// Something changed in the air...
	{NOTHING, 1},
	{A, 5},
	{UP_LEFT, 75},
	{UP, 15},
	
	//----------Regidrago [59,70]----------
	{LEFT, 120},	// Goto the left up corner
	{RIGHT, 35},
	{DOWN, 47},
	{RIGHT, 51},
	{UP, 13},
	{DOWN, 60},
	{LEFT, 24},
	{UP, 50},
	
	{A, 170},		// Something changed in the air...
	{NOTHING, 1},
	{A, 5},
	{UP, 80},
	
	//----------Encounter + Leave (Shiny aware) [71,88]----------
	{A, 20},
	{NOTHING, 1},
	{A, 28},
	{NOTHING, 1},
	{A, 9999}, 		// OVERWRITTEN Time to wait for battle to begin, default 626
	{DOWN, 1}, 		// First down (ignored if shiny)
	{NOTHING, 1},
	{DOWN, 1}, 		// Second down (ignored if shiny)
	{NOTHING, 110},
	{DOWN, 1}, 		// Third down
	{NOTHING, 10},
	{A, 10}, 		// Run | Enter Pokemon
	{NOTHING, 100},
	{A, 10}, 		// | Select Pokemon
	{NOTHING, 10},
	{DOWN, 1}, 		// | Go to summary
	{NOTHING, 120},
	{A, 5}, 		// Close textbox | Enter summary
};
