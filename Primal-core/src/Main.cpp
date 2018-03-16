#include "graphics\Window.h"
#include "maths\vect3.h"

int main()
{
	using namespace primal;
	using namespace graphics;
	using namespace maths;

	Window window("Primal Engine", 960, 540);

	vect3 a(1.0f, 2.0f, 3.0f);
	vect3 b(3.0f, 4.0f, 5.0f);

	while (!window.closed())
	{
		a.add(b).add(a);
		std::cout << a << '\n';

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