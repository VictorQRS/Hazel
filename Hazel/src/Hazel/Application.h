#pragma once

#include "Core.h"

#include "Hazel/LayerStack.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Window.h"

namespace Hazel {
	class HAZEL_API Application {
	public:
		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);

		inline static Application& get() { return *s_Instance; }
		inline Window& getWindow() { return *_window; }
	private:
		bool onWindowClose(WindowCloseEvent& wce);

		std::unique_ptr<Window> _window;
		bool _running = true;
		LayerStack _layerStack;
	private:
		static Application* s_Instance;
	};

	// To be defined in the client
	Application* CreateApplication();
}

