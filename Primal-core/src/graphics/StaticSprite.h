#pragma once

#include "Renderable2D.h"

namespace primal
{
	namespace graphics
	{

		class StaticSprite : public Renderable2D
		{
		private:
			Shader & m_Shader;
			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;
		public:
			StaticSprite(float x, float y, float widht, float heidth, maths::vec4 color, Shader& shader);
			~StaticSprite();

			inline const VertexArray* getVertexArray() const { return m_VertexArray; };
			inline const IndexBuffer* getIndexBuffer() const { return m_IndexBuffer; };
			inline Shader& getShader() const { return m_Shader; };
		};

	}
}