#pragma once

#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "../maths/vec2.h"

namespace primal {
	namespace graphics {

		class Window
		{
		private:
			const char *m_Title;
			int m_Width, m_Heigth;
			GLFWwindow *m_Window;
		public:
			bool m_Keys[GLFW_KEY_LAST];
			bool m_MouseButtons[GLFW_MOUSE_BUTTON_LAST];
			maths::vec2 m_position;
		public:
			Window(const char *title, int width, int heigth);
			~Window();
			bool closed() const;
			void clear() const;
			void update();

			inline int getHeigth() const { return m_Heigth; }
			inline int getWidth() const { return m_Width; }
			inline GLFWwindow * getWindow() const { return m_Window; };
		private:
			bool init();
		};

	}
}