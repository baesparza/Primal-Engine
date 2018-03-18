#pragma once

#include "../graphics/Window.h"

namespace primal
{
	struct Keyboard
	{
		static bool isKeyPressed(const graphics::Window & win, unsigned int keycode);
	};
}