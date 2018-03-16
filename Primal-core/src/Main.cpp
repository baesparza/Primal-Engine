#include "graphics\Window.h"
#include "maths\vect2.h"
#include "maths\vect3.h"
#include "maths\vect4.h"

int main()
{
	using namespace primal;
	using namespace graphics;
	using namespace maths;

	Window window("Primal Engine", 960, 540);

	vect4 a(1.0f, 2.0f, 3.0f, 4.0f);
	vect4 b(3.0f, 4.0f, 3.0f, 4.0f);

	vect4 c = a + b;

	while (!window.closed())
	{
		std::cout << a << '\n';
		std::cout << b << '\n';
		std::cout << c << '\n';

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