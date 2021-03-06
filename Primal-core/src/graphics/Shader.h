#pragma once

#include <GL/glew.h>
#include <vector>
#include <iostream>
#include "../utils/fileutils.h"
#include "../maths/maths.h"

namespace primal
{
	namespace graphics
	{
		class Shader
		{
		private:
			GLuint m_ShaderID;
			const char *m_VertPath, *m_FragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void setUniform1f(const GLchar* name, float value);
			void setUniform1fv(const GLchar* name, float* value, GLint count);
			void setUniform1i(const GLchar* name, int value);
			void setUniform1iv(const GLchar* name, int* value, GLint count);
			void setUniform2f(const GLchar* name, const maths::vec2& vector);
			void setUniform3f(const GLchar* name, const maths::vec3& vector);
			void setUniform4f(const GLchar* name, const maths::vec4& vector);
			void setUniformMat4(const GLchar* name, const maths::mat4& matrix);

			void enable() const;
			void disable() const;
		private:
			GLuint load();
			GLuint compileShader(unsigned int type, std::string& source);
			GLint getUniformLocation(const GLchar* name);
		};

	}
}