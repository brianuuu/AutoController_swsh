#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},	// Line {lineCounter}
	{B, 1},	// Line {lineCounter}
	{NOTHING, 1},	// Line {lineCounter}
	
	//----------Release Pokemon [3,12]----------
	
	//get items
	{A, 10},	// Line {lineCounter}
	{NOTHING, 1},	// Line {lineCounter}
	{DOWN, 1},	// Line {lineCounter}
	{NOTHING, 1},	// Line {lineCounter}
	{A, 1},	// Line {lineCounter}
	{NOTHING, 10},	// Line {lineCounter}
	{A, 10},	// Line {lineCounter}
	{NOTHING, 20},	// Line {lineCounter}
	{A, 1},	// Line {lineCounter}
	{NOTHING, 20},	// Line {lineCounter}
	
	//----------Movement [13,48]----------
	// Next box [13-34]
	{B, 1},	// Line {lineCounter}
	{NOTHING, 110},	// Line {lineCounter}
	{B, 1},	// Line {lineCounter}
	{NOTHING, 40},	// Line {lineCounter}
	{B, 1},	// Line {lineCounter}
	{NOTHING, 40},	// Line {lineCounter}
	{DOWN, 1},	// Line {lineCounter}
	{NOTHING, 10},	// Line {lineCounter}
	{A, 1},	// Line {lineCounter}
	{NOTHING, 50},	// Line {lineCounter}
	{B, 5},	// Line {lineCounter}
	{NOTHING, 50},	// Line {lineCounter}
	{A,10},	// Line {lineCounter}
	{NOTHING,10},	// Line {lineCounter}
	{X,10},	// Line {lineCounter}
	{NOTHING,10},	// Line {lineCounter}
	{A,10},	// Line {lineCounter}
	{NOTHING,40},	// Line {lineCounter}
	{R,5},	// Line {lineCounter}
	{NOTHING,110},	// Line {lineCounter}
	{X,5},	// Line {lineCounter}
	{NOTHING,20},	// Line {lineCounter}
	
	// Next Pokemon [35-36]
	{RIGHT, 1},	// Line {lineCounter}
	{NOTHING, 1},	// Line {lineCounter}
	
	// Next Row [37-48]
	{LEFT, 1},	// Line {lineCounter}
	{NOTHING, 1},	// Line {lineCounter}
	{LEFT, 1},	// Line {lineCounter}
	{NOTHING, 1},	// Line {lineCounter}
	{LEFT, 1},	// Line {lineCounter}
	{NOTHING, 1},	// Line {lineCounter}
	{LEFT, 1},	// Line {lineCounter}
	{NOTHING, 1},	// Line {lineCounter}
	{LEFT, 1},	// Line {lineCounter}
	{NOTHING, 1},	// Line {lineCounter}
	{DOWN, 1},	// Line {lineCounter}
	{NOTHING, 1},	// Line {lineCounter}
};