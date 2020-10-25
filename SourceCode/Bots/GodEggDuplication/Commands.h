#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	{HOME, 1},
	{NOTHING, 1},
	
	//----------Loop [5,27]----------
	{RIGHT, 10},	// Cycle
	{B, 1},
	{RIGHT, 110},
	{DOWN, 1},
	{LEFT, 210},
	{UP, 70},
	
	{A, 26},		// Talk
	{NOTHING, 1},
	{A, 120},		// Yes
	{NOTHING, 1},
	{B, 82},		// You received an Egg from the Nursery worker!
	{NOTHING, 1},
	
	{A, 32},		// Add to your party
	{NOTHING, 1},
	{B, 92},		// Please select a Pokemon to swap from your party
	{NOTHING, 1},
	
	{A, 104},		// Select pokemon
	{NOTHING, 1},
	{B, 38},		// (Optional) Send the Pokemon to Box as is
	{NOTHING, 1},
	{B, 50},		// The Egg will be added to your party
	{NOTHING, 1},
	{B, 5},			// Take good care of it, and raise it well!
};