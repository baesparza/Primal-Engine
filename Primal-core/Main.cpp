#include "src\graphics\Window.h"
#include "src\graphics\Shader.h"
#include "src\maths\maths.h"
#include "src\utils\fileutils.h"

#include "src\graphics\buffers\Buffer.h"
#include "src\graphics\buffers\IndexBuffer.h"
#include "src\graphics\buffers\VertexArray.h"

int main()
{
	// TODO: separate input class
	// TODO: gl handle errors
	// TODO: rename vect classes to vec

	using namespace primal;
	using namespace graphics;
	using namespace maths;

	Window window("Primal Engine", 960, 540);

	GLfloat vertices[] =
	{
		0.f, 0.f, 0.f, // 0
		0.f, 3.f, 0.f, // 1
		8.f, 3.f, 0.f, // 2
		8.f, 0.f, 0.f  // 3
	};

	GLushort indices[] =
	{
		0, 1, 2,
		0, 2, 3
	};

	VertexArray vao;
	Buffer* vbo = new Buffer(vertices, 4 * 3, 3);
	IndexBuffer ibo(indices, 6);

	vao.addBuffer(vbo, 0);

	mat4 ortho = mat4::ortographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	/////shader/////
	Shader shader("./res/shader/basic.ver", "./res/shader/basic.frag");
	shader.enable();

	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vect3(4.f, 3.f, 0)));

	shader.setUniform4f("colour", vect4(0.7f, 0.5f, 0.9f, 1.0f));

	while (!window.closed())
	{
		window.clear();
		// mouse position
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vect2(( float ) (x * 16 / 960), ( float ) (9 - y * 9 / 540)));

		vao.bind();
		ibo.bind();
		//	shader.setUniformMat4("ml_matrix", mat4::translation(vect3(4.f, 3.f, 0)));
		//	glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		//	shader.setUniformMat4("ml_matrix", mat4::translation(vect3(0.f, 0.f, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		vao.unbind();
		ibo.unbind();

		window.update();
	}
	return 0;
}