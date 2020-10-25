#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Surprise Trade Sequence [3,50]----------
	// Goto box [3,6]
	{Y, 50},
	{DOWN, 2}, 
    {A, 80},
	{Y, 3},				// Multipurpose
	
	// Goto slot [7,24]
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	
	// Next box [25,26]
	{R, 1},
	{NOTHING, 14},
	
	// Wait for trade to complete [27,33]
	{A, 200},			// Confirm pokemon
	{NOTHING, 1},
	{A, 22},			// Start
	{B, 22},			// Starting to search for another Trainer!
	{NOTHING, 1},
	{B, 1},				// You can also cancel your request...
	{NOTHING, 1300},	// 1300 = wait 30 seconds
	
	// Wait for trade to complete (long wait for last pokemon) [34,40]
	{A, 200},			// Confirm pokemon
	{NOTHING, 1},
	{A, 22},			// Start
	{B, 22},			// Starting to search for another Trainer!
	{NOTHING, 1},
	{B, 1},				// You can also cancel your request...
	{NOTHING, 2600},	// 2600 = wait 60 seconds
	
	// Finish trade [41,46]
	{Y, 5},				
	{B, 1000},			// Wait 25 seconds for trade to complete + dex entry
	{NOTHING, 1},
	{B, 30},			// Exit y-comm if nothing was traded
	{NOTHING, 1},
	{B, 80},			// One extra B for new dex entry
	
	// Finish trade (no new dex entry wait) [47,50]
	{Y, 5},				// Wait 23 seconds for trade to complete
	{B, 930},			// This B press is only for trade evolution
	{NOTHING, 1},
	{B, 30},			// Exit y-comm if nothing was traded
	
	//----------Done [51,52]----------
	{HOME, 1},
	{NOTHING, 30},
};