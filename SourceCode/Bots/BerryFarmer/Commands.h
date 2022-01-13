#include "../../Joystick.h"
#include <avr/pgmspace.h>

// Define ECHOES here:
// 0 will run significantly faster but min button push time is 5 (sticks are 4)
// 1 is not tested
// 2 is the regular mode with min push time 1
#define ECHOES 0
#if ECHOES <= 1
	#define SPAM_DURATION 5
#else
	#define SPAM_DURATION 1
#endif

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press A once to connect
	{NOTHING, 80},
	{A, 10},
	{NOTHING, 20},
	
	//----------Sync and unsync time, goto change date [3,42]----------
	// To System Settings
	{HOME, 5},
	{NOTHING, 100},
	{RIGHT, 4},
	{RRIGHT, 4},
	{DOWN, 4},
	{RIGHT, 4},
	{A, 120},
	
	// To Date and Time
	{DOWN, 4},
	{RDOWN, 4},
	{DOWN, 4},
	{RDOWN, 4},
	{DOWN, 4},
	{RDOWN, 4},
	{DOWN, 4},
	{RDOWN, 4},
	{DOWN, 4},
	{RDOWN, 4},
	{DOWN, 4},
	{RDOWN, 4},
	{DOWN, 4},
	{RDOWN, 4},
	{DOWN, 4},
	{NOTHING, 50},
	{A, 4},
	{DOWN, 4},
	{RDOWN, 4},
	{DOWN, 4},
	{RDOWN, 30},
	{DOWN, 4},
	{RDOWN, 4},
	{A, 4},
	{NOTHING, 30},
	
	// Sync and unsync time
	{A, 5},
	{NOTHING, 5},
	{A, 5},
	{NOTHING, 36},
	
	// To actually Date and Time
	{DOWN, 4},
	{RDOWN, 4},
	{A, 5},
	{NOTHING, 16},
	
	//----------Plus 1 year [43,49]----------
	{RIGHT, 4},		// EU/US start
	{RRIGHT, 4},
	{UP | A, 4},	// JP start
	{RIGHT, 4},
	{RRIGHT, 4},	// EU end
	{RIGHT, 4},		// US end
	{RRIGHT, 4},	// JP end
	
	//----------Back to game [50,55]----------
	{A, 5},
	{NOTHING, 30},
	{HOME, 5},
	{NOTHING, 120},
	{HOME, 5},
	{NOTHING, 120},
	
	//----------Save Game [56,59]----------
	{X, 70},
	{R, 150},
	{A, 4},
	{NOTHING, 420},
	
	//----------Collect berries [60,61]----------
	{A_SPAM, 140},	
	{B_SPAM, 1040},
};
