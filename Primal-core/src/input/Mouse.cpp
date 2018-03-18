#include "Mouse.h"

namespace primal
{
	namespace mouse
	{
		maths::vec2 getPosition(const graphics::Window & win)
		{
			glfwSetCursorPosCallback(win.m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				graphics::Window* win = (graphics::Window*) glfwGetWindowUserPointer(window);
				win->m_position.x = ( float ) xpos;
				win->m_position.y = ( float ) ypos;
			});
			return win.m_position;
		}

		bool isButtonPressed(const graphics::Window & win, unsigned int button)
		{
			glfwSetMouseButtonCallback(win.m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				graphics::Window* win = (graphics::Window*) glfwGetWindowUserPointer(window);
				win->m_MouseButtons[button] = action != GLFW_RELEASE;
			});
			if (button >= GLFW_MOUSE_BUTTON_LAST)
				return false;
			return win.m_MouseButtons[button];
		}

	}
}