#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Encounter + Leave + Camp [3,10]----------
	{B, 25},		// Leave camp
	{A, 9999},		// OVERWRITTEN, wait time, refer to .c file line 
	
	{UP, 1},		// Run from battle
	{NOTHING, 1},
	{A, 210},
	
	{X, 1},	
	{NOTHING, 20},
	{A, 9999},		// OVERWRITTEN, Start camping
};
