#include "graphics\Window.h"
#include "maths\maths.h"

int main()
{
	using namespace primal;
	using namespace graphics;
	using namespace maths;

	Window window("Primal Engine", 960, 540);

	while (!window.closed())
	{
		window.clear();

		glBegin(GL_POLYGON);

		glColor3f(1.0, 0.0, 0.0);     glVertex3f( 0.5, -0.5, -0.5);      // P1 is red
		glColor3f(0.0, 1.0, 0.0);     glVertex3f( 0.5,  0.5, -0.5);      // P2 is green
		glColor3f(0.0, 0.0, 1.0);     glVertex3f(-0.5,  0.5, -0.5);      // P3 is blue
		glColor3f(1.0, 0.0, 1.0);     glVertex3f(-0.5, -0.5, -0.5);      // P4 is purple

		glEnd();

		window.update();
	}
	//	system("PAUSE");
	return 0;
}