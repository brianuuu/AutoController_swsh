#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Sync and unsync time, goto change date [3,40]----------
	// To System Settings
	{HOME, 1},
	{NOTHING, 30},
	{DOWN, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	
	// To Date and Time
	{DOWN, 80},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 8},
	
	// Sync and unsync time
	{A, 1},
	{NOTHING, 4},
	{A, 1},
	{NOTHING, 8},
	
	// To actually Date and Time
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 7},
	
	//----------Plus 1 year [41,56]----------
	{RIGHT, 1},		// EU/US start
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{UP, 1},		// JP start
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},	// EU end
	{RIGHT, 1},
	{NOTHING, 1},	// US end
	{RIGHT, 1},		
	{NOTHING, 1},	// JP end
	
	//----------Back to game [57,62]----------
	{A, 1},
	{NOTHING, 4},
	{HOME, 1},
	{NOTHING, 30},
	{HOME, 1},
	{NOTHING, 30},
	
	//----------Loto [63,102]----------
	{A, 12},			// Greetingzzz Trainer! What can I help you with? Zzzrt?
	{NOTHING, 1},
	{B, 12},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{A, 31},		// I've now connected to the serverzzz at the Loto-ID Center!
	{NOTHING, 1},
	{B, 22},		// We'll draw a number, and if it'zzz a match for the ID No. of any of your Pokemon, you could
	{NOTHING, 1},
	{B, 10},		// win fabulous prizzzes!
	{NOTHING, 1},
	{B, 24},		// Ready to save your progress and try your luck?
	{NOTHING, 1},
	{A, 45},		// Yes
	{NOTHING, 1},
	{B, 19},		// Then here we go... Bezzzt of luck to you!
	{NOTHING, 1},
	{B, 24},		// ... ... ...
	{NOTHING, 1},
	{B, 7},			// Here'zzz your number: xxxxx!
	{NOTHING, 1},
	{B, 10},		// Let's see if it matches any Pokemon's ID number!
	{NOTHING, 1},
	{B, 96},		// Oh! Congratulationszzz!
	{NOTHING, 1},
	{B, 22},		// That'zzz amazing! The number matches up with the ID No. of ??? in your Boxes!
	{NOTHING, 1},
	{B, 22},		// Oh! The last xxx digitzzz matched! (Longest: Moomoo Milk <- fuck you)
	{NOTHING, 1},
	{B, 26},		// (Award dialog)
	{NOTHING, 1},
	{B, 95},		// You obtained a xxx!
	{NOTHING, 1},
	{B, 20},		// You put the xxx in your Bag's xxx pocket.
	{NOTHING, 1},
	{B, 16},		// Looking forward to your nexzzzt attempt!
	{NOTHING, 1},
	{B, 1},
	{NOTHING, 8}
};