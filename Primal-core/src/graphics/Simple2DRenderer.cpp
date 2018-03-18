#include "Simple2DRenderer.h"

namespace primal
{
	namespace graphics
	{
		void Simple2DRenderer::submit(const Renderable2D * renderable)
		{
			m_RenderQueue.push_back(renderable);
		}

		void Simple2DRenderer::flush()
		{
			while (!m_RenderQueue.empty())
			{
				const Renderable2D* renderable = m_RenderQueue.front();
				renderable->getVertexArray()->bind();
				renderable->getIndexBuffer()->bind();
						  
				renderable->getShader().setUniformMat4("ml_matrix", maths::mat4::translation(renderable->getPosition()));
				glDrawElements(GL_TRIANGLES, renderable->getIndexBuffer()->getCount(), GL_UNSIGNED_SHORT, 0);
						  
				renderable->getIndexBuffer()->unbind();
				renderable->getVertexArray()->unbind();

				m_RenderQueue.pop_front();
			}
		}

	}
}
