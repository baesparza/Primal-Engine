#pragma once

#include "buffers\Buffer.h"
#include "buffers\IndexBuffer.h"
#include "buffers\VertexArray.h"

#include "Shader.h"

#include "../maths/maths.h"

namespace primal
{
	namespace graphics
	{
		// vertex data
		struct VertexData
		{
			maths::vec3 vertex;
			maths::vec4 color;
		};

		class Renderable2D
		{
		protected:
			maths::vec3 m_Position;
			maths::vec2 m_Size;
			maths::vec4 m_Color;

		public:
			Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color) :
				m_Position(position), m_Size(size), m_Color(color)
			{ }

			virtual ~Renderable2D()
			{ }

			inline const maths::vec3& getPosition() const { return m_Position; };
			inline const maths::vec2& getSize() const { return m_Size; };
			inline const maths::vec4& getColor() const { return m_Color; };
		};
	}
}