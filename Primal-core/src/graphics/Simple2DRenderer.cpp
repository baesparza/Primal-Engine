#include "Simple2DRenderer.h"

namespace primal
{
	namespace graphics
	{
		void Simple2DRenderer::submit(const Renderable2D * sprite)
		{
			m_RenderQueue.push_back((StaticSprite *) sprite);
		}

		void Simple2DRenderer::flush()
		{
			while (!m_RenderQueue.empty())
			{
				const StaticSprite* sprite = m_RenderQueue.front();
				sprite->getVertexArray()->bind();
				sprite->getIndexBuffer()->bind();
					
				sprite->getShader().setUniformMat4("ml_matrix", maths::mat4::translation(sprite->getPosition()));
				glDrawElements(GL_TRIANGLES, sprite->getIndexBuffer()->getCount(), GL_UNSIGNED_SHORT, 0);
						  
				sprite->getIndexBuffer()->unbind();
				sprite->getVertexArray()->unbind();

				m_RenderQueue.pop_front();
			}
		}

	}
}
