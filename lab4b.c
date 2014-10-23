//-------------------------------------------------------------------------------
//	Name:		Dr. Chris Coulston
//	Term:		Fall 2014
//	MCU:		MSP430G2553
//	Lecture:	22
//	Date:		16 October 2014
//	Note:		Demonstration of how to combine C and assembly lanugage.
//-------------------------------------------------------------------------------
#include <msp430g2553.h>
#include "pong.h"

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBall(ball_t ball);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)
#define		SECONDS			16000000


	unsigned char	xPos, yPos, xVel, yVel, radius, button_press, inverted;

void main() {


	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;


	init();
	initNokia();
	clearDisplay();
	xPos=1;		yPos=1;
	xVel=1;		yVel=1;
	radius=2;

	ball_t myBall1;
	ball_t myBall2;
	myBall1 = createBall(xPos, yPos, xVel, yVel);
	myBall2 = createBall(xPos+4, yPos, -xVel, -yVel);

	while(1) {

		myBall1 = moveBall(myBall1);
		drawBall(myBall1);
		myBall2 = moveBall(myBall2);
		drawBall(myBall2);
		__delay_cycles(SECONDS/4);
		clearDisplay();
	}
}

