#pragma once

#include "../graphics/Window.h"
#include "../maths/vec2.h"

namespace primal
{
	namespace mouse
	{
		// TODO: create class for mouse and 
		maths::vec2 getPosition(const graphics::Window& win);

		bool isButtonPressed(const graphics::Window& win, unsigned int button);
	}
}
