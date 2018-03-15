#pragma once

#include<GLFW\glfw3.h>
#include <iostream>

namespace primal {
	namespace graphics {

		class Window
		{
		private:
			const char *m_Title;
			int m_Width, m_Heigth;
			GLFWwindow *m_Window;
		public:
			Window(const char *title, int width, int heigth);
			~Window();
			bool closed() const;
			void update() const;
		private:
			bool init();
		};

	}
}