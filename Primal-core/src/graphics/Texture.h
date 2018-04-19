#pragma once

#include <GL\glew.h>
#include <string>
#include "../utils/ImageLoad.h"

namespace primal
{
	namespace graphics
	{

		class Texture
		{
		private:
			std::string m_Filename;
			GLuint m_TID;
			GLsizei m_Width, m_Height;
		public:
			Texture(const std::string& filename);
			~Texture();
			void bind() const;
			void unbind() const;

			inline const unsigned int getWidth() const { return m_Width; }
			inline const unsigned int getHeight() const { return m_Height; }
		private:
			GLuint load();
		};

	}
}