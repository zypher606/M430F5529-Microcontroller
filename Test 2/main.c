#include <msp430.h> 

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    P8DIR |= BIT2;
	P3DIR |= BIT7;
	P4DIR |= ~BIT0;
	P4DIR |= ~BIT3;
	P1DIR |= ~BIT2;
	P1DIR |= ~BIT3;
	P1DIR |= ~BIT4;
	P1DIR |= ~BIT5;
}


void zero(){
	P8OUT |= BIT2;
	P3OUT |= BIT7;
	P4OUT |= ~BIT0;
	P4OUT |= ~BIT3;
	P1OUT |= ~BIT2;
	P1OUT |= ~BIT3;
	P1OUT |= ~BIT4;
	P1OUT |= ~BIT5;

}

void one(){
	P8OUT |= BIT2;
	P3OUT |= BIT7;
	P4OUT |= BIT0;
	P4OUT |= BIT3;
	P1OUT |= BIT2;
	P1OUT |= ~BIT3;
	P1OUT |= ~BIT4;
	P1OUT |= BIT5;

}


void two(){
	P8OUT |= BIT2;
	P3OUT |= ~BIT7;
	P4OUT |= BIT0;
	P4OUT |= ~BIT3;
	P1OUT |= ~BIT2;
	P1OUT |= BIT3;
	P1OUT |= ~BIT4;
	P1OUT |= ~BIT5;

}


void three(){
	P8OUT |= BIT2;
	P3OUT |= ~BIT7;
	P4OUT |= BIT0;
	P4OUT |= BIT3;
	P1OUT |= ~BIT2;
	P1OUT |= ~BIT3;
	P1OUT |= ~BIT4;
	P1OUT |= ~BIT5;

}


void four(){
	P8OUT |= BIT2;
	P3OUT |= ~BIT7;
	P4OUT |= ~BIT0;
	P4OUT |= BIT3;
	P1OUT |= BIT2;
	P1OUT |= ~BIT3;
	P1OUT |= ~BIT4;
	P1OUT |= BIT5;

}
