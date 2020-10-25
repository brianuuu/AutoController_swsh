#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Fossil Startup [3,6]----------
	{A, 40},		// Talk
	{NOTHING, 1},
	{A, 32},		// Yes
	{NOTHING, 1},
	
	//----------1st/2nd fossil [7,10]----------
	{DOWN, 1},		// 2nd fossil
	{NOTHING, 1},
	{A, 32},		// 1st fossil
	{NOTHING, 1},
	
	//----------Get fossil [11,28]----------
	{A, 20},		// Yes please
	{NOTHING, 1},
	{A, 160},		// OK. Restoration time...
	{NOTHING, 1},
	{A, 30},		// All right, I'll stick 'em together! ...
	{NOTHING, 1},
	{A, 20},		// Objective complete...
	{NOTHING, 1},
	{A, 16},		// Yes, I can see it in its eyes...
	{NOTHING, 1},
	{A, 180},		// Please take and care for this Pokemon, huh. (Music plays)
	{NOTHING, 1},
	{B, 80},		// You received XXX! (please check if this is a shiny here)
	{NOTHING, 1},
	{B, 24},		// Send to box
	{NOTHING, 1},
	{B, 60},		// XXX has been sent to box
	{NOTHING, 1},
	
	//----------Finish/Prepare SR [29,30]----------
	{HOME, 1},		// (We use this to tell player it is done, if m_autoSoftReset = false
	{NOTHING, 40},
	
	//----------Soft reset [31,40]----------
	{X, 1},			// Close game
	{NOTHING, 8},
	{A, 1},			// Comfirm close game
	{NOTHING, 120},
	{A, 1},			// Choose game
	{NOTHING, 50},
	{A, 1},			// Pick User
	{NOTHING, 820},
	{A, 1},			// Enter game
	{NOTHING, 460}
};