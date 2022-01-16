#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Start [3,5]----------
	{B,40},
	{R,40},
	
	{X,2}, // For bag item only
	
	//----------Release [6,13]----------
	{A,8},
	{DPAD_UP,1},
	{NOTHING,1},
	{DPAD_UP,1},
	{A,8},
	{DPAD_UP,1},
	{A,20},
	{B,5},
	
	//----------Bag Item [14,19]----------
	{A,8},
	{DPAD_DOWN,1},
	{A,8},
	{NOTHING,1},
	{A,20},
	{B,10},
	
	//----------Enter 2nd menu (glitch) [20,24]----------
	{A,1},
	{X,22},
	{A,40},
	{R,50},
	{X,2},
	
	//----------Exit 2nd menu (glitch) [25,34]----------
	{NOTHING,5},
	{B,1},
	{NOTHING,30},
	{B,1},
	{NOTHING,30},
	{B,1},
	{NOTHING,30},
	{DPAD_DOWN,1},
	{A,40},
	{B,40},
	
	//----------Movement [35,40]----------
	{DPAD_DOWN,1},
	{NOTHING, 6},
	{DPAD_RIGHT,1},
	{NOTHING, 6},
	{DPAD_LEFT,1},
	{NOTHING, 6},
	
	//----------Next Box [41,59]----------
	{DPAD_LEFT,1},
	{NOTHING, 4},
	{DPAD_LEFT,1},
	{NOTHING, 4},
	{DPAD_LEFT,1},
	{NOTHING, 4},
	{DPAD_LEFT,1},
	{NOTHING, 4},
	{DPAD_LEFT,1},
	{NOTHING, 4},
	
	{DPAD_UP,1},
	{NOTHING, 4},
	{DPAD_UP,1},
	{NOTHING, 4},
	{DPAD_UP,1},
	{NOTHING, 4},
	{DPAD_UP,1},
	{NOTHING, 4},
	
	{R,22},
	
	//----------Complete [60,61]----------
	{HOME,1},
	{NOTHING, 4},
};