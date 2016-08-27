#pragma once
#include "Window.h"
class Shader
{
public:
	Shader(const std::string& fileName);
	~Shader();
	void Bind();
private:
	GLuint p_program;
	static  const unsigned int NUM_SHADERS = 2;
	GLuint p_shader[NUM_SHADERS];
};

