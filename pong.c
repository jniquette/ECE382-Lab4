#include "pong.h"
#include <stdbool.h>

/*
 * pong.c
 * Author: C2C Justin Niquette
 * Date: 23 Oct 2013
 * Description: Contains methods for a subset of the pong game
 */

extern void drawBallAsm(unsigned char x, unsigned char y);

vector2d_t initVector(int x, int y)
{
    vector2d_t newVector;
    newVector.x = x;
    newVector.y = y;

    return newVector;
}

ball_t createBall(int xPos, int yPos, int xVel, int yVel)
{
    ball_t newBall;
    newBall.position = initVector(xPos, yPos);
    newBall.velocity = initVector(xVel, yVel);

    return newBall;
}

void drawBall(ball_t ball)
{
    drawBallAsm(ball.position.x, ball.position.y);

}


ball_t moveBall(ball_t ballToMove)
{
	ballToMove.position.x += ballToMove.velocity.x;
	ballToMove.position.y += ballToMove.velocity.y;

	//Check Collisions on the sides
	if(collidesLeft(ballToMove.position.x) || collidesRight(ballToMove.position.x))
		ballToMove.velocity.x *= -1;

	//Check Collisions on the top/bottom
	if(collidesTop(ballToMove.position.y) ||	collidesBottom(ballToMove.position.y))
		ballToMove.velocity.y *= -1;

	return ballToMove;

}

bool collidesLeft(int xPos)
{
	if(xPos <= 0)
		return true;
	return false;
}


bool collidesRight(int xPos)
{
	if(xPos>= SCREEN_WIDTH)
		return true;
	return false;
}


bool collidesTop(int yPos)
{
	if(yPos <= 0)
		return true;
	return false;
}


bool collidesBottom(int yPos)
{
	if(yPos >= SCREEN_HEIGHT)
		return true;
	return false;
}
