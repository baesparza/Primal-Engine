#include "Group.h"
namespace primal
{
	namespace graphics
	{
		Group::Group(const maths::mat4& transform)
			: m_TransformationMatrix(transform)
		{

		}

		void Group::submit(Renderer2D * renderer) const
		{
			renderer->push(m_TransformationMatrix);

			for (const Renderable2D* renderable : m_Renderables)
				renderable->submit(renderer);

			renderer->pop();
		}

		void Group::add(Renderable2D * renderable)
		{
			m_Renderables.push_back(renderable);
		}

		Group::~Group()
		{
			for (int i = 0; i < m_Renderables.size(); i++)
				delete m_Renderables[i];
		}
	}

}
