#include "Sprite.h"

namespace primal
{
	namespace graphics
	{
		Sprite::Sprite(float x, float y, float widht, float heidth, const maths::vec4 color) :
			Renderable2D(maths::vec3(x, y, 0), maths::vec2(widht, heidth), color)
		{

		}
		Sprite::Sprite(float x, float y, float widht, float heidth, Texture* texture) :
			Renderable2D(maths::vec3(x, y, 0), maths::vec2(widht, heidth), maths::vec4(1, 0, 1, 1))
		{
			m_Texture = texture;
		}
	}
}