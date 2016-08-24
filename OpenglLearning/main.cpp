#include <SDL.h>
#include <glm.hpp>
#include <GL\glew.h>

using namespace std;

int main(int argc, char** argv)
{

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window;
	window = SDL_CreateWindow("Meow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);


	system("PAUSE");
	return 0;
}