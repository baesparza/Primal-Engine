#include "TileLayer.h"

namespace primal
{
	namespace graphics
	{

		TileLayer::TileLayer(Shader * shader) :
			Layer(new BatchRenderer2D(), shader, maths::mat4::ortographic(-16, 16, -9, 9, -1, 1))
		{
		}

		TileLayer::~TileLayer()
		{
		}

	}
}
