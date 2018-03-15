#include "graphics\Window.h"

int main()
{
	using namespace primal::graphics;
	Window window("Primal Engine", 800, 800);

	while (!window.closed())
	{
		window.update();

	}
	//	system("PAUSE");
	return 0;
}