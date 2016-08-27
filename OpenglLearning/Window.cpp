#include "Window.h"

Input input;

Window::Window(std::string TITLE, int HEIGHT, int WIDTH)
{
	int _sdl = SDL_Init(SDL_INIT_EVERYTHING);
	if (_sdl != 0)
		std::cout << "Sdl couldn't initlize" << std::endl;

	p_window = SDL_CreateWindow(TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	if (!p_window)
		std::cout << "window creation failed" << std::endl;

	p_context = SDL_GL_CreateContext(p_window);

	glewExperimental = GL_TRUE;
	glewInit();


	p_isClosed = false;


}


Window::~Window()
{
	SDL_GL_DeleteContext(p_context);
	SDL_DestroyWindow(p_window);

	SDL_Quit();
}

bool Window::isClosed()
{
	return p_isClosed;
}

void Window::Draw()
{
	glPushMatrix();
	{
		glBegin(GL_QUADS);
		{
			glColor3f(0.1f, 0.65f, 0.23f);
			glVertex2f(-1.0f, -1.0f);
			glVertex2f(-1.0f, 0.0f);
			glVertex2f(0.0f, 0.0f);
			glVertex2f(0.0f, -1.0f);
		}
		glEnd();
	}
	glPopMatrix();
}

void Window::Update()
{
	SDL_GL_SwapWindow(p_window);

	input.mainInput(p_isClosed);
}

void Window::Clear(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

