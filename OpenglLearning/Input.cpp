#include "Input.h"
#include "Window.h"


Input::Input()
{

}


Input::~Input()
{
}

void Input::mainInput(bool isClosed)
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			isClosed = true;
			break;
		case SDL_KEYDOWN:
		case SDLK_ESCAPE:
		{
			exit(-1);
			break;
		}
		break;
		}
	}
}
