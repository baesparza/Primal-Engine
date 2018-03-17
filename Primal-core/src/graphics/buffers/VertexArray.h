#pragma once

#include <vector>
#include <GL\glew.h>
#include "Buffer.h"

namespace primal
{
	namespace graphics
	{

		class VertexArray
		{
		private :
			GLuint m_ArrayID;
			std::vector<Buffer*> m_Buffer;
		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer* buffer, GLuint index);
			void bind();
			void unbind();
		};

	}
}