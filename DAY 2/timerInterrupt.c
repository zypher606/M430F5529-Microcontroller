/*
 * timerInterrupt.c
 *
 *  Created on: 19-Mar-2017
 *      Author: Ashim
 */


#include <msp430f5529.h>

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    P1DIR |= BIT0;  //SET P1  TO OUTPUT DIRECTION


    TA0CCTL0 = CCIE; // CCR0 INTERRUPT ENABLED
    TA0CCR0 = 60000;
	TA0CTL = TASSEL_2 + MC_2;  //SMCLK , contmode

	_BIS_SR(LPM0_bits + GIE); //Enter LPM0 w/ interrupt



}

// Timer A0 interupt service routine

#pragma vector = TIMER0_A0_VECTOR

__interrupt void Timer_A(void){
	P1OUT ^= BIT0;
	TA0CCR0 += 60000;  //Add offset to CCR0 to fix counters upto 65535

}




// FOR GOUP INTERRUPT SOURCES, WE NEED TO CLEAR THE INTERRUPT FLAGS MANUALLY
