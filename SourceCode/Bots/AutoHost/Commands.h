#include "../../Joystick.h"
#include <avr/pgmspace.h>

static const Command m_command[] PROGMEM = {
	//----------Setup [0,2]----------
	// Press B once to connect
	{NOTHING, 30},
	{B, 1},
	{NOTHING, 1},
	
	//----------Connect internet and talk to den [3,14]----------
	{Y, 50},
	{PLUS, 9999},		// OVERWRITTEN, refer to m_internetTime in Config.h
	{B, 1},
	{NOTHING, 6}, 
	{B, 1},				
	{NOTHING, 240},		// Allow time to load other players
	
	{A, 20},			// Interact with den
	{NOTHING, 1},
	{A, 6},				// There's energy pouring out from the den!
	{NOTHING, 1},
	{A, 30},			// You gained 2,000W!
	{NOTHING, 200},		// Communicating... standing by
	
	//----------Start raid [15,26]----------
	{A, 30},			// (Optional) You can't catch this Pokemon, Is that OK?
	{NOTHING, 1},
	{A, 2660},			// 2660 ~= until 2 min
	{NOTHING, 2510},	// 2660 + 2510 = 5170 ~= until 1 min
	
	{UP, 1},
	{NOTHING, 1},	
	{A, 1},	
	{NOTHING, 30},
	{A, 50},	
	{NOTHING, 1},
	
	// This A will be repeated 40 times
	{A, 1},				
	{NOTHING, 19},	// Wait until raid starts (between standing up to show abilities)
		
	//----------Set Link Code [27,56]----------
	// Init
	{PLUS, 40},
	{NOTHING, 1},
	
	// Reset to 0
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	
	// Press A
	{A, 1},
	{NOTHING, 1},
	
	// 1,4,7,2,5,8 [37-44]
	{UP, 1},
	{NOTHING, 1},
	{UP, 1},
	{NOTHING, 1},
	{UP, 1},
	{NOTHING, 1},
	{LEFT, 1},
	{NOTHING, 1},
	
	// 3,6,9 [45-52]
	{UP, 1},
	{NOTHING, 1},
	{UP, 1},
	{NOTHING, 1},
	{UP, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	
	// Confirm link code
	{PLUS, 51},
	{NOTHING, 1},
	{A, 1},	
	{NOTHING, 30},
	
	//----------Soft-reset [57,68]----------
	{HOME, 1},
	{NOTHING, 40},
	{X, 1},			// Close game
	{NOTHING, 8},
	{A, 1},			// Comfirm close game
	{NOTHING, 120},
	{A, 1},			// Choose game
	{NOTHING, 50},
	{A, 1},			// Pick User
	{NOTHING, 820},
	{A, 1},			// Enter game
	{NOTHING, 460},
	
	//----------Unsafe invite local friend [69,92]----------
	{HOME, 1},
	{NOTHING, 40},
	{UP, 1},
	{NOTHING, 1},
	{A, 1},				// To profile
	{NOTHING, 1},
	{DOWN, 90},			// Scroll to bottom
	{NOTHING, 1},
	{UP, 1},			// Add friend
	{NOTHING, 8},
	{A, 1},
	{NOTHING, 1},
	{DOWN, 1},			// Search for local friend
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 20},
	{A, 1},				// DC
	{NOTHING, 90},
	
	// Back to game
	{HOME, 1},
	{NOTHING, 30},
	{HOME, 1},
	{NOTHING, 60},
	{A, 1},				// Error message
	{NOTHING, 600},		// Wait until exit raid
		
	// COPY FROM Auto3DaySkipper
	//----------Sync and unsync time, goto change date [93,124]----------
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
	
	//----------Plus 1 year [125,148]----------
	// To actually Date and Time
	{DOWN, 1},
	{NOTHING, 1},
	{DOWN, 1},
	{NOTHING, 1},
	{A, 1},
	{NOTHING, 7},
	
	// Plus 1 year
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
	
	{A, 1},
	{NOTHING, 4},
	
	//----------Back to game [149,152]----------
	{HOME, 1},
	{NOTHING, 30},
	{HOME, 1},
	{NOTHING, 30},
	
	//----------Quit the raid [153,156]----------
	{B, 32},
	{NOTHING, 1},
	{A, 200},		// WAITING on local communication
	{NOTHING, 1},
	
	//----------Collect Watts [157,166]----------
	{A, 20},		// Talk
	{NOTHING, 1},
	{A, 6},			// There's energy pouring out from the den!
	{NOTHING, 1},
	{A, 30},		// You gained 2,000W!
	{NOTHING, 1},
	{A, 30},		// (Optional) You can't catch this Pokemon, Is that OK?
	{NOTHING, 1},
	{A, 120},		// WAITING on local communication
	{NOTHING, 1},
	
	//----------Goto profile [167,199]----------
	{A, 30},		// (Optional) You can't catch this Pokemon, Is that OK?
	{NOTHING, 1},
	{A, 1000},			// Wait 20 seconds (for 1 minute wait)
	{NOTHING, 2510},	// Wait extra 60 seconds (for 2 minute wait)
	
	{NOTHING, 1},
	{HOME, 1},
	{NOTHING, 40},
	{UP, 1},
	{NOTHING, 1},
	
	// 10 profiles maximum [176,193]
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
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	{RIGHT, 1},
	{NOTHING, 1},
	
	{A, 1},				// To profile
	{NOTHING, 1},
	{DOWN, 90},			// Scroll to bottom
	{NOTHING, 1},
	{UP, 1},			// Add friend
	{NOTHING, 8},
	
	//----------A Spam [200,201]----------
	{A, 1},
	{NOTHING, 9},
	
	//----------Back to game [202,205]----------
	{HOME, 1},
	{NOTHING, 30},
	{HOME, 1},
	{NOTHING, 450},	// wait 10 more seconds before start raid
};