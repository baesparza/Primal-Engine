#pragma once

#include <iostream>
#include <GL\glew.h>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogError(#x, __FILE__, __LINE__))


inline void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

inline bool GLLogError(const char* funtion, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[Open GL Error] - '" << funtion << "': '" << file << "': " << line << ". " << error << '\n';
		return false;
	}
	return true;
}