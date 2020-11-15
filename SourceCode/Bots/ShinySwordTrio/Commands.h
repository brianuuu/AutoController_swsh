#include "../../Joystick.h"
#include <avr/pgmspace.h>

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
	{RIGHT, 1},		// Little correction. Player will make narrow circles
	{DOWN, 30}, 	// Go down
	
	{X, 1},	
	{NOTHING, 20},
	{A, 280},		// Start camping
	
	{X, 10},		// Leave camp
	{LEFT, 1},
	{A, 230},		// Black screen delay (account for longest time)

	{LEFT, 1},		// Little correction (when player is facing up and turns down, he always turns by rigth side and he moves a little to right)
	{UP, 40},		// Go up for encounter
	
	{NOTHING, 9999},// OVERWRITTEN, Time to wait for battle to begin, default 366
	
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
};
