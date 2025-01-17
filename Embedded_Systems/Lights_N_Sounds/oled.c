/*
 * oled.c
 *  Modified for classroom use by: Stephen Longofono
 *  Created on: Aug 28, 2015
 *  Author: Brad Torrence
 */

// Header File
#include "oled.h"

// Base library
#include "system.h"

// Stellaris driver libraries
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

// OLED driver
#include "rit128x96x4.h"

// Standard C library
#include "stdio.h"

// The local variables to control execution frequency
static unsigned long timeToExec = 0;
//static const unsigned long delay = 50 * ONE_MS; // Execute every 50 ms
static const unsigned long delay = 500 * ONE_MS; //Execute every 100 ms


/*
 *  The initialization and execution functions of the OLED display
 */
void OLEDInit(){
    /*
	 * The RIT128x96x4** functions are a part of the driver API for the OLED
	 * The details for this API can be found in drivers/rit128x96x4.c
	 *
     * Create a frame for the OLED display
     * 		The ImageDraw function takes an array of unsigned char
     * 		each 8-bit char represents 2 pixels (side-by-side)
     * 		so, 4 of these bits represent a single pixel's brightness
     * 		with valid brightness values ranging (0-15)
     * 		and the pixels are represented in pairs.
     *
     *  Since the pixels are represented in pairs along the horizontal,
     *  	and the OLED is 128x96 pixels,
     *  	the horizontal frame only needs 64 elements (64 * 2 = 128).
     *  However the vertical frames will require two separate arrays,
     *  	each will have 94 elements (the OLED is 96 pixels high
     *  	but we have taken care of the two ends with the horizontal lines)
     *  The left frame will set the right column of pixels to zero,
     *  	and the right frame will set the left column of pixels to zero.
     *  The blank array elements are initialized to 0 to turn-off pixels later.
     *  It only needs 62 elements because we don't want to erase the frame.
     */
    unsigned char lframe[94], rframe[94], hframe[64], blank[62];

    // The loop is used to initialize the arrays
    unsigned int i;
    for(i = 0; i < 94; i++){
    	lframe[i] = 0xF0; 				// Vertical line for the left edge
    	rframe[i] = 0x0F; 				// Vertical line for the right edge
    	if(i < 64) hframe[i] = 0xFF; 	// Horizontal line for top and bottom
    	if(i < 62) blank[i] = 0x00; 	// The blank line used to clear the screen
    }

    //  Initialize the OLED display
    RIT128x96x4Init(1000000);
    /*
     *  Draw the frame
     *  ImageDraw takes an array of unsigned char as the first argument
     *  	the next two arguments are the x and y coordinates (respectively)
     *  	of the screen position to start drawing, and the final two arguments
     *  	are the width and height (respectively) to which the image is scaled.
     */
    // Draw upper frame starting at (0,0) with width = 128 pixels and height = 1 pixel
    // 	(width and height should match the size of array measured in pixels)
    RIT128x96x4ImageDraw(hframe, 0, 0, 128, 1);
    // Draws lower frame starting at (0,95) width = 128, height = 1
    RIT128x96x4ImageDraw(hframe, 0, 95, 128, 1);
    // Draws left frame starting at (0,1) width = 2, height = 94
    RIT128x96x4ImageDraw(lframe, 0, 1, 2, 94);
    // Draws right frame starting at (127,1) width = 2, height = 94
    RIT128x96x4ImageDraw(rframe, 127, 1, 2, 94);


    /*
     * 	Draw the message
     * 	StringDraw takes a string as the first argument
     * 		the next two arguments are again the x and y coordinates of the starting position
     * 		and the final argument is pixel brightness for the
     * 	The first function writes the first part of the message at (32,24)
     * 		with a brightness of 15 (full brightness)
     */

	RIT128x96x4StringDraw(" Press the", 32, 24, 15);
	RIT128x96x4StringDraw("\"Select\" Button", 16, 33, 15);
	RIT128x96x4StringDraw("To Continue", 32, 42, 15);

	// Enable the select button, wait for the press, then disable and reset the port
	// The button is disabled after the splash screen and the port is reset to default for future use.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG); 		// Enable Port G to use the select button
	GPIOPinTypeGPIOInput(GPIO_PORTG_BASE, GPIO_PIN_7); 	// Set the select button signal PG7 as input
	while(GPIOPinRead(GPIO_PORTG_BASE, GPIO_PIN_7));	// Wait until the signal changes (button pressed)
	SysCtlPeripheralReset(SYSCTL_PERIPH_GPIOG); 		// Reset the peripheral to default settings
	SysCtlPeripheralDisable(SYSCTL_PERIPH_GPIOG); 		// Disable it because it is no longer needed

	/*
	 *  When the select button is pressed we need to wipe the message leaving the frame on the OLED.
	 *   The loop sets the pixels to 0 everywhere except the screen's edges.
	 */
	for(i = 24; i < 50; i++)
		RIT128x96x4ImageDraw(blank, 2, i, 124, 1);

	//	Set the initial execution time.
	timeToExec = sysTickCount + delay;
}

void OLEDExec(){
	if(sysTickCount >= timeToExec) {
		/*
		*  Save the tick count into a string (character array)
		*  The length is 32 because each character is 8x8 pixels,
		*  		and since the OLED screen is 128 pixels wide
		*  		32 (128 / 8) is the number of characters that will
		*  		successfully fit on a single line of the OLED screen.
		*/
		char sysTickStr[32];

		// sprintf is a standard C function that builds strings from other arguments
		sprintf(sysTickStr, "SysTick: %d", sysTickCount);

	    //Also, display the current system clock and systick period

	    char currentSYSTICK [32];
	    char currentSYSCLOCK [32];
	    sprintf(currentSYSCLOCK, "SysClock: %ul", WhatsSysClock());
	    sprintf(currentSYSTICK, "SysTickPer: %ul", WhatsTickClock());

		//  Draw the string on the OLED display
	    //From above, we want them 9 pixels apart
	    RIT128x96x4StringDraw(sysTickStr, 6, 54, 15);
	    RIT128x96x4StringDraw(currentSYSCLOCK, 6, 63, 15);
	    RIT128x96x4StringDraw(currentSYSTICK, 6, 72, 15);

        //	Advance next execution time
	    timeToExec += delay;
	}
}

