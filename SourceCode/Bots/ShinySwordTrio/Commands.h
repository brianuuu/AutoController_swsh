#include "../../Joystick.h"
#include <avr/pgmspace.h>

// Define ECHOES here:
// 0 will run significantly faster but min button push time is 5 (sticks are 4)
// 1 is not tested
// 2 is the regular mode with min push time 1
#define ECHOES 2
#if ECHOES <= 1
	#define SPAM_DURATION 5
#else
	#define SPAM_DURATION 1
#endif

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Encounter + Leave + Camp [3,11]----------
	{X, 10},		// Leave camp
	{LEFT, 1},
	{A, 9999},		// OVERWRITTEN, wait time, refer to .c file line 
	
	{UP, 1},		// Run from battle
	{NOTHING, 1},
	{A, 210},
	
	{X, 1},	
	{NOTHING, 20},
	{A, 9999},		// OVERWRITTEN, Start camping
	
	//----------Encounter + Leave + Camp (Shiny aware) [12,33]----------
	{UP, 15},		// Little correction. Player will make narrow circles
	{DOWN, 35}, 	// Go down
	
	{X, 1},	
	{NOTHING, 20},
	{A, 280},		// Start camping
	
	{X, 10},		// Leave camp
	{LEFT, 1},
	{A, 240},		// Black screen delay (account for longest time)

	{DOWN, 15},		// Little correction (when player is facing up and turns down, he always turns by rigth side and he moves a little to right)
	{UP, 45},		// Go up for encounter
	
	{NOTHING, 9999},// OVERWRITTEN, Time to wait for battle to begin, default 404
	
	{UP, 1},
	{NOTHING, 1},
	{A, 1},			// Run from battle (ignored if shiny)
	
	{NOTHING, 110},	// Shiny delay
	
	{DPAD_DOWN, 1},
	{A, 1}, 		
	{NOTHING, 80},
	{A, 1},
	{NOTHING, 20},
	{DPAD_DOWN, 1},
	{A, 10}, 		// Enter Pokemon summary (ignore if not shiny)
	
	//----------Hourly Rollback [34,63]----------
	// To System Settings
	{HOME, 1},
	{NOTHING, 30},
	{RIGHT, 1},
	{RRIGHT, 1},
	{DOWN, 1},
	{RIGHT, 1},
	{A, 40},
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
	{A, 10},
	{DOWN, 1},
	{RDOWN, 1},
	{DOWN, 1},
	{RDOWN, 1},
	{A, 10},
	
	// To actually Date and Time
	{DOWN, 1},
	{RDOWN, 1},
	{A, 8},
	
	// ----------Plus 1 year [64,69]----------
	{RIGHT, 1},		// All start
	{RRIGHT, 1},
	{RIGHT, 1},
	{DOWN_A, 1},
	{RIGHT, 1},		// JP/EU end
	{RRIGHT, 1},	// US end
	
	// ----------Back to game [70,74]----------
	{A, 5},
	{HOME, 1},
	{NOTHING, 30},
	{HOME, 1},
	{NOTHING, 30},
};
