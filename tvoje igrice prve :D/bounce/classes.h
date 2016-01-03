#ifndef CLASSES_H
#define CLASSES_H

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_mixer.h>
#include <iostream>
#include <string>

#define MOVE_NO		0
#define MOVE_UP		1
#define MOVE_DOWN	2
#define MOVE_ADD	3
#define MOVE_DELETE	4

class Player	// Player class
{
//private:
public:
	float x;
	float y;
	float width;
	float height;
	float moveStep;
	bool moveUp;
	bool moveDown;
	int lifes;

public:
	Player(float x, float y, float width, float height);
	void move();
	void chageMoveState(int type, int state);
	void colision();
	void render();
};

class Ball		// Ball Class
{
public:
	float x;
	float y;
	float radius;
	float moveX;
	float moveY;

public:
	Ball();		// Constructor
	void move();
	void colision(Player *player1, Player *player2);
	void colision();
	void render();
};

class Main
{
private:
	float x;
	float y;
	float width;
	float height;
	char* caption;
	bool isRunning;
	int FPS;
	SDL_Event event;
	Ball ball;
	Player player1 = Player(3, 210, 20, 100);
	Player player2 = Player(777, 210, 20, 100);
	Mix_Music *music;

	void events(SDL_Event event);

public:
	Main();
	void init();
	void mainloop();
	void free();
};

#endif
