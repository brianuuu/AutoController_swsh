/*
Pokemon Sword & Shield Remote Controller
	brianuuuSonic
	2020-12-26

Based on the LUFA library's Low-Level Joystick Demo
	(C) Dean Camera
Based on the HORI's Pokken Tournament Pro Pad design
	(C) HORI

This project implements a modified version of HORI's Pokken Tournament Pro Pad
USB descriptors to allow for the creation of custom controllers for the
Nintendo Switch. This also works to a limited degree on the PS3.

Since System Update v3.0.0, the Nintendo Switch recognizes the Pokken
Tournament Pro Pad as a Pro Controller. Physical design limitations prevent
the Pokken Controller from functioning at the same level as the Pro
Controller. However, by default most of the descriptors are there, with the
exception of Home and Capture. Descriptor modification allows us to unlock
these buttons for our use.

This project is based on auto-controller code written by brianuuuuSonic
*/

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include "../../Config/uart.h"
#include "../../Joystick.h"
#include "Config.h"

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CHECK_BIT(var,pos) (var & (1UL << pos))
#define COMMAND_MAX 30
#define SMART_HEX_VERSION 6

// Main entry point.
int main(void) {
	// We'll start by performing hardware and peripheral setup.
	SetupHardware();
	// We'll then enable global interrupts for our use.
	GlobalInterruptEnable();
	// Then we'll initialize the serial communications with the external computer
	
	// Once that's done, we'll enter an infinite loop.
	for (;;)
	{
		// We need to run our task to process and deliver data for our IN and OUT endpoints.
		HID_Task();
		// We also need to run the main USB management task.
		USB_USBTask();
	}
}

// Configures hardware and peripherals, such as the USB peripherals.
void SetupHardware(void) {
	// We need to disable watchdog if enabled by bootloader/fuses.
	MCUSR &= ~(1 << WDRF);
	wdt_disable();

	// We need to disable clock division before initializing the USB hardware.
	//clock_prescale_set(clock_div_1);
	// We can then initialize our hardware and peripherals, including the USB stack.
	
	CPU_PRESCALE(0);  // run at 16 MHz
	uart_init(9600);
	
	#ifdef ALERT_WHEN_DONE
	// Both PORTD and PORTB will be used for the optional LED flashing and buzzer.
	#warning LED and Buzzer functionality enabled. All pins on both PORTB and \
PORTD will toggle when printing is done.
	DDRD  = 0xFF; //Teensy uses PORTD
	PORTD =  0x0;
                  //We'll just flash all pins on both ports since the UNO R3
	DDRB  = 0xFF; //uses PORTB. Micro can use either or, but both give us 2 LEDs
	PORTB =  0x0; //The ATmega328P on the UNO will be resetting, so unplug it?
	#endif
	// The USB stack should be initialized last.
	USB_Init();
}

// Fired to indicate that the device is enumerating.
void EVENT_USB_Device_Connect(void) {
	// We can indicate that we're enumerating here (via status LEDs, sound, etc.).
}

// Fired to indicate that the device is no longer connected to a host.
void EVENT_USB_Device_Disconnect(void) {
	// We can indicate that our device is not ready (via status LEDs, sound, etc.).
}

// Fired when the host set the current configuration of the USB device after enumeration.
void EVENT_USB_Device_ConfigurationChanged(void) {
	bool ConfigSuccess = true;

	// We setup the HID report endpoints.
	ConfigSuccess &= Endpoint_ConfigureEndpoint(JOYSTICK_OUT_EPADDR, EP_TYPE_INTERRUPT, JOYSTICK_EPSIZE, 1);
	ConfigSuccess &= Endpoint_ConfigureEndpoint(JOYSTICK_IN_EPADDR, EP_TYPE_INTERRUPT, JOYSTICK_EPSIZE, 1);

	// We can read ConfigSuccess to indicate a success or failure at this point.
}

// Process control requests sent to the device from the USB host.
void EVENT_USB_Device_ControlRequest(void) {
	// We can handle two control requests: a GetReport and a SetReport.

	// Not used here, it looks like we don't receive control request from the Switch.
}

typedef enum {
	REMOTE_USER,
	SEQUENCE,
	DONE
} State_t;
State_t state = REMOTE_USER;

uint32_t button_flag = 2;	// start with B-press to enable controller on Switch
uint8_t mode = 0;	// 0xFF = remote, 0xFE = sequence

uint8_t commandIndex = 0;
uint16_t durationCount = 0;
char command_list[COMMAND_MAX];
uint16_t duration_list[COMMAND_MAX];

uint8_t loopStart = 0;
uint16_t loopCount = 0;
bool loopInProgress = false;

// Process and deliver data from IN and OUT endpoints.
void HID_Task(void) {
	// If the device isn't connected and properly configured, we can't do anything here.
	if (USB_DeviceState != DEVICE_STATE_Configured)
		return;

	// We'll start with the OUT endpoint.
	Endpoint_SelectEndpoint(JOYSTICK_OUT_EPADDR);
	// We'll check to see if we received something on the OUT endpoint.
	if (Endpoint_IsOUTReceived())
	{
		// If we did, and the packet has data, we'll react to it.
		if (Endpoint_IsReadWriteAllowed())
		{
			// We'll create a place to store our data received from the host.
			USB_JoystickReport_Output_t JoystickOutputData;
			// We'll then take in that data, setting it up in our storage.
			while(Endpoint_Read_Stream_LE(&JoystickOutputData, sizeof(JoystickOutputData), NULL) != ENDPOINT_RWSTREAM_NoError);
			// At this point, we can react to this data.

			// However, since we're not doing anything with this data, we abandon it.
		}
		// Regardless of whether we reacted to the data, we acknowledge an OUT packet on this endpoint.
		Endpoint_ClearOUT();
	}

	// We'll then move on to the IN endpoint.
	Endpoint_SelectEndpoint(JOYSTICK_IN_EPADDR);
	// We first check to see if the host is ready to accept data.
	if (Endpoint_IsINReady())
	{
		// We'll create an empty report.
		USB_JoystickReport_Input_t JoystickInputData;
		// We'll then populate this report with what we want to send to the host.
		GetNextReport(&JoystickInputData);
		// Once populated, we can output this data to the host. We do this by first writing the data to the control stream.
		while(Endpoint_Write_Stream_LE(&JoystickInputData, sizeof(JoystickInputData), NULL) != ENDPOINT_RWSTREAM_NoError);
		// We then send an IN packet on this endpoint.
		Endpoint_ClearIN();
	}
	
	// Lastly we'll check the serial port for incoming messages from the computer
	if (mode == 0 && uart_available() > 0)
	{
		// Check first byte in the queue, if not the mode we want, clear everything
		mode = uart_getchar();
		if (mode < 0xFE)
		{
			mode = 0;
			
			state = DONE;
			while (uart_available() > 0)
			{
				uart_getchar();
			}
		}
	}
	else if (mode == 0xFF)
	{
		// Wait until we have enough data to read
		if (uart_available() >= 4)
		{
			state = REMOTE_USER;
			button_flag = 0;
			for (uint8_t i = 0; i < 4; i++)
			{
				button_flag |= ((uint32_t)(uart_getchar()) << (8UL * i));
				//uart_putchar(received_command); // DEBUG echo incoming messages back to computer
			}
			
			// Discard the rest
			while (uart_available() > 0)
			{
				uart_getchar();
			}
			
			// Can read next data now
			mode = 0;
			return;
		}
	}
	else if (mode == 0xFE)
	{
		// Wait until we have enough data to read
		if (uart_available() >= COMMAND_MAX * 3)
		{
			state = SEQUENCE;
			commandIndex = 0;
			durationCount = 0;
			loopStart = 0;
			loopCount = 0;
			loopInProgress = false;
			for (int i = 0; i < COMMAND_MAX; i++)
			{
				command_list[i] = 0;
				duration_list[i] = 0;
				
				command_list[i] = uart_getchar();
				duration_list[i] |= (uint16_t)(uart_getchar());
				duration_list[i] |= ((uint16_t)(uart_getchar()) << 8);
			}
			
			// Discard the rest
			while (uart_available() > 0)
			{
				uart_getchar();
			}
			
			// Can read next data now
			mode = 0;
			return;
		}
	}
}

#define ECHOES 5
int echoes = ECHOES;
USB_JoystickReport_Input_t last_report;

// Prepare the next report for the host.
void GetNextReport(USB_JoystickReport_Input_t* const ReportData) {

	// Prepare an empty report
	memset(ReportData, 0, sizeof(USB_JoystickReport_Input_t));
	ReportData->LX = STICK_CENTER;
	ReportData->LY = STICK_CENTER;
	ReportData->RX = STICK_CENTER;
	ReportData->RY = STICK_CENTER;
	ReportData->HAT = HAT_CENTER;

	// Repeat ECHOES times the last report
	if (echoes > 0)
	{
		memcpy(ReportData, &last_report, sizeof(USB_JoystickReport_Input_t));
		echoes--;
		return;
	}

	// States and moves management
	switch (state)
	{
		case REMOTE_USER:
		{
			// Nothing, early out
			if (button_flag == 0)
			{
				state = DONE;
				return;
			}
			
			// Buttons
			if (CHECK_BIT(button_flag, 0))
				ReportData->Button |= SWITCH_A;
			if (CHECK_BIT(button_flag, 1))
				ReportData->Button |= SWITCH_B;
			if (CHECK_BIT(button_flag, 2))
				ReportData->Button |= SWITCH_X;
			if (CHECK_BIT(button_flag, 3))
				ReportData->Button |= SWITCH_Y;
			if (CHECK_BIT(button_flag, 4))
				ReportData->Button |= SWITCH_L;
			if (CHECK_BIT(button_flag, 5))
				ReportData->Button |= SWITCH_R;
			if (CHECK_BIT(button_flag, 6))
				ReportData->Button |= SWITCH_ZL;
			if (CHECK_BIT(button_flag, 7))
				ReportData->Button |= SWITCH_ZR;
			if (CHECK_BIT(button_flag, 8))
				ReportData->Button |= SWITCH_PLUS;
			if (CHECK_BIT(button_flag, 9))
				ReportData->Button |= SWITCH_MINUS;
			if (CHECK_BIT(button_flag, 10))
				ReportData->Button |= SWITCH_HOME;
			if (CHECK_BIT(button_flag, 11))
				ReportData->Button |= SWITCH_CAPTURE;
			if (CHECK_BIT(button_flag, 12))
				ReportData->Button |= SWITCH_LCLICK;
			if (CHECK_BIT(button_flag, 17))
				ReportData->Button |= SWITCH_RCLICK;
			
			
			// DPad
			bool up, down, left, right;
			up = CHECK_BIT(button_flag, 22);
			down = CHECK_BIT(button_flag, 23);
			left = CHECK_BIT(button_flag, 24);
			right = CHECK_BIT(button_flag, 25);
			if (up)
			{
				ReportData->HAT = HAT_TOP;
				if (left)
				{
					ReportData->HAT = HAT_TOP_LEFT;
				}
				else if (right)
				{
					ReportData->HAT = HAT_TOP_RIGHT;
				}
			}
			else if (down)
			{
				ReportData->HAT = HAT_BOTTOM;
				if (left)
				{
					ReportData->HAT = HAT_BOTTOM_LEFT;
				}
				else if (right)
				{
					ReportData->HAT = HAT_BOTTOM_RIGHT;
				}
			}
			else if (left)
			{
				ReportData->HAT = HAT_LEFT;
			}
			else if (right)
			{
				ReportData->HAT = HAT_RIGHT;
			}
			
			// L-Stick
			up = CHECK_BIT(button_flag, 13);
			down = CHECK_BIT(button_flag, 14);
			left = CHECK_BIT(button_flag, 15);
			right = CHECK_BIT(button_flag, 16);
			if (up)
			{
				ReportData->LY = STICK_MIN;
			}
			else if (down)
			{
				ReportData->LY = STICK_MAX;
			}
			if (left)
			{
				ReportData->LX = STICK_MIN;		
			}
			else if (right)
			{
				ReportData->LX = STICK_MAX;
			}
			
			// R-Stick
			up = CHECK_BIT(button_flag, 18);
			down = CHECK_BIT(button_flag, 19);
			left = CHECK_BIT(button_flag, 20);
			right = CHECK_BIT(button_flag, 21);
			if (up)
			{
				ReportData->RY = STICK_MIN;
			}
			else if (down)
			{
				ReportData->RY = STICK_MAX;
			}
			if (left)
			{
				ReportData->RX = STICK_MIN;		
			}
			else if (right)
			{
				ReportData->RX = STICK_MAX;
			}
			
			break;
		}

		case SEQUENCE: 
		{
			switch (command_list[commandIndex])
			{
				case '0': //NOTHING:
					break;
					
				case '1': //A:
					ReportData->Button |= SWITCH_A;
					break;

				case '2': //B:
					ReportData->Button |= SWITCH_B;
					break;

				case '3': //X:
					ReportData->Button |= SWITCH_X;
					break;
				
				case '4': //Y:
					ReportData->Button |= SWITCH_Y;
					break;

				case '5': //L:
					ReportData->Button |= SWITCH_L;
					break;

				case '6': //R:
					ReportData->Button |= SWITCH_R;
					break;

				case '7': //ZL:
					ReportData->Button |= SWITCH_ZL;
					break;

				case '8': //ZR:
					ReportData->Button |= SWITCH_ZR;
					break;

				case '9': //PLUS:
					ReportData->Button |= SWITCH_PLUS;
					break;

				case 'q': //MINUS:
					ReportData->Button |= SWITCH_MINUS;
					break;

				case 'w': //HOME:
					ReportData->Button |= SWITCH_HOME;
					break;

				case 'e': //CAPTURE:
					ReportData->Button |= SWITCH_CAPTURE;
					break;

				case 'r': //LCLICK:
					ReportData->Button |= SWITCH_LCLICK;
					break;

				case 't': //UP:
					ReportData->LY = STICK_MIN;				
					break;
					
				case 'y': //DOWN:
					ReportData->LY = STICK_MAX;				
					break;

				case 'u': //LEFT:
					ReportData->LX = STICK_MIN;				
					break;

				case 'i': //RIGHT:
					ReportData->LX = STICK_MAX;				
					break;
					
				case 'o': //RCLICK:
					ReportData->Button |= SWITCH_RCLICK;
					break;
					
				case 'p': //RUP:
					ReportData->RY = STICK_MIN;				
					break;

				case 'a': //RDOWN:
					ReportData->RY = STICK_MAX;				
					break;
					
				case 's': //RLEFT:
					ReportData->RX = STICK_MIN;				
					break;

				case 'd': //RRIGHT:
					ReportData->RX = STICK_MAX;				
					break;
					
				case 'f': //DPAD_UP:
					ReportData->HAT = HAT_TOP;
					break;
					
				case 'g': //DPAD_DOWN:
					ReportData->HAT = HAT_BOTTOM;
					break;
					
				case 'h': //DPAD_LEFT:
					ReportData->HAT = HAT_LEFT;
					break;
					
				case 'j': //DPAD_RIGHT:
					ReportData->HAT = HAT_RIGHT;
					break;

				case 'k': //TRIGGERS:
					ReportData->Button |= SWITCH_L | SWITCH_R;
					break;

				case 'l': //UP_LEFT:
					ReportData->LY = STICK_MIN;		
					ReportData->LX = STICK_MIN;	
					break;

				case 'z': //UP_RIGHT:
					ReportData->LY = STICK_MIN;		
					ReportData->LX = STICK_MAX;	
					break;

				case 'x': //DOWN_LEFT:
					ReportData->LY = STICK_MAX;		
					ReportData->LX = STICK_MIN;	
					break;
					
				case 'c': //DOWN_RIGHT:
					ReportData->LY = STICK_MAX;		
					ReportData->LX = STICK_MAX;	
					break;
					
				case 'v': //A_SPAM:
				{
					// Same as (A,1,Nothing,1) * durationCount / 2
					if (durationCount % 2 == 0)
					{
						ReportData->Button |= SWITCH_A;
					}
					break;
				}
					
				case 'b': //B_SPAM:
				{
					// Same as (B,1,Nothing,1) * durationCount / 2
					if (durationCount % 2 == 0)
					{
						ReportData->Button |= SWITCH_B;
					}
					break;
				}
				
				case 'n': // LOOP
				{
					// loop command finishes immadiately
					uart_putchar(0xFF);
					durationCount = 0;
					
					int loopDuration = duration_list[commandIndex];
					if (loopDuration > 0)
					{
						loopCount++;
						if (loopCount == loopDuration)
						{
							// continue with commands after this loop
							commandIndex++;
							loopStart = commandIndex;
							loopCount = 0;
							loopInProgress = false;
							
							// We reached the end of a command sequence
							if (commandIndex >= COMMAND_MAX)
							{
								state = DONE;
							}	
							
							return;
						}
					}
					
					// Go back to beginning of the loop
					commandIndex = loopStart;
					loopInProgress = true;
					return;
				}
				
				case 'm': //UP_A:
					ReportData->LY = STICK_MIN;	
					ReportData->Button |= SWITCH_A;
					break;
					
				case ',': //DOWN_A:
					ReportData->LY = STICK_MAX;	
					ReportData->Button |= SWITCH_A;
					break;
					
				case '.': //RIGHT_A:
					ReportData->LX = STICK_MAX;	
					ReportData->Button |= SWITCH_A;	
					break;
					
				case '/': //DPAD_RIGHT_R:
					ReportData->HAT = HAT_RIGHT;
					ReportData->Button |= SWITCH_R;
					break;
					
				case '@': //LUP_LCLICK:
					ReportData->LY = STICK_MIN;	
					ReportData->Button |= SWITCH_LCLICK;
					break;
					
				case '#': //LLEFT_B:
					ReportData->LX = STICK_MIN;	
					ReportData->Button |= SWITCH_B;						
					break;
					
				case '$': //LRIGHT_B:
					ReportData->LX = STICK_MAX;	
					ReportData->Button |= SWITCH_B;						
					break;
					
				case '%': //B_X_DPAD_UP:
					ReportData->Button |= SWITCH_B;
					ReportData->Button |= SWITCH_X;
					ReportData->HAT = HAT_TOP;
					break;
					
				case '!':
				default:
					// Invalid button
					state = DONE;
					return;
			}
			
			durationCount++;
			if (durationCount >= duration_list[commandIndex])
			{
				uart_putchar((commandIndex == 0 && !loopInProgress) ? (char)SMART_HEX_VERSION : 0xFF); // this feedback a command has finished
				commandIndex++;
				durationCount = 0;

				// We reached the end of a command sequence
				if (commandIndex >= COMMAND_MAX)
				{
					state = DONE;
					return;
				}		
			}
			break;
		}
		
		case DONE: return;
	}

	// Prepare to echo this report
	memcpy(&last_report, ReportData, sizeof(USB_JoystickReport_Input_t));
	
	echoes = ECHOES;
}
