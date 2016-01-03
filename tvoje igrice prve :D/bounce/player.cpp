/*
 * 	player.cpp
 * 	Class Player
 */

#include "classes.h"

Player::Player(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->moveStep = 5;
	this->moveUp = false;
	this->moveDown = false;
	this->lifes = 3;
}

void Player::move()
{
	if(this->moveUp)
		this->y += this->moveStep;
	if(this->moveDown)
		this->y -= this->moveStep;
}

void Player::chageMoveState(int type, int state)
{
	if(type == MOVE_ADD)
	{
		if(state == MOVE_UP)
			this->moveUp = true;
		else if(state == MOVE_DOWN)
			this->moveDown = true;
	}
	else if(type == MOVE_DELETE)
	{
		if(state == MOVE_UP)
			this->moveUp = false;
		if(state == MOVE_DOWN)
			this->moveDown = false;
	}
}

void Player::colision()
{
	if(this->y < 0)
		this->y = 0;
	else if (this->y + this->height > 500)
		this->y = 500 - this->height;
}

void Player::render()
{
	glColor4ub(0, 0, 0, 255);
	glBegin(GL_QUADS);
		glVertex2f(this->x, this->y);
		glVertex2f(this->x + this->width, this->y);
		glVertex2f(this->x + this->width, this->y + this->height);
		glVertex2f(this->x, this->y + this->height);
	glEnd();
}
