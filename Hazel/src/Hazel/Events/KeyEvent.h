#pragma once

#include "../Core.h"

#include "Event.h"

namespace Hazel {
	/*
	 * Key event handler
	 */
	class HAZEL_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return _keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keycode)
			: _keyCode(keycode)
		{}

		int _keyCode;
	};

	/*
	 * Key pressed event handler
	 */
	class HAZEL_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), _repeat(repeatCount)
		{}

		inline int GewrRepeatCount() const { return _repeat; }

		std::string ToString() const override{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _keyCode << " (" << _repeat << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int _repeat;
	};


	/*
	 * Key released event handler
	 */
	class HAZEL_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode)
			: KeyEvent(keycode)
		{}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << _keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}