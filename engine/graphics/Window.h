#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

namespace lambda { namespace graphics {
	class Window {
	private:
		const char* m_title;
		int m_width, m_height;
		GLFWwindow* m_window;
		bool m_closed;

		bool init(); // The main window function
	public:
		Window(const char* title, int width, int height);
		~Window();
		void update(); // Runs every tick.
		bool closed() const;
		void clear() const; // Clears the screen. This is needed apparently because you can't show shit without clearing the screen upon init.

		inline int getWidth() const { return m_width; }
		inline int getHeight() const { return m_height; }
	};
} }