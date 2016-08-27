#pragma once
#include <SDL.h>
#include <glm.hpp>
#include <GL\glew.h>
#include <string>
#include <iostream>
#include "Input.h"
#include <fstream>
#include "Shader.h"

class Window
{
public:
	Window(std::string TITLE, int HEIGHT, int WIDTH);
	~Window();
	bool isClosed();
	void Draw();
	void Update();
	void Clear(float r, float g, float b);
	bool p_isClosed;
private:
	SDL_Window* p_window;
	SDL_GLContext p_context;
};
