/*
 * ADC.c
 *
 *  Created on: 19-Mar-2017
 *      Author: Ashim
 */

/*
 * timerInterrupt.c
 *
 *  Created on: 19-Mar-2017
 *      Author: Ashim
 */


#include <msp430f5529.h>

unsigned int value_adc=0;

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  ADC12CTL0 = ADC12SHT02 + ADC12ON;         // Sampling time, ADC12 on
  ADC12CTL1 = ADC12SHP;                     // Use sampling timer
  ADC12CTL0 |= ADC12ENC;
  P6SEL |= 0x01;                            // P6.0 ADC option select
  P1DIR |= 0x01;                            // P1.0 output

  while (1)
  {
    ADC12CTL0 |= ADC12SC;// Start sampling/conversion
    value_adc=ADC12MEM0;
    if(value_adc>=600)
      P1OUT |= BIT0;   // P1.0 = 1
    else
      P1OUT &= ~BIT0;          // P1.0 = 0
  }
}



// FOR GOUP INTERRUPT SOURCES, WE NEED TO CLEAR THE INTERRUPT FLAGS MANUALLY



