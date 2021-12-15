#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},	// Line 0
	{B, 1},	// Line 1
	{NOTHING, 1},	// Line 2
	
	//----------Release Pokemon [3,12]----------
	
	//get items
	{A, 10},	// Line 3
	{NOTHING, 1},	// Line 4
	{DOWN, 1},	// Line 5
	{NOTHING, 1},	// Line 6
	{A, 1},	// Line 7
	{NOTHING, 10},	// Line 8
	{A, 10},	// Line 9
	{NOTHING, 20},	// Line 10
	{A, 1},	// Line 11
	{NOTHING, 20},	// Line 12
	
	//----------Movement [13,48]----------
	// Next box [13-34]
	{B, 1},	// Line 13
	{NOTHING, 95},	// Line 14
	{B, 1},	// Line 15
	{NOTHING, 40},	// Line 16
	{B, 1},	// Line 17
	{NOTHING, 40},	// Line 18
	{DOWN, 1},	// Line 19
	{NOTHING, 10},	// Line 20
	{A, 1},	// Line 21
	{NOTHING, 50},	// Line 22
	{B, 5},	// Line 23
	{NOTHING, 90},	// Line 24
	{A,10},	// Line 25
	{NOTHING,10},	// Line 26
	{X,10},	// Line 27
	{NOTHING,10},	// Line 28
	{A,10},	// Line 29
	{NOTHING,40},	// Line 30
	{R,5},	// Line 31
	{NOTHING,100},	// Line 32
	{X,5},	// Line 33
	{NOTHING,20},	// Line 34
	
	// Next Pokemon [35-36]
	{RIGHT, 1},	// Line 35
	{NOTHING, 1},	// Line 36
	
	// Next Row [37-48]
	{LEFT, 1},	// Line 37
	{NOTHING, 1},	// Line 38
	{LEFT, 1},	// Line 39
	{NOTHING, 1},	// Line 40
	{LEFT, 1},	// Line 41
	{NOTHING, 1},	// Line 42
	{LEFT, 1},	// Line 43
	{NOTHING, 1},	// Line 44
	{LEFT, 1},	// Line 45
	{NOTHING, 1},	// Line 46
	{DOWN, 1},	// Line 47
	{NOTHING, 1},	// Line 48
};