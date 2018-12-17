#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Hazel/Window.h"

namespace Hazel {
	class HAZEL_API Application {
	public:
		Application();
		virtual ~Application();

		void run();

	private:
		std::unique_ptr<Window> _window;
		bool _running = true;
	};

	// To be defined in the client
	Application* CreateApplication();
}

