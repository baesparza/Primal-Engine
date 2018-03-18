#include "Mouse.h"

namespace primal
{
	maths::vec2 Mouse::getPosition(const graphics::Window & win)
	{
		glfwSetCursorPosCallback(win.getWindow(), [](GLFWwindow* window, double xpos, double ypos)
		{
			graphics::Window* win = (graphics::Window*) glfwGetWindowUserPointer(window);
			win->m_position.x = ( float ) xpos;
			win->m_position.y = ( float ) ypos;
		});
		return win.m_position;
	}

	bool Mouse::isButtonPressed(const graphics::Window & win, unsigned int button)
	{
		glfwSetMouseButtonCallback(win.getWindow(), [](GLFWwindow* window, int button, int action, int mods)
		{
			graphics::Window* win = (graphics::Window*) glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		});
		if (button >= GLFW_MOUSE_BUTTON_LAST)
			return false;
		return win.m_MouseButtons[button];
	}

}