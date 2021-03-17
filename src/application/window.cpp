#include "application/window.h"

namespace Application
{
	Window::Window(const char* str_name, short s_width, short s_height)
		: name(str_name),
		isClosed(false),
		windowSize(WindowSize(s_width, s_height)),
		windowPosition(WindowPosition())
	{
		init();
	};

	Window::Window(std::string& str_name, short& s_width, short& s_height, short& s_x, short& s_y)
		: name(str_name),
		isClosed(false),
		windowSize(WindowSize(s_width, s_height)),
		windowPosition(WindowPosition(s_x, s_y))
	{
		init();
	};

	Window::Window(std::string& str_name, WindowSize& windowSize)
		: name(str_name),
		isClosed(false),
		windowSize(windowSize),
		windowPosition(WindowPosition())
	{
		init();
	};

	Window::Window(std::string& str_name, WindowSize& windowSize, WindowPosition& windowPosition)
		: name(str_name),
		isClosed(false),
		windowSize(windowSize),
		windowPosition(windowPosition)
	{
		init();
	};

	void Window::init()
	{
		if (!glfwInit())
		{
			fprintf(stderr, "Failed to create GLFW3 / OpenGL context");
			system("PAUSE");
			exit(EXIT_FAILURE);
		}
		else
			fprintf(stderr, "GLFW3 initialized!\n");
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		window = glfwCreateWindow(windowSize.width, windowSize.height, name.c_str(), nullptr, nullptr);

		glewExperimental = GL_TRUE;

		glfwMakeContextCurrent(window);

		switch (glewInit())
		{
		case GLEW_ERROR_NO_GL_VERSION: fprintf(stderr, "No gl version"); break;
		case GLEW_ERROR_GL_VERSION_10_ONLY: fprintf(stderr, "Gl version 10"); break;
		}

		glViewport(0, 0, windowSize.width, windowSize.height);
		glfwSwapInterval(1);
		glEnable(GL_DEPTH_TEST);
	}

	void Window::update()
	{
		isClosed = glfwWindowShouldClose(window);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void Window::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}