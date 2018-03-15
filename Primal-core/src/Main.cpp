#include "graphics\Window.h"

int main()
{
	using namespace primal::graphics;

	Window window("Primal Engine", 960, 540);
	glClearColor(0.2f, 0.5f, 0.7f, 1.f);

	//	std::cout << glGetString(GL_VERSION) << '\n';

	while (!window.closed())
	{
		std::cout << window.getWidth() << ", " << window.getHeigth() << '\n';
		window.clear();

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glEnd();

		window.update();
	}
	//	system("PAUSE");
	return 0;
}