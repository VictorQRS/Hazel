#pragma once

#include "hzpch.h"

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {
	struct WindowProps {
		std::string title;
		unsigned width;
		unsigned height;

		WindowProps(
			const std::string& title = "HazelEngine",
			unsigned width  = 1280,
			unsigned height = 720
		)
			: title(title), width(width), height(height)
		{}
	};

	// Interface representing a desktop system based Window
	class HAZEL_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void onUpdate() = 0;

		virtual unsigned getWidth() const = 0;
		virtual unsigned getHeight() const = 0;

		// Windows attributtes
		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		virtual void* getNativeWindow() const = 0;

		static Window* create(const WindowProps& props = WindowProps());
	};
}