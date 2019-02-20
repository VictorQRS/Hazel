#include <Hazel.h>

class ExampleLayer : public Hazel::Layer {
public:
	ExampleLayer() : Layer("Example") {}

	void onUpdate() override {
		if (Hazel::Input::isKeyPressed(HZ_KEY_TAB))
			HZ_TRACE("Tab key is pressed!");
	}

	void onEvent(Hazel::Event& event) override {
		if (event.GetEventType() == Hazel::EventType::KeyPressed) {
			auto& e = static_cast<Hazel::KeyPressedEvent&>(event);
			if (e.GetKeyCode() == HZ_KEY_TAB)
				HZ_TRACE("Tab key is pressed (event)!");
			HZ_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Hazel::Application {
public:
	Sandbox() {
		pushLayer(new ExampleLayer());
		pushOverlay(new Hazel::ImGuiLayer());
	}

	~Sandbox() {}
};

Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}