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

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Shader shader("./res/shader/basic.ver", "./res/shader/basic.frag");
	shader.enable();

	while (!window.closed())
	{
		window.clear();

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

		window.update();
	}
	return 0;
}