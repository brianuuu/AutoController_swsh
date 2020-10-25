#include "../../Joystick.h"
#include <avr/pgmspace.h>

// 14 -> US/EU:696ms, JP:536ms (some people reported crashing)
// 16 -> US/EU:728ms, JP:568ms
#define FIXED_DELAY 16

static const Command m_command[] PROGMEM = {
	//----------Setup [0,8]----------
	// Press B once to connect
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
	{HOME, 4},
	{NOTHING, 150},
	{HOME, 4},
	
	//----------Skip day JP [13,21]----------
	{A, 5},
	{NOTHING, FIXED_DELAY},
	
	// <<<^>>>
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{UP_A, 4},
	{RRIGHT, 4},

	{RIGHT_A, 5},
	{NOTHING, FIXED_DELAY},
	
	//----------Skip month JP [22,33]----------
	{A, 5},
	{NOTHING, FIXED_DELAY},
	
	// <<<^<^>>>>
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{UP, 4},
	{RLEFT, 4},
	{UP_A, 4},
	{RIGHT, 4},
	{RRIGHT, 4},

	{RIGHT_A, 5},
	{NOTHING, FIXED_DELAY},
	
	//----------Skip year JP [34,48]----------
	{A, 5},
	{NOTHING, FIXED_DELAY},
	
	// <<<^<^<^>>>>>
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{UP, 4},
	{RLEFT, 4},
	{UP, 4},
	{LEFT, 4},
	{UP_A, 4},
	{RRIGHT, 4},
	{RIGHT, 4},
	{RRIGHT, 4},
	
	{RIGHT_A, 5},
	{NOTHING, FIXED_DELAY},
	
	//----------Skip day EU/US [49,61]----------
	{A, 5},
	{NOTHING, FIXED_DELAY},
	
	// <<<<<^>>>>>
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{UP_A, 4},
	{RRIGHT, 4},
	{RIGHT, 4},
	{RRIGHT, 4},

	{RIGHT_A, 5},
	{NOTHING, FIXED_DELAY},
	
	//----------Skip month EU [62,75]----------
	{A, 5},
	{NOTHING, FIXED_DELAY},
	
	// <<<<<^>^>>>>
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{UP_A, 4},
	{NOTHING, 2},
	{UP_A, 4},
	{RIGHT, 4},
	{RRIGHT, 4},

	{RIGHT_A, 5},
	{NOTHING, FIXED_DELAY},
	
	//----------Skip year EU [76,90]----------
	{A, 5},
	{NOTHING, FIXED_DELAY},
	
	// <<<<<^>^>^>>>
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{UP_A, 4},
	{NOTHING, 2},
	{UP_A, 4},
	{NOTHING, 2},
	{UP_A, 4},
	{RRIGHT, 4},

	{RIGHT_A, 5},
	{NOTHING, FIXED_DELAY},
	
	//----------Skip month US [91,106]----------
	{A, 5},
	{NOTHING, FIXED_DELAY},
	
	// <<<<<^<^>>>>>>
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{UP, 4},
	{RLEFT, 4},
	{UP_A, 4},
	{RIGHT, 4},
	{RRIGHT, 4},
	{RIGHT, 4},
	{RRIGHT, 4},

	{RIGHT_A, 5},
	{NOTHING, FIXED_DELAY},
	
	//----------Skip year US [107,122]----------
	{A, 5},
	{NOTHING, FIXED_DELAY},
	
	// <<<<<^<^>>^>>>>
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{RLEFT, 4},
	{LEFT, 4},
	{UP, 4},
	{RLEFT, 4},
	{UP_A, 4},
	{RRIGHT, 4},
	{UP_A, 4},
	{RIGHT, 4},
	{RRIGHT, 4},

	{RIGHT_A, 5},
	{NOTHING, FIXED_DELAY}
};