#include "StaticSprite.h"

namespace primal
{
	namespace graphics
	{

		StaticSprite::StaticSprite(float x, float y, float widht, float heidth, maths::vec4 color, Shader& shader) :
			Renderable2D(maths::vec3(x, y, 0), maths::vec2(widht, heidth), color), m_Shader(shader)
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

		StaticSprite::~StaticSprite()
		{
			delete m_VertexArray;
			delete m_IndexBuffer;
		}

	}
}