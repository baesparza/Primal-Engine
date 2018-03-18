/*
if (e.key.code == sf::Mouse::Left)
for (int z = 0; z < 10; z++)
{
sf::Vector2i pos = sf::Mouse::getPosition(app);
int x = (pos.x - z * offX) / stepX;
int y = (pos.y + z * offY) / stepY;

for (int i = 0; i < 2; i++)
for (int j = 0; j < 2; j++)
if (f(x - i, y - j, z) > 0 && isOpen(x - i, y - j, z))
v1 = sf::Vector3i(x - i, y - j, z);

if (v1 == v2)
continue;

int a = f(v1), b = f(v2);
if (a == b || (a > 34 && a < 39 && b > 34 && b < 39) || a >= 39 && b <= 39)
{
f(v1) *= -1;
f(v2) *= -1;
}
v2 = v1;

}

*/



#pragma once

#include "../graphics/Window.h"
#include "../maths/vec2.h"

namespace primal
{
	namespace mouse
	{
		maths::vec2 getPosition(const graphics::Window& win);

		//	bool isButtonPressed(GLFWwindow* window, int button, int action, int mods)
		//	{
		//		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		//		if (button >= MAX_BUTTONS)
		//			return false;
		//		return m_MouseButtons[button];
		//		graphics::Window* win = (graphics::Window*) glfwGetWindowUserPointer(window);
		//		win->m_MouseButtons[button] = action != GLFW_RELEASE;
		//	}
	}
}
