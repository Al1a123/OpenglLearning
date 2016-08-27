#include "Shader.h"

static GLuint CreateShader(const std::string& fileName, GLenum shader_type);
static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string loadShader(const std::string& fileName);

Shader::Shader(const std::string& fileName)
{
	p_program = glCreateProgram();

	p_shader[0] = CreateShader(loadShader(fileName + ".vs.text"), GL_VERTEX_SHADER);
	p_shader[1] = CreateShader(loadShader(fileName + ".fs.text"), GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < NUM_SHADERS, i++;)
		glAttachShader(p_program, p_shader[i]);

	glLinkProgram(p_program);
	CheckShaderError(p_program, GL_LINK_STATUS, true, "Program linking failed!");

	glValidateProgram(p_program);
	CheckShaderError(p_program, GL_VALIDATE_STATUS, true, "Program is not validate");

}


Shader::~Shader()
{
	glDeleteProgram(p_program);
}

static std::string loadShader(const std::string & fileName)
{
	std::ifstream file;
	file.open(fileName.c_str());
	
	std::string line;
	std::string output;

	if (file.is_open())
	{
		while (file.good())
		{
			std::getline(file, line);
			output.append(line + "\n");
		}

	}

	else
		std::cout << "Unable to load shader" << std::endl;

	return output;
}

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}

void Shader::Bind()
{
	glUseProgram(p_program);
}

static GLuint CreateShader(const std::string & text, GLenum shader_type)
{
	GLuint shader = glCreateShader(shader_type);

	if (shader == 0)
		std::cerr << "Shader was not found " << std::endl;

	const GLchar*  shaderSourceStrings[1];
	GLint shaderSourceStringsLenght[1];

	shaderSourceStrings[0] = text.c_str();
	shaderSourceStringsLenght[0] = text.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringsLenght);
	glCompileShader(shader);

	return shader;

}
