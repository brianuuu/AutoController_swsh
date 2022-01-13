#include "../../Joystick.h"
#include <avr/pgmspace.h>

// 14 -> US/EU:696ms, JP:536ms (some people reported crashing)
// 16 -> US/EU:728ms, JP:568ms
#define FIXED_DELAY 16

static const Command m_command[] PROGMEM = {
	//----------Setup [0,8]----------
	// Press A once to connect
	{NOTHING, 80},
	{B, 3},
	{NOTHING, FIXED_DELAY},
	
	// Make sure cursor is on OK
	{A, 5},
	{NOTHING, FIXED_DELAY},
	{RIGHT, 120},
	{NOTHING, 3},
	
	// Exit
	{A, 5},
	{NOTHING, FIXED_DELAY},
	
	//----------Back to game [9,12]----------
	{NOTHING, 30},
	{HOME, 5},
	{NOTHING, 150},
	{HOME, 5},
	
	//----------Skip day JP [13,21]----------
	{A, 5},
	{NOTHING, FIXED_DELAY},
	
	// <<<^>>>
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{UP | A, 4},
	{RRIGHT, 4},

	{RIGHT | A, 5},
	{NOTHING, FIXED_DELAY},
	
	//----------Skip day EU/US [22,34]----------
	{A, 5},
	{NOTHING, FIXED_DELAY},
	
	// <<<<<^>>>>>
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{UP | A, 4},
	{RRIGHT, 4},
	{RIGHT, 4},
	{RRIGHT, 4},

	{RIGHT | A, 5},
	{NOTHING, FIXED_DELAY}
};
