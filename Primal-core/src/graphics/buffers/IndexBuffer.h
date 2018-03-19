#pragma once

#include <GL/glew.h>

namespace primal
{
	namespace graphics
	{
		class IndexBuffer
		{
		private:
			GLuint m_BufferID;
			GLuint m_Count; // num indices
		public:
			IndexBuffer(GLushort * data, GLsizei count);
			IndexBuffer(GLuint * data, GLsizei count);
			~IndexBuffer();
			void bind() const;
			void unbind() const;

			inline GLuint getCount() const { return m_Count; };
		};

	}
}