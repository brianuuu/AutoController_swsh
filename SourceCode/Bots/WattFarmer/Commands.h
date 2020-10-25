#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Sync and unsync time, goto change date [3,40]----------
	// To System Settings
	{HOME, 1},
	{NOTHING, 30},
	{DOWN, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	
	// To Date and Time
	{DOWN, 80},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 8},
	
	// Sync and unsync time
	{A, 1},
	{NOTHING, 4},
	{A, 1},
	{NOTHING, 8},
	
	// To actually Date and Time
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 7},
	
	//----------Plus 1 year [41,56]----------
	{RIGHT, 1},		// EU/US start
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{UP, 1},		// JP start
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},	// EU end
	{RIGHT, 1},
	{NOTHING, 1},	// US end
	{RIGHT, 1},		
	{NOTHING, 1},	// JP end
	
	//----------Back to game [57,62]----------
	{A, 1},
	{NOTHING, 4},
	{HOME, 1},
	{NOTHING, 30},
	{HOME, 1},
	{NOTHING, 30},
	
	//----------Collect Watts [63,70]----------
	{A, 12},	
	{NOTHING, 1},
	{B, 6},
	{NOTHING, 1},
	{B, 30},
	{NOTHING, 1},
	{B, 1},	
	{NOTHING, 50},
	
	//----------Save Game [71,76]----------
	{X, 1},	
	{NOTHING, 20},
	{R, 1},
	{NOTHING, 50},
	{A, 1},
	{NOTHING, 140}
};