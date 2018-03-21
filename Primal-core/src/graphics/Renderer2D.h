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
			virtual void begin() { };
			virtual void submit(const Renderable2D * renderable) = 0;
			virtual void end() { };
			virtual void flush() = 0;
		};

	}
}