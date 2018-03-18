#pragma once

#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "../maths/vec2.h"

namespace primal {
	namespace graphics {

		#define MAX_KEYS GLFW_KEY_LAST
		#define MAX_BUTTONS GLFW_MOUSE_BUTTON_LAST

		class Window
		{
		public:
			const char *m_Title;
			int m_Width, m_Heigth;
			GLFWwindow *m_Window;
		public:
			bool m_Keys[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			maths::vec2 m_position;
		public:
			Window(const char *title, int width, int heigth);
			~Window();
			bool closed() const;
			void clear() const;
			void update();

			inline int getHeigth() const { return m_Heigth; }
			inline int getWidth() const { return m_Width; }

			bool isKeyPressed(unsigned int keycode) const;
			bool isMouseButtonPressed(unsigned int button) const;
		private:
			bool init();
			friend static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		};
		// TODO: refactor this fuctions
		// TODO: move input to other class

		void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	}
}