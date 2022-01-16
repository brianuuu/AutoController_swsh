#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Loop [3,43]----------
	// Enter 2nd menu
	{B,40},
	{R,40},
	{A,1},
	{X,22},
	{A,40},
	{R,50},
	{Y,2},
	{NOTHING,1},
	{Y,2},
	
	// Select all pokemon in the box
	{A,2},
	{DPAD_RIGHT,1},
	{NOTHING,4},
	{DPAD_RIGHT,1},
	{NOTHING,4},
	{DPAD_RIGHT,1},
	{NOTHING,4},
	{DPAD_RIGHT,1},
	{NOTHING,4},
	{DPAD_RIGHT,1},
	{NOTHING,4},
	{DPAD_DOWN,1},
	{NOTHING,4},
	{DPAD_DOWN,1},
	{NOTHING,4},
	{DPAD_DOWN,1},
	{NOTHING,4},
	{DPAD_DOWN,1},
	{NOTHING,4},
	
	// Move to box on the right
	{A,10},
	{R,20},
	{A,5},
	
	// Quit 2nd menu
	{B,1},
	{NOTHING,30},
	{B,1},
	{NOTHING,30},
	{B,1},
	{NOTHING,30},
	
	// Enter & exit summary
	{DPAD_DOWN,1},
	{A,40},
	{B,40},
	{R,22},
	
	//----------Complete [44,45]----------
	{HOME,1},
	{NOTHING, 4},
};