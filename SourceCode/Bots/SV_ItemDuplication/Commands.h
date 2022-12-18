#include "../../Joystick.h"
#include <avr/pgmspace.h>

/*
Smart command
A,5,Nothing,5,DUp,5,LUp,5,A,30,B,5,Nothing,5,A,60,B,5,Nothing,5,DRight,5,DDown,5,LDown,5,A,5,Nothing,60,X,5,Nothing,4,X,5,Nothing,4,L,10,A,10,DDown,5,LDown,5,DDown,5,A,30,B,5,Nothing,30,DLeft,5
*/

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press A once to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 1},
	
	//----------Loop [3,30]----------
	// return to ride form
	{A, 5},
	{NOTHING, 5},
	{DPAD_UP, 5},
	{UP, 5},
	{A, 30},
	{B, 5},
	{NOTHING, 5},
	{A, 60},
	{B, 5},
	{NOTHING, 5},
	
	// enter box
	{DPAD_RIGHT, 5},
	{DPAD_DOWN, 5},
	{DOWN, 5},
	{A, 5},
	{NOTHING, 60},
	
	// mirandon/koraidon box
	{X, 5},
	{NOTHING, 4},
	{X, 5},
	{NOTHING, 4},
	{L, 10},
	
	// take item
	{A, 10},
	{DPAD_DOWN, 5},
	{DOWN, 5},
	{DPAD_DOWN, 5},
	{A, 30},
	
	// exit box, move cursor to 2nd slot
	{B, 5},
	{NOTHING, 30},
	{DPAD_LEFT, 5},
	
	//----------Complete [31,32]----------
	{HOME,1},
	{NOTHING, 4}
};