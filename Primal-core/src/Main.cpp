#include "graphics\Window.h"

int main()
{
	using namespace primal::graphics;

	Window window("Primal Engine", 960, 540);
	glClearColor(0.2f, 0.5f, 0.7f, 1.f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	 
	while (!window.closed())
	{
		//	std::cout << window.getWidth() << ", " << window.getHeigth() << '\n';
		window.clear();

		//	glBegin(GL_QUADS);
		//	glVertex2f(-0.5f, -0.5f);
		//	glVertex2f( 0.5f, -0.5f);
		//	glVertex2f( 0.5f,  0.5f);
		//	glVertex2f(-0.5f,  0.5f);
		//	glEnd();

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

		window.update();
	}
	//	system("PAUSE");
	return 0;
}