#include "src\graphics\Window.h"
#include "src\graphics\Shader.h"
#include "src\maths\maths.h"
#include "src\utils\fileutils.h"

int main()
{
	// TODO: separate input class
	// TODO: gl handle errors
	using namespace primal;
	using namespace graphics;
	using namespace maths;

	Window window("Primal Engine", 960, 540);

	GLfloat vertices[] =
	{
		-0.5f, -0.5f,  0.0f, // 0
		 0.5f, -0.5f,  0.0f, // 1
		 0.5f,  0.5f,  0.0f, // 2

		 0.5f,  0.5f,  0.0f, // 2
		-0.5f, -0.5f,  0.0f, // 0
		-0.5f,  0.5f,  0.0f // 3
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Shader shader("./res/shader/basic.ver", "./res/shader/basic.frag");
	shader.enable();

	while (!window.closed())
	{
		window.clear();

		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.update();
	}
	return 0;
}