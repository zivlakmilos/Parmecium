/*
 * 	main.cpp
 * 	Class Main
 */

#include "classes.h"

Main::Main()
{
	this->x = 100;
	this->y = 100;
	this->width = 800;
	this->height = 500;
	this->caption = "[ZI] Bonce";
	this->isRunning = true;
	this->FPS = 1;
	//this->player1 = Player(3, 210, 20, 100);
	//this->player2 = Player(777, 210, 20, 100);
	music = NULL;
}

void Main::init()
{
	// SDL initialization
	SDL_Init(SDL_INIT_EVERYTHING);

	// Set OpenGL memory usage
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Set window caption
	SDL_WM_SetCaption(this->caption, NULL);

	// Set size of window
	SDL_SetVideoMode(this->width, this->height, 32, SDL_OPENGL);

	// Specified the clear color
	glClearColor(1, 1, 1, 1);

	// Part of screen to be display
	glViewport(0, 0, this->width, this->height);

	// Shade model
	glShadeModel(GL_SMOOTH);

	// 2D rendering
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	// Disable depth checking
	glDisable(GL_DEPTH_TEST);

	// Clear the window
	glClear(GL_COLOR_BUFFER_BIT);

	// Load music
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	music = Mix_LoadMUS("music.wav");
	Mix_PlayMusic(music, -1);
}

void Main::mainloop()
{
	/*
	 * 	main loop
	 */
	while(this->isRunning)
	{
		// EVENTS
		this->events(event);

		// LOGIC
		this->ball.move();
		this->player1.move();
		this->player2.move();
		this->ball.colision();
		this->ball.colision(&player1, &player2);
		this->player1.colision();
		this->player2.colision();

		// REDNER
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		glOrtho(0, this->width, 0, this->height, -1, 1.);
		this->player1.render();
		this->player2.render();
		this->ball.render();
		glPopMatrix();
		SDL_GL_SwapBuffers();

		// Regulate FPS
		SDL_Delay(this->FPS);
	}

	Mix_FreeMusic(music);
}

void Main::events(SDL_Event event)
{
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
			this->isRunning = false;
		if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
			this->isRunning = false;

		if(event.type == SDL_KEYDOWN)
		{
			if(event.key.keysym.sym == SDLK_w)
				player1.chageMoveState(MOVE_ADD, MOVE_UP);
			else if(event.key.keysym.sym == SDLK_s)
				player1.chageMoveState(MOVE_ADD, MOVE_DOWN);
			if(event.key.keysym.sym == SDLK_UP)
				player2.chageMoveState(MOVE_ADD, MOVE_UP);
			else if(event.key.keysym.sym == SDLK_DOWN)
				player2.chageMoveState(MOVE_ADD, MOVE_DOWN);
		}
		if(event.type == SDL_KEYUP)
		{
			if(event.key.keysym.sym == SDLK_w)
				player1.chageMoveState(MOVE_DELETE, MOVE_UP);
			else if(event.key.keysym.sym == SDLK_s)
				player1.chageMoveState(MOVE_DELETE, MOVE_DOWN);
			if(event.key.keysym.sym == SDLK_UP)
				player2.chageMoveState(MOVE_DELETE, MOVE_UP);
			else if(event.key.keysym.sym == SDLK_DOWN)
				player2.chageMoveState(MOVE_DELETE, MOVE_DOWN);
		}
	}
}
