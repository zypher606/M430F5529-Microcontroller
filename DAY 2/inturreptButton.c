#include <msp430f5529.h>

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    P1DIR |= BIT0;                      // Set P1.0 to output and P1.3 to input direction
	P1OUT &= ~BIT0;                  // set P1.0 to Off
	P1IE |= BIT1;                         // P1.3 interrupt enabled
	P1IFG &= ~BIT1;                   // P1.3 interrupt flag cleared

	_BIS_SR(GIE);       // Enable all interrupts

	while(1);                                  //Loop forever, we'll do our job in the interrupt routine...


}



#pragma vector=PORT1_VECTOR

__interrupt void Port_1(void)
    {
    P1OUT ^= BIT0;                  // Toggle P1.0
    P1IFG &= ~BIT1;                // P1.3 interrupt flag cleared
}



// FOR GOUP INTERRUPT SOURCES, WE NEED TO CLEAR THE INTERRUPT FLAGS MANUALLY
