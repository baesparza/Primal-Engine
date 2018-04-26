#pragma once

#include "Renderable2D.h"

namespace primal
{
	namespace graphics
	{

		class Sprite : public Renderable2D
		{
		public:
			Sprite(float x, float y, float widht, float heidth, unsigned int color);
			Sprite(float x, float y, float widht, float heidth, Texture* texture);
		};

	}
}