#include "src\graphics\Window.h"
#include "src\graphics\Shader.h"
#include "src\maths\maths.h"
#include "src\utils\fileutils.h"

int main()
{
	// TODO: separate input class
	// TODO: gl handle errors
	// TODO: fix mat4::rotation
	// TODO: rename vect classes to vec
	using namespace primal;
	using namespace graphics;
	using namespace maths;

	Window window("Primal Engine", 960, 540);

	GLfloat vertices[] =
	{
		4,3,0,
		12,3,0,
		4,6,0,

		12, 6, 0,
		4,6,0,
		12,3,0,
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::ortographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("./res/shader/basic.ver", "./res/shader/basic.frag");
	shader.enable();

	shader.setUniformMat4("pr_matrix", ortho);
	//	shader.setUniformMat4("ml_matrix", mat4::rotation(5, vect3(0, 0, 1)));
	shader.setUniformMat4("ml_matrix", mat4::translation(vect3(2, 2, 0)));

	shader.setUniform2f("light_pos", vect2(8.0f, 4.5f));
	shader.setUniform4f("colour", vect4(0.6f, 0.5f, 0.7f, 1.0f));

	while (!window.closed())
	{
		window.clear();

		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.update();
	}
	return 0;
}