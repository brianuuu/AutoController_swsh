#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 80},
	{B, 3},
	{NOTHING, 14},
	
	//----------Tournament [3,18]----------
	// BAAAAAAA + Stick Up slightly Right
	{B, 25},
	{NOTHING, 25},
	
	{A, 25},
	{NOTHING, 25},
	{A, 25},
	{NOTHING, 25},
	{A, 25},
	{NOTHING, 25},
	{A, 25},
	{NOTHING, 25},
	{A, 25},
	{NOTHING, 25},
	{A, 25},
	{NOTHING, 25},
	{A, 25},
	{NOTHING, 25}
};