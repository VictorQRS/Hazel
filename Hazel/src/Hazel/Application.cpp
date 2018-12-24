#include "hzpch.h"
#include "Application.h"

#include "Hazel/Log.h"

#include <GLFW/glfw3.h>

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application:: ## x, this, std::placeholders::_1)

	Application::Application() {
		_window = std::unique_ptr<Window>(Window::create());
		_window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	Application::~Application() {
	}

	void Application::run() {
		while (_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			_window->onUpdate();
		}
	}

	void Application::onEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

		HZ_CORE_TRACE("{0}", e);
	}

	bool Application::onWindowClose(WindowCloseEvent& wce) {
		Application::_running = false;
		return true;
	}
}
