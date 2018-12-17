#include "hzpch.h"
#include "WindowsWindow.h"

namespace Hazel {
	static bool s_GLFWinitialized = false;

	Window* Window::create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		init(props);
	}

	WindowsWindow::~WindowsWindow() {
		shutdown();
	}

	void WindowsWindow::init(const WindowProps& props) {
		_data.title = props.title;
		_data.width = props.width;
		_data.height = props.height;

		HZ_CORE_INFO("Creating window {0} ({1} {2})", props.title, props.width, props.height);

		if (!s_GLFWinitialized) {
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			HZ_CORE_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWinitialized = true;
		}

		_window = glfwCreateWindow(
			(int)props.width,
			(int)props.height,
			_data.title.c_str(),
			nullptr,
			nullptr
		);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		setVSync(true);
	}

	void WindowsWindow::shutdown() {
		glfwDestroyWindow(_window);
	}

	void WindowsWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}

	void WindowsWindow::setVSync(bool enabled) {
		glfwSwapInterval(enabled ? 1 : 0);
		_data.vsync = enabled;
	}

	bool WindowsWindow::isVSync() const {
		return _data.vsync;
	}
}