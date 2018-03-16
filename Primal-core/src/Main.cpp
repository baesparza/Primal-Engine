#include "graphics\Window.h"

int main()
{
	using namespace primal::graphics;

	Window window("Primal Engine", 960, 540);
	glClearColor(0.2f, 0.5f, 0.7f, 1.f);

	//	GLuint vao;
	//	glGenVertexArrays(1, &vao);
	//	glBindVertexArray(vao);


	while (!window.closed())
	{
		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << '\n';
		window.clear();

		glBegin(GL_POLYGON);

		glColor3f(1.0, 0.0, 0.0);     glVertex3f(0.5, -0.5, -0.5);      // P1 is red
		glColor3f(0.0, 1.0, 0.0);     glVertex3f(0.5, 0.5, -0.5);      // P2 is green
		glColor3f(0.0, 0.0, 1.0);     glVertex3f(-0.5, 0.5, -0.5);      // P3 is blue
		glColor3f(1.0, 0.0, 1.0);     glVertex3f(-0.5, -0.5, -0.5);      // P4 is purple

		glEnd();

		//	glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

		window.update();
	}
	//	system("PAUSE");
	return 0;
}