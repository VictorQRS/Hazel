#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
	Hazel::Log::init();
	HZ_CORE_WARN("Initialized logger");
	HZ_INFO("Hello, {0}", "World");

	auto app = Hazel::CreateApplication();
	app->run();
	delete app;

	return 0;
}

#endif