/*
 * 	ball.cpp
 * 	Class Main
 */

#include "classes.h"

Ball::Ball()
{
	this->x = 390;
	this->y = 240;
	this->radius = 20;
	this->moveX = 3;
	this->moveY = 3;
}

void Ball::move()
{
	this->x += this->moveX;
	this->y += this->moveY;
}

void Ball::colision()
{
	if(this->y < 0)
		this->moveY = -this->moveY;
	else if(this->y > 480)
		this->moveY = -this->moveY;
	if(this->x > 780)
		this->moveX = -this->moveX;
	else if(this->x < 0)
		this->moveX= -this->moveX;
}

void Ball::colision(Player *player1, Player *player2)
{
	if(this->x < player1->x + player1->width)
	{
		if(this->y > player1->y && this->y + this->radius < player1->y + player1->height)
			this->moveX = -this->moveX;
	}
	else if(this->x + this->radius > player2->x)
	{
		if(this->y > player2->y && this->y + this->radius < player2->y + player2->height)
			this->moveX = -this->moveX;
	}
}

void Ball::render()
{
	glColor4ub(255, 0, 0, 125);
	glBegin(GL_QUADS);
		glVertex2f(this->x, this->y);
		glVertex2f(this->x + this->radius, this->y);
		glVertex2f(this->x + this->radius, this->y + this->radius);
		glVertex2f(this->x, this->y + this->radius);
	glEnd();
}
