#include "Sprite.h"

namespace primal
{
	namespace graphics
	{
		Sprite::Sprite(float x, float y, float widht, float heidth, maths::vec4 color) :
			Renderable2D(maths::vec3(x, y, 0), maths::vec2(widht, heidth), color)
		{

		}
	}
}