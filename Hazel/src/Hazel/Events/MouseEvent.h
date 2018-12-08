#pragma once

#include "../Core.h"

#include <sstream>

#include "Event.h"

namespace Hazel {
	/*
	 * Mouse moved event handler
	 */
	class HAZEL_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: _x(x), _y(y)
		{}

		inline float GetX() const { return _x; }
		inline float GetY() const { return _y; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << GetX() << ", " << GetY();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _x, _y;
	};

	/*
	 * Mouse scrolled event handler
	 */
	class HAZEL_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: _x_offset(xOffset), _y_offset(yOffset)
		{}

		inline float GetXOffset() const { return _x_offset; }
		inline float GetYOffset() const { return _y_offset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float _x_offset, _y_offset;
	};

	/*
	 * Mouse button event handler (base class)
	 */
	class HAZEL_API MouseButtonEvent : public Event {
	public:

		inline float GetMouseButton() const { return _button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button)
			: _button(button)
		{}

		float _button;
	};

	/*
	 * Mouse button pressed event handler
	 */
	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button)
		{}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << GetMouseButton();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

	private:
		float _x_offset, _y_offset;
	};

	/*
	 * Mouse button released event handler
	 */
	class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button)
		{}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << GetMouseButton();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

	private:
		float _x_offset, _y_offset;
	};
}