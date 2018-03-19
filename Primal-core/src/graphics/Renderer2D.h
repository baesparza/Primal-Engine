#pragma once

#include "Renderable2D.h"

namespace primal
{
	namespace graphics
	{
		// Superclass with basic methods for renderers
		class Renderer2D
		{
		public:
			// TODO: if This is only used for the StaticSprite
			// change Renderable2D  with StaticSprite
			virtual void submit(const Renderable2D * renderable) = 0;
			virtual void flush() = 0;
		};

	}
}