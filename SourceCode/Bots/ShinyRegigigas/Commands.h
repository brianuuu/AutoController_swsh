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
	
	//----------Finish [3,4]----------
	{HOME, 1},		
	{NOTHING, 10},
	
	//----------Soft Reset [5,18]----------
	{A_SPAM, 120},	// Enter den
	{NOTHING, 810},	// Wait time before SR
	{HOME, 1},
	{NOTHING, 40},
	{X, 1},			// Close game
	{NOTHING, 8},
	{A, 1},			// Comfirm close game
	{NOTHING, 120},
	{A, 1},			// Choose game
	{NOTHING, 50},
	{A, 1},			// Pick User
	{NOTHING, 820},
	{A, 1},			// Enter game
	{NOTHING, 290},	// Crown Tundra has lower load times?
	
	//----------Shiny Aware [19,30]----------
	{A_SPAM, 120},	// Enter den
	{NOTHING, 900},	// Fixed delay
	{B_SPAM, 100},	// This spam quits the team screen if shiny is found
	
	{NOTHING, 9999},// OVERWRITTEN, Time to wait for battle to begin, default 176
	
	{DPAD_UP, 1},	// Non-shiny: Run, Shiny: Ignore
	{NOTHING, 110},	// Shiny delay
	{DPAD_DOWN, 1},	// Non-shiny: Fight, Shiny: Pokemon
	
	{A_SPAM, 50},	// Non-shiny: Attack, Shiny: Select first Pokemon
	
	{NOTHING, 540}, // Delay accounted for crit, 450 + 80
	
	{DPAD_DOWN, 1},
	{A, 1},			// Non-shiny: Don't Catch, Shiny: Check Summary
	{NOTHING, 310},
	
	//----------Restore PP [31,34]----------
	{X, 1},			// Menu
	{NOTHING, 20},
	{A_SPAM, 130},	// Goto bag, use Leppa Berry on Reversal
	{B_SPAM, 100},	// Spam B to quit (this will quit Pokemon summary if shiny is found)
};
