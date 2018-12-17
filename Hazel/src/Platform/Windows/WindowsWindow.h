#pragma once

#include "Hazel/Window.h"

#include <GLFW/glfw3.h>

namespace Hazel {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned getWidth() const override { return _data.width; }
		inline unsigned getHeight() const override { return _data.height; }

		// Window attributes
		inline void setEventCallback(const EventCallbackFn& callback) override { _data.EventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;

	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();

	private:
		GLFWwindow* _window;

		struct WindowData {
			std::string title;
			unsigned width, height;
			bool vsync;

			EventCallbackFn EventCallback;
		};

		WindowData _data;
	};
}


