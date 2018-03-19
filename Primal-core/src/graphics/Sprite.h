#pragma once

#include "Renderable2D.h"

namespace primal
{
	namespace graphics
	{

		class Sprite : public Renderable2D
		{
		public:
			Sprite(float x, float y, float widht, float heidth, maths::vec4 color);
		};

	}
}