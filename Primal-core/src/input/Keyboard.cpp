#include "Keyboard.h"

namespace primal
{

	bool Keyboard::isKeyPressed(const graphics::Window & win, unsigned int keycode)
	{
		glfwSetKeyCallback(win.m_Window, [](GLFWwindow * window, int key, int scancode, int action, int mods)
		{
			graphics::Window* win = (graphics::Window*) glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action != GLFW_RELEASE;
		});
		if (keycode >= GLFW_KEY_LAST)
			return false;
		return win.m_Keys[keycode];
	}

}