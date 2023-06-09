#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,6]----------
	// Press trigger to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 60},
	{L|R, 1},
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 60},
	
	//----------Complete [7,8]----------
	{HOME,1},
	{NOTHING, 4},
	
	//----------Loop [9,16]----------
	{PLUS, 10},
	{NOTHING, 1},
	{X, 1},
	{NOTHING, 1},
	{A_SPAM, 10},
	{Y|B, 1},	
	{NOTHING, 5},
	{A_SPAM, 20}
};