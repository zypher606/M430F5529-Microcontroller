/*
 * USCI.c
 *
 *  Created on: 19-Mar-2017
 *      Author: Ashim
 */


#include <msp430f5529.h>


int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  P4SEL |= BIT5+BIT4;                       // P4.5,4.4 = USCI_A1 TXD/RXD
  UCA1CTL1 |= UCSWRST;                      // **Put state machine in reset**
  UCA1CTL1 |= UCSSEL_2;                     // SMCLK
  UCA1BR0 = 9;                              // 1MHz 115200 (see User's Guide)
  UCA1BR1 = 0;                              // 1MHz 115200
  UCA1MCTL |= UCBRS_1 + UCBRF_0;            // Modulation UCBRSx=1, UCBRFx=0
  UCA1CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
  UCA1IE |= UCRXIE;                         // Enable USCI_A1 RX interrupt

  __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0, interrupts enabled
  __no_operation();                         // For debugger
}

// Echo back RXed character, confirm TX buffer is ready first

#pragma vector=USCI_A1_VECTOR

__interrupt void USCI_A1_ISR(void)
{
    while (!(UCA1IFG & UCTXIFG));             // USCI_A0 TX buffer ready?

    UCA1TXBUF = UCA1RXBUF;               // TX -> RXed character

}


// FOR GOUP INTERRUPT SOURCES, WE NEED TO CLEAR THE INTERRUPT FLAGS MANUALLY



