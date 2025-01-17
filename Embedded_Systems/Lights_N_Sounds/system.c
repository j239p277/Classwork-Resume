/*
 *  system.c
 *  Modified for classroom use by: Stephen Longofono
 *  Created on: Aug 28, 2015
 *  Author: Brad Torrence
 */

// Always include the header file inside the associated source file!
#include "system.h"

// Stellaris driver libraries
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"

//*************************************************************************************************
// Global variables (marked with extern) must be redeclared before they can be used globally
// This is a good place to also initialize the value using some constant or literal.
//*************************************************************************************************
volatile unsigned long sysTickCount = 0;

//*************************************************************************************************
// The SysTick interrupt service routine (ISR).
// This is a callback function that is run when the system encounters a systick interrupt.
// It maintains the systick count for the system by simply incrementing the count.
//*************************************************************************************************
static
void sysTickISR() {
	sysTickCount++;
}

/*************************************************************************************************
 *	Initializes the system clock to run from the crystal
 *		and enables the board's systick functionality.
 ************************************************************************************************/
void systemInit() {
    // Set the clocking to run directly from the crystal.
	//PLL = Phase Locked Loop - holds the phase with system clock to prevent any drift
	//SysCtlClockSet(divider | pll on | Main Oscillator | use 8MHz crystal)
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);

    // Configure and Enable SysTick mechanism
    //As the code is, the 50MHz clock is divided by 1000, giving 50000 clocks per tick period.
    //So since the clock operates at 50MHz, and there are 50000 clocks per tick, we get 1ms
    //ticks, or 1KHz
    SysTickPeriodSet(SysCtlClockGet() / SYSTICK_FREQUENCY);

    //Sets up the interrupt, with a pointer to the routine that should execute on interrupt.
    //In this case, it it the funciton we defined above, sysTickISR()
    SysTickIntRegister(sysTickISR);

    //
    SysTickIntEnable();
    SysTickEnable();
}

/*********************************************************************************************
 * Allows OLED to monitor system clock
 * for comparison with Systick
 *
*********************************************************************************************/


extern unsigned long WhatsSysClock(){

	return SysCtlClockGet();

}

/*********************************************************************************************
 * Allows OLED to monitor Systick
 * for comparison with system clock
 *
*********************************************************************************************/


extern unsigned long WhatsTickClock(){

	return SysTickPeriodGet();

}

