#include <msp430f5529.h>

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P4DIR |= BIT7; //SETTING OUTPUT TO THE 4.7 LED
	// P2DIR = 0X00 IS SET DEFAULT
	P2REN |= BIT1;   // TAKINg register enable; 0-> pull down; 1=> PULL UP
	P2OUT |= BIT1;

	while(1){
		if(!(P2IN & BIT1)){  // PIN2 AND  00000010 => CHECK IF 2.1 IS HIGH OR NOT
			P4OUT = P4OUT | BIT7;   // TURN ON THE LED IF 2.1 IS HIGH OR P4OUT |= BIT7
		}
		else{
			P4OUT = P4OUT & ~BIT7; // OR P4OUT &= ~BIT7
		}
	}

}
