ECE382-Lab1 "Etch-a-Sketch and Pong"
====================================

##Purpose
The purpose of this lab is to demonstrate how C programs can operate with Assembly code though the use of method calls and globals. This lab also demonstrates knowledge of graphics output through the Serial Communications Interface of the MSP430G2553 to the Nokia 1202 LCD Boosterpack.

##Prelab
The prelab can be found at https://github.com/jniquette/ECE382-Lab4/blob/master/Prelab%204.docx

###Software Diagram
![alt text](https://github.com/jniquette/ECE382-Lab4/blob/master/img/software%20diagram.png "Software Diagram")

##Code
This program makes use of assembly (.asm), C source (.c), and C header (.h) files.
- pong.h: C Header file for Pong Game
- pong.c: C Source file for Pong Game
- nokia.asm: Assembly source file containing LCD and draw methods
-- Contains bonus features of using a ball, using multiple balls, and inverting the colors.
- lab4req.c: C Source file for "Required Functionality"
- lab4b.c: C Source file for "B Functionality"
- lab4a.c: C Source file for "A Functionality"

##Testing Methodology
Since all parts of this lab involve modifying the LCD display, all tests were visual.

##Test Cases
###Required Functionality
Expected Result: A square block that could be moved with the directional buttons. When the ball is moved it will act similar to an "Etch-a-sketch", drawing a square in the new position on the screen. When the user presses the Aux button on the Nokia board, the color will switch to "inverted" and will erase all black marks that the square passes.

Actual Result: The code worked as expected.

###B Functionality
Expected Result: A block drawn on the screen that would "bounce" off of the edges of the display. Additionally, I wanted to create a drawBallAsm method that would draw a filled circle instead of a block with inverted colors as desired, as well as C code that would allow multiple balls to be displayed on the screen at one time.

Actual Result: The code worked as expected. I added a drawBall function in pong.c as a helper function that would pass along the ball's position and color to the assembly code.

###A Functionality
Expected Result: A ball and paddle drawn on the screen. The user can move the paddle and if the bouncing ball hits the paddle it will rebound and stay in play. If the ball passes by the paddle the game is over.

Actual Result: The code did not work as expected.

Analysis: I believe there is a flaw in my code that is causing the paddle to move on it's own with the same timing as the ball rather than at the user's command.

##Documentation Statement
Nothing to report.