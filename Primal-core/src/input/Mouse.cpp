#include "Mouse.h"

namespace primal
{
	namespace mouse
	{
		maths::vec2 mouse::getPosition(const graphics::Window & win)
		{
			glfwSetCursorPosCallback(win.m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				graphics::Window* win = (graphics::Window*) glfwGetWindowUserPointer(window);
				win->m_position.x = ( float ) xpos;
				win->m_position.y = ( float ) ypos;
			});
			return win.m_position;
		}

	}
}