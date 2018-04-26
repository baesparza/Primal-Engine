#include "Sprite.h"

namespace primal
{
	namespace graphics
	{
		Sprite::Sprite(float x, float y, float widht, float heidth, unsigned int color) :
			Renderable2D(maths::vec3(x, y, 0), maths::vec2(widht, heidth), color)
		{

		}
		Sprite::Sprite(float x, float y, float widht, float heidth, Texture* texture) :
			Renderable2D(maths::vec3(x, y, 0), maths::vec2(widht, heidth), 0xffffffff)
		{
			m_Texture = texture;
		}
	}
}