#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Window.h"

namespace Hazel {
	class HAZEL_API Application {
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);
	private:
		bool onWindowClose(WindowCloseEvent& wce);

		std::unique_ptr<Window> _window;
		bool _running = true;
	};

	// To be defined in the client
	Application* CreateApplication();
}

