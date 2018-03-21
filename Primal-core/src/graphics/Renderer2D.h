#pragma once

#include "Renderable2D.h"

namespace primal
{
	namespace graphics
	{
		// Superclass with basic methods for renderers
		class Renderer2D
		{
		protected:
			std::vector<maths::mat4> m_TransformationStrack;
			maths::mat4 *m_TransformationBack;
		protected:
			Renderer2D()
			{
				m_TransformationStrack.push_back(maths::mat4::identity());
				m_TransformationBack = &m_TransformationStrack.back();
			}

		public:
			void push(const maths::mat4 & matrix, bool override = false)
			{
				if (override)
					m_TransformationStrack.push_back(matrix);
				else
					m_TransformationStrack.push_back(m_TransformationStrack.back() * matrix);
				m_TransformationBack = &m_TransformationStrack.back();
			}

			void pop()
			{
				if (m_TransformationStrack.size() > 1)
					m_TransformationStrack.pop_back();
				m_TransformationBack = &m_TransformationStrack.back();
			}

			virtual void begin() { };
			virtual void submit(const Renderable2D * renderable) = 0;
			virtual void end() { };
			virtual void flush() = 0;
		};

	}
}