#include "Label.h"

namespace primal {
	namespace graphics {

		Label::Label(std::string text, float x, float y, unsigned int color)
			:Renderable2D() ,text(text)
		{
			m_Position = maths::vec3(x, y, 0.f);
			m_Color = color;
		}

		void Label::submit(Renderer2D * renderer) const
		{
			renderer->drawString(text, m_Position, m_Color);
		}

	}
}