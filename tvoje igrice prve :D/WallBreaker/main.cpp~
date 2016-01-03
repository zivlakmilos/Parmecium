/*
Compile command:
g++ -o test main.cpp -lSDLmain -lSDL -lGL
*/

// specific headers
#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include <iostram>

bool checkCollision(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh)
{
	if(Ay+Ah < By) return false;
	else if(Ay > By+Bh) return false;
	else if(Ax+Aw < Bx) return false;
	else if(Ax > Bx+Bw) return false;

	return true;
}

struct brick
{
	float x;
	float y;
	float width;
	float height;
	bool alive;
};

// start of the programm
int main(int argc, char* args[])
{
	// initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// Ste OpenGL memory usage
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Caption of the window
	SDL_WM_SetCaption("Out first gmae", NULL);

	// Size of window
	SDL_SetVideoMode(600, 400, 32, SDL_OPENGL);

	// Specific the clear color
	glClearColor(1, 1, 1, 1);	// RED, GREEN, BLUE, ALPHA
	
	// What portion of teh screen we will display
	glViewport(0, 0, 600, 400);

	// Shader model - Use this
	glShadeModel(GL_SMOOTH);

	// 2D rendering
	glMatrixMode(GL_PROJECTION);

	// "Save" it
	glLoadIdentity();

	// Disable depth checking
	glDisable(GL_DEPTH_TEST);

	std::cout << "OpenGL is running\n";
	std::cout << "Main loop has started\n";

	// Handles the main loop
	bool isRunning = true;

	// For handling with event
	SDL_Event event;

	float myX = 300;
	float myY = 370;
	float width = 80;
	float height = 20;

	bool left = false, right = false;	// we save in whitch state the button is

	// The ball variables
	float ballX = 50;
	float ballY = 350;
	float ballWH = 30;

	float vellX = 3.0;
	float vellY = -3.0;

	// Brick elements
	const static int BRICKS = 45;
	brick bricks[BRICKS];

	int x = 5;
	int y = 10;	
	for(int n = 0;  n < BRICKS; n++)
	{
		if (x > 560)
		{
			x = 4;
			y += 25;
		}
		bricks[n].x = x;
		bricks[n].y = y;
		bricks[n].width = 60;
		bricks[n].height = 20;
		bricks[n].alive = true;
		x += 66;
	}

	// Main game loop
	while (isRunning)
	{
		// INPUT - EVENTS
		while(SDL_PollEvent(&event))
		{
			// Id the window was closed
			if(event.type == SDL_QUIT)
			{
				isRunning = false;
			}

			// If a button was released and the button is escape
			if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
			{
				isRunning = false;
			}

			if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_r)
			{
				glClearColor(1, 0, 0, 1);
			}

			if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					left = true;
				}
				else if(event.key.keysym.sym == SDLK_RIGHT)
				{
					right = true;
				}
			}
			else if(event.type == SDL_KEYUP)
			{
				if(event.key.keysym.sym == SDLK_LEFT)
				{
					left = false;
				}
				else if(event.key.keysym.sym == SDLK_RIGHT)
				{
					right = false;
				}
			}
			// logic the shouold be for a certain event
		}

		// LOGIC

		if(left == true)
		{
			myX -= 5.0;
		}

		if(right == true)
		{
			myX += 5.0;
		}

		if(myX < 0)
		{
			myX = 0;
		}

		if(myX+width > 600)
		{
			myX = 600 - width;
		}

		// The Ball logic
		ballX += vellX;	// Move the ball on the X axis

		for(int n = 0; n < BRICKS; n++)
		{
			if(bricks[n].alive == true)
			{
				if(checkCollision(ballX, ballY, ballWH, ballWH, bricks[n].x, bricks[n].y, bricks[n].width, bricks[n].height) == true)
				{
					vellX = -vellX;
					bricks[n].alive = false;
					break;
				}
			}
		}

		ballY += vellY;	// Move the ball on the X axis

		for(int n = 0; n < BRICKS; n++)
		{
			if(bricks[n].alive == true)
			{
				if(checkCollision(ballX, ballY, ballWH, ballWH, bricks[n].x, bricks[n].y, bricks[n].width, bricks[n].height) == true)
				{
					vellY = -vellY;
					bricks[n].alive = false;
					break;
				}
			}
		}

		if(ballX < 0)
		{
			vellX = -vellX;
		}
		else if(ballX+ballWH > 600)
		{
			vellX = -vellX;
		}
		else if(ballY < 0)
		{
			vellY = -vellY;
		}
		else if(ballY+ballWH > 400)	// Bootom of screen
		{
			myX = 300;
			myY = 370;
			width = 80;
			height = 20;

			bool left = false, right = false;	// we save in whitch state the button is

			// The ball variables
			ballX = 50;
			ballY = 350;
			ballWH = 30;

			vellX = 3.0;
			vellY = -3.0;

			for(int n = 0;  n < BRICKS; n++)
			{
				bricks[n].alive = true;
			}	
		}

		if(checkCollision(ballX, ballY, ballWH, ballWH, myX, myY, width, height) == true)
		{
			vellY = -vellY;
		}

		//  RENDERING to the screen
		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();	// Start phase

		glOrtho(0, 600, 400, 0, -1, 1);	// Set the matrix

		glColor4ub(0, 0, 0, 255); // Black color

		glBegin(GL_QUADS);

		glVertex2f(myX, myY);
		glVertex2f(myX+width, myY);
		glVertex2f(myX+width, myY+height);
		glVertex2f(myX, myY+height);

		glEnd();

		glColor4ub(255, 0, 0, 255);	// Red color

		glBegin(GL_QUADS);

		glVertex2f(ballX, ballY);
		glVertex2f(ballX, ballY+ballWH);
		glVertex2f(ballX+ballWH, ballY+ballWH);
		glVertex2f(ballX+ballWH, ballY);

		glEnd();

		glColor4ub(0, 0, 255, 255);	// Blue color

		glBegin(GL_QUADS);

		for(int n = 0; n < BRICKS; n++)
		{
			if(bricks[n].alive == true)
			{
				if(n % 2 == 0) glColor4ub(122, 0, 255, 255);
				else glColor4ub(0, 0, 255, 255);

				glVertex2f(bricks[n].x, bricks[n].y);
				glVertex2f(bricks[n].x+bricks[n].width, bricks[n].y);
				glVertex2f(bricks[n].x+bricks[n].width, bricks[n].y+bricks[n].height);
				glVertex2f(bricks[n].x, bricks[n].y+bricks[n].height);
			}
		}

		glEnd();

		/*
		glColor4ub(255, 0, 0, 255);	// Red color

		glBegin(GL_QUADS); // GL_POINT, GL_LINES, GL_LINE_LOOP, GL_QUADS, GL_TRIANGLE GL_POLiGON

		glVertex2f(5, 5); // top left cornner
		glVertex2f(595, 5); // bottom right cornner

		glColor4ub(0, 255, 0, 255);

		glVertex2f(595, 395);
		glVertex2f(5, 395);

		glEnd(); // end drawing

		glColor4ub(0, 0, 0, 255);

		glBegin(GL_LINES);

		glVertex2f(5, 5); // draw a line
		glVertex2f(595, 395);

		glVertex2f(595, 5);
		glVertex2f(5, 395);

		glEnd(); // end drawing
		*/

		glPopMatrix();	// Stop

		SDL_GL_SwapBuffers();

		SDL_Delay(1);
	}

	SDL_Quit();

	return 0;
}
