#pragma once

#include "../Core.h"

#include "Event.h"

namespace Hazel {
	/*
	 * Window resize event handler
	 */
	class HAZEL_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned width, unsigned height)
			: _width(width), _height(height)
		{}

		inline unsigned getWidth() const { return _width; }
		inline unsigned getHeight() const { return _height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << getWidth() << ", " << getHeight();
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned _width, _height;
	};

	/*
	 * Window close event handler
	 */
	class HAZEL_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent(){}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	/*
	 * Application tick event handler
	 */
	class HAZEL_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	/*
	 * Application update event handler
	 */
	class HAZEL_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	/*
	 * Application render event handler
	 */
	class HAZEL_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}