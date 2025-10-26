#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press A once to connect
	{NOTHING, 30},
	{A, 1},
	{NOTHING, 1},
	
	//----------!!Modify Loop Commands Down Here!!----------
	{RIGHT | B, 1},
	{RIGHT, 300},
	{NOTHING, 10},
	{LEFT | B, 1},
	{LEFT, 300},
};

/*
---------------------------------------
Tutorial
---------------------------------------
You can make any loop macro commands by modifying the commands above
You are recommended to use Notepad++ to edit this
Here are the list of available commands (all caps):

NOTHING 
A, B, X, Y          
L, R, ZL, ZR         
PLUS, MINUS, HOME, CAPTURE    
LCLICK     
UP, DOWN, LEFT, RIGHT      
RCLICK     
RUP, RDOWN, RLEFT, RRIGHT     
DPAD_UP, DPAD_DOWN, DPAD_LEFT, DPAD_RIGHT 
A_SPAM, B_SPAM     

---------------------------------------
Each command requires this exact format (including the comma at the end)
{<BUTTON>, <DURATION>},

<BUTTON>: are the buttons above, you can also do button combinations (see example 2 below)
<DURATION>: 1 = 48.05ms

---------------------------------------
Example 1:
{LEFT, 300},
{A, 1},
{NOTHING, 20},
{RIGHT, 300},

Left stick to move left for 300 * 48.05ms
Press A once, then wait 20 * 48.05ms
Left stick to move right for 300 * 48.05ms
Repeat

---------------------------------------
Example 2:
{RIGHT | B, 1},
{RIGHT, 300},
{DPAD_UP | B | X, 1},

To do button combinations, use | between each buttons, you can combine any number of buttons
DPAD_UP + B + X is common for loading backup saves in Pokemon games

---------------------------------------
Example 3:
{A_SPAM, 40},
{B_SPAM, 100},

A_SPAM and B_SPAM are special cases
The duration must be a multiple of 2

{A_SPAM, 2}, is the same as:

{A, 1},
{NOTHING, 1},

*/

