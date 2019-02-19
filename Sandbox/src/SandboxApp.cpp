#include <Hazel.h>

class ExampleLayer : public Hazel::Layer {
public:
	ExampleLayer() : Layer("Example") {}

	void onUpdate() override { HZ_INFO("ExampleLayer::Update"); }
	void onEvent(Hazel::Event& event) override { HZ_TRACE("{0}", event); }
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