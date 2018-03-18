#include "Window.h"

namespace primal
{
	namespace graphics
	{

		Window::Window(const char * title, int width, int heigth) :
			m_Title(title), m_Width(width), m_Heigth(heigth)
		{
			if (!init())
				glfwTerminate();

			for (int i = 0; i < GLFW_KEY_LAST; i++)
				m_Keys[i] = false;

			for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++)
				m_MouseButtons[i] = false;
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
			glfwSetWindowUserPointer(m_Window, this);

			glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *wind, int w, int h) { glViewport(0, 0, w, h); });
			
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Fail to create glew lib" << '\n';
				return false;
			}

			std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << '\n';
			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
				std::cout << "[ERROR OPENGL]: " << error << '\n';

			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Heigth);
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

	}
}