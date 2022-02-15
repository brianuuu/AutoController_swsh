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
	
	//----------Loop [3,12]----------
	{HOME, 1},
	{NOTHING, 40},
	{X, 20},		// Close game
	{A, 40},
	{DOWN, 1},		
	{UP, 1},		// Cancel DOWN if no game, otherwise goto Start Software
	{A, 40},
	{UP, 1},		// Goto Start Software
	{A_SPAM, 1500},	// Enter game and talk to legendary
	{NOTHING, 900},	// Delay
};
