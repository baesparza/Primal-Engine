#include "Shader.h"


namespace primal
{
	namespace graphics
	{

		Shader::Shader(const char * vertPath, const char * fragPath) :
			m_VertPath(vertPath), m_FragPath(fragPath)
		{
			m_ShaderID = load();
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_ShaderID);
		}

		void Shader::setUniform1f(const GLchar * name, float value)
		{
			glUniform1f(getUniformLocation(name), value);
		}

		void Shader::setUniform1i(const GLchar * name, int value)
		{
			glUniform1i(getUniformLocation(name), value);
		}

		void Shader::setUniform2f(const GLchar * name, const maths::vect2 & vector)
		{
			glUniform2f(getUniformLocation(name), vector.x, vector.y);
		}

		void Shader::setUniform3f(const GLchar * name, const maths::vect3 & vector)
		{
			glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
		}

		void Shader::setUniform4f(const GLchar * name, const maths::vect4 & vector)
		{
			glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
		}

		void Shader::setUniformMat4(const GLchar * name, const maths::mat4 & matrix)
		{
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
		}

		void Shader::enable() const
		{
			glUseProgram(m_ShaderID);
		}

		void Shader::disable() const
		{
			glUseProgram(0);
		}

		GLuint Shader::load()
		{
			GLuint program = glCreateProgram();

			// read source
			std::string vertexSource = read_file(m_VertPath);
			std::string fragmentSource = read_file(m_FragPath);

			// compile shaders
			GLuint vertex = compileShader(GL_VERTEX_SHADER, vertexSource);
			GLuint fragment = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

			// attach to program
			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			// validate
			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		GLuint Shader::compileShader(unsigned int type, std::string & source)
		{
			GLuint id = glCreateShader(type);
			const char* src = source.c_str();

			// load shader source
			glShaderSource(id, 1, &src, nullptr);
			glCompileShader(id);

			// get result
			GLint result;
			glGetShaderiv(id, GL_COMPILE_STATUS, &result);

			// handle error
			if (result == GL_FALSE)
			{
				int length;
				glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(id, length, &length, &error[0]);
				std::cout << "Failed to compile " << ((type == GL_VERTEX_SHADER) ? "vetex" : "fragment") << " shader: " << '\n';
				std::cout << &error[0] << '\n';
				glDeleteShader(type);
				return 0;
			}

			// succeed
			return id;
		}

		GLint Shader::getUniformLocation(const GLchar * name)
		{
			return glGetUniformLocation(m_ShaderID, name);
		}

	}
}
