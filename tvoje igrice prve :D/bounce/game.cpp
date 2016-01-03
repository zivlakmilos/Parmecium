#include "classes.h"

int main(int argc, char* argv[])
{
	Main mainloop;

	mainloop.init();
	mainloop.mainloop();

	SDL_Quit();
	return 0;
}
