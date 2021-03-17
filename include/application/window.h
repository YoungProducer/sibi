#pragma once

#include <string>

#include "engine.h"

namespace Application {
	struct WindowSize {
		short width;
		short height;

		WindowSize(short s_width, short s_height) : width(s_width), height(s_height) {};
	};

	struct WindowPosition {
		short x;
		short y;

		WindowPosition(): x(0), y(0) {};
		WindowPosition(short& s_x, short& s_y) : x(s_x), y(s_y) {};
	};

	class Window {
	public:
		Window(const char* str_name, short s_width, short s_height);
		Window(std::string& str_name, short& s_width, short& s_height, short& s_x, short& s_y);
		Window(std::string& str_name, WindowSize& windowSize);
		Window(std::string& str_name, WindowSize& windowSize, WindowPosition& windowPosition);

	public:
		void init();
		void update();
		void clear();

	public:
		inline void setWindowSize(const short& s_width, const short& s_height) { windowSize.height = s_height; windowSize.width = s_height; glfwSetWindowSize(window, s_width, s_height); };
		inline void setWindowPosition(const short& s_x, const short& s_y) { windowPosition.x = s_x; windowPosition.y = s_y; glfwSetWindowPos(window, s_x, s_y); };

		inline const WindowSize& getWindowSize() const { return windowSize; };
		inline const WindowPosition& getWindowPosition() const { return windowPosition; };

		inline const bool& getIsClosed() const { return isClosed; };

	private:
		std::string name;
		WindowSize windowSize;
		WindowPosition windowPosition;

		GLFWwindow* window;

		bool isClosed;
	};
}

