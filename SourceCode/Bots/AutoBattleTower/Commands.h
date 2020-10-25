#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 80},
	{B, 3},
	{NOTHING, 14},
	
	//----------Battle Tower [3,37]----------
	//AA (17s) AA^AA^AAA (17s) AABB (0.8s) ^
	{A, 25},
	{NOTHING, 75},
	{A, 25},
	{NOTHING, 75},
	
	{NOTHING, 2100},
	
	{A, 25},
	{NOTHING, 75},
	{A, 25},
	{NOTHING, 75},
	
	{DPAD_UP, 25},
	{NOTHING, 75},
	
	{A, 25},
	{NOTHING, 75},
	{A, 25},
	{NOTHING, 75},
	
	{DPAD_UP, 25},
	{NOTHING, 75},
	
	{A, 25},
	{NOTHING, 75},
	{A, 25},
	{NOTHING, 75},
	{A, 25},
	{NOTHING, 75},
	
	{NOTHING, 2100},
	
	{A, 25},
	{NOTHING, 75},
	{A, 25},
	{NOTHING, 75},
	{B, 25},
	{NOTHING, 75},
	{B, 25},
	{NOTHING, 75},
	
	{NOTHING, 100},
	
	{DPAD_UP, 25},
	{NOTHING, 75}
};