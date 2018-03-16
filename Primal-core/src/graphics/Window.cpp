#include "Window.h"

namespace primal {
	namespace graphics {

		Window::Window(const char * title, int width, int heigth) :
			m_Title(title), m_Width(width), m_Heigth(heigth)
		{
			if (!init())
				glfwTerminate();

			for (int i = 0; i < MAX_KEYS; i++)
				m_Keys[i] = false;

			for (int i = 0; i < MAX_BUTTONS; i++)
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
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Fail to create glew lib" << '\n';
				return false;
			}

			std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << '\n';
			return true;
		}

		bool Window::isKeyPressed(unsigned int keycode) const
		{
			// TODO: log this
			if (keycode >= MAX_KEYS)
				return false;
			return m_Keys[keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int button) const
		{
			// TODO: log this
			if (button >= MAX_BUTTONS)
				return false;
			return m_MouseButtons[button];
		}

		void Window::getMousePosition(double &x, double &y) const
		{
			x = mx;
			y = my;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			/// enable changes on window class variables
			//	glfwGetFramebufferSize(m_Window, &m_Width, &m_Heigth);
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
		{
			Window* win = ( Window* ) glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = ( Window* ) glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = ( Window* ) glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}
	}
}