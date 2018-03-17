#include "src\graphics\Window.h"
#include "src\maths\maths.h"
#include "src\utils\fileutils.h"

int main()
{
	using namespace primal;
	using namespace graphics;
	using namespace maths;

	std::string file = read_file("main.cpp");
	std::cout << file << '\n';

	Window window("Primal Engine", 960, 540);

	mat4 position = mat4::translation(vect3(2, 3, 4));

	position *= mat4::identity();

	std::cout << position.columns[3] << '\n';

	while (!window.closed())
	{
		window.clear();

		glBegin(GL_POLYGON);

		glColor3f(1.0, 0.0, 0.0);     glVertex3f( 0.5, -0.5, -0.5);      // P1 is red
		glColor3f(0.0, 1.0, 0.0);     glVertex3f( 0.5,  0.5, -0.5);      // P2 is green
		glColor3f(0.0, 0.0, 1.0);     glVertex3f(-0.5,  0.5, -0.5);      // P3 is blue
		
		glEnd();

		window.update();
	}
	return 0;
}