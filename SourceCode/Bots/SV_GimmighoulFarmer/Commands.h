#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press A once to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 1},
	
	//----------To Time [3,35]----------
	{HOME, 2},
	{NOTHING, 21},
	{RIGHT, 1},
	{RRIGHT, 1},
	{DOWN, 1},
	{RIGHT, 1},
	{A, 18},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{A, 12},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 6},
	{DOWN, 1},
	{RDOWN, 1},
	{A, 6},
	{DOWN, 1},
	{RDOWN, 1},
	{A, 4},
	
	//----------Skip Day JP [36,40]----------
	{RIGHT, 1},
	{RRIGHT, 1},
	{UP | A, 1},
	{RRIGHT, 1},
	{RIGHT, 1},
	
	//----------Skip Day EU/US [41,45]----------
	{RRIGHT, 1}, // US start
	{UP | A, 1}, // EU start
	{RRIGHT, 1},
	{RIGHT | A, 1},
	{RRIGHT, 1},
	
	//----------Close game + farm [46,52]----------
	{NOTHING, 2},
	{A, 1},
	{NOTHING, 2},
	{HOME, 2},
	{NOTHING, 21},
	{X, 1},
	{A_SPAM, 950}, // Home to talk to Gimmighoul, 20 ~= 1s
	
	//----------Save game [53,57]----------
	{X, 5},
	{NOTHING, 15},
	{R, 2},
	{A_SPAM, 30},
	{B_SPAM, 40},
};