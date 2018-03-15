#include "Window.h"

namespace primal {
	namespace graphics {

		Window::Window(const char * title, int width, int heigth) :
			m_Title(title), m_Width(width), m_Heigth(heigth)
		{
			if (!init())
				glfwTerminate();
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Fail to load glfw" << '\n';
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Heigth, m_Title, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Fail to create glfw window" << '\n';
				glfwTerminate();
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			//	glfwSwapInterval(1);
			return true;
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}
		
		void Window::update() const
		{
			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}

	}
}