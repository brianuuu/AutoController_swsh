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
	
	//----------Encounter + Leave + Camp (Shiny aware) [12,28]----------
	{X, 10},		// Leave camp
	{LEFT, 1},
	{A, 9999},		// OVERWRITTEN, Time to wait for battle to begin, default 650
	
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
	
	{X, 1},	
	{NOTHING, 20},
	{A, 280},		// Start camping
};
