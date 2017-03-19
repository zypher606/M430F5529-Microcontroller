/*
 * pwm.c
 *
 *  Created on: 19-Mar-2017
 *      Author: Ashim
 */


#include <msp430f5529.h>

int a[5] = {0, 3200, 6400, 12800, 25500};
int i = 0;

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    P1DIR |= BIT2;  //SET P1.2  TO OUTPUT DIRECTION
    P1SEL |= BIT2;  //Set P1.2 SEL as GPIO
    TA0CCR0 = 51200;  // Max cycle
    TA0CCR1 = a[0];   // PWM duty cycle
    TA0CCTL1 = OUTMOD_7;  // ta0ccr1 reset/set high voltage ; below count, low voltage when past

    TA0CTL = TASSEL_2 + MC_1 + TAIE + ID_3;
    // Timer A control set to SMCLK, 1MHz and count up mode MC_1


	_BIS_SR(LPM0_bits + GIE); //Enter LPM0 w/ interrupt

	while (1);


}

// Timer A0 interupt service routine

#pragma vector = TIMER0_A1_VECTOR

__interrupt void timer(void){
	TA0CTL &= ~TAIFG;
	TA0CCR1 = a[++i];
	if (i>4)
	{
		i = 0;
	}

}




// FOR GOUP INTERRUPT SOURCES, WE NEED TO CLEAR THE INTERRUPT FLAGS MANUALLY


