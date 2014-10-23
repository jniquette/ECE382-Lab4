/*
 * pong.h
 * Author: Todd Branchflower
 * Modified by: C2C Justin Niquette
 * Date: 23 Oct 2013
 * Description: Implements a subset of the pong game
 */

#ifndef _PONG_H
#include <stdbool.h>
#define _PONG_H

#define SCREEN_WIDTH 7
#define SCREEN_HEIGHT 11

typedef struct {
    int x;
    int y;
} vector2d_t;

typedef struct {
    vector2d_t position;
    vector2d_t velocity;
} ball_t;

ball_t createBall(int xPos, int yPos, int xVel, int yVel);

ball_t moveBall(ball_t ballToMove);

void drawBall(ball_t ballToMove);

bool collidesLeft(int xPos);

bool collidesRight(int xPos);

bool collidesTop(int yPos);

bool collidesBottom(int yPos);

#endif
