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
		class Renderable2D
		{
		protected:
			maths::vec3 m_Position;
			maths::vec2 m_Size;
			maths::vec4 m_Color;

			Shader& m_Shader;
			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;
		public:
			Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color, Shader & shader) :
				m_Position(position), m_Size(size), m_Color(color), m_Shader(shader)
			{
				m_VertexArray = new VertexArray();

				GLfloat vertices[] = 
				{
					0.f, 0.f, 0.f,
					0.f, m_Size.y, 0.f,
					m_Size.x, m_Size.y, 0.f,
					m_Size.x, 0.f, 0.f
				};

				GLfloat colors[] = 
				{
					m_Color.x, m_Color.y, m_Color.z, m_Color.w,
					m_Color.x, m_Color.y, m_Color.z, m_Color.w,
					m_Color.x, m_Color.y, m_Color.z, m_Color.w,
					m_Color.x, m_Color.y, m_Color.z, m_Color.w
				};

				m_VertexArray->addBuffer(new Buffer(vertices, 3 * 4, 3), 0);
				m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

				GLushort indices[] = {0, 1, 2, 0, 2, 3};
				m_IndexBuffer = new IndexBuffer(indices, 6);
			}

			virtual ~Renderable2D()
			{
				delete m_VertexArray;
				delete m_IndexBuffer;
			}

			inline const VertexArray* getVertexArray() const { return m_VertexArray; };
			inline const IndexBuffer* getIndexBuffer() const { return m_IndexBuffer; };
			inline Shader& getShader() const { return m_Shader; };

			inline const maths::vec3& getPosition() const { return m_Position; };
			inline const maths::vec2& getSize() const { return m_Size; };
			inline const maths::vec4& getColor() const { return m_Color; };
		};
	}
}