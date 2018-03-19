#pragma once

#include <deque>
#include "Renderer2D.h"
#include "StaticSprite.h"

namespace primal
{
	namespace graphics
	{

		class Simple2DRenderer: public Renderer2D
		{
		private:
			std::deque<const StaticSprite*> m_RenderQueue;
		public:
			void submit(const Renderable2D * sprite) override;
			void flush() override;
		};

	}
}