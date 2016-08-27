#include "Window.h"

int main(int argc, char** argv)
{

	Window window("Learning", 600, 800);
	Shader shader("E:\\VisualStudio2015\\C# projects\\OpenglLearning\\Shaders\\BasicShader");
	while (!window.isClosed())
	{
		window.Clear(0.5f, 0.115f, 0.34f);
		shader.Bind();
		window.Draw();
		window.Update();
	}

	system("PAUSE");
	return 0;
}