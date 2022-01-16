#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Push rock and start glitch [3,15]----------
	{A_SPAM, 40},
	{B_SPAM, 100},
	{DPAD_RIGHT, 3},
	{NOTHING, 1},
	{DPAD_RIGHT | R, 3},
	{NOTHING, 10},
	{A, 1},
	{NOTHING, 20},
	{DPAD_RIGHT, 5},
	{NOTHING, 10},
	{A, 10},
	{X, 20},
	{A, 100},
};