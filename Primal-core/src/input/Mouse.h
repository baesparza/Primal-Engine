#pragma once

#include "../graphics/Window.h"
#include "../maths/vec2.h"

namespace primal
{
	struct Mouse
	{
		static maths::vec2 getPosition(const graphics::Window& win);
		static bool isButtonPressed(const graphics::Window& win, unsigned int button);
	};
}
