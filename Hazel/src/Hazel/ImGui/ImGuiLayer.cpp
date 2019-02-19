#include "hzpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"

#include "Hazel/Application.h"

// TEMPORARY
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Hazel {
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{}


	ImGuiLayer::~ImGuiLayer() {}

	void ImGuiLayer::onAttach() {
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// TEMPORARY: should eventually use Hazel key codes
		io.KeyMap[ImGuiKey_Tab]        = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow]  = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow]    = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow]  = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp]     = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown]   = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home]       = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End]        = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert]     = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete]     = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace]  = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space]      = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter]      = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape]     = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A]          = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C]          = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V]          = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X]          = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y]          = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z]          = GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::onDetach() {

	}

	void ImGuiLayer::onUpdate() {
		ImGuiIO& io = ImGui::GetIO();
		auto& application = Application::get();
		io.DisplaySize = ImVec2(application.getWindow().getWidth(), application.getWindow().getHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = _time > .0 ? (time - _time) : (1.0f / 60.0f);
		_time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::onEvent(Event& event) {
#define HZ_IMGUI_DISPATCH(event) dispatcher.Dispatch<event>(HZ_BIND_EVENT_FN(ImGuiLayer::on ## event))

		EventDispatcher dispatcher(event);
		HZ_IMGUI_DISPATCH(MouseButtonPressedEvent);
		HZ_IMGUI_DISPATCH(MouseButtonReleasedEvent);
		HZ_IMGUI_DISPATCH(MouseMovedEvent);
		HZ_IMGUI_DISPATCH(MouseScrolledEvent);
		HZ_IMGUI_DISPATCH(WindowResizeEvent);
		HZ_IMGUI_DISPATCH(KeyPressedEvent);
		HZ_IMGUI_DISPATCH(KeyReleasedEvent);
		HZ_IMGUI_DISPATCH(KeyTypedEvent);

#undef HZ_IMGUI_DISPATCH
	}


	bool ImGuiLayer::onMouseButtonPressedEvent(MouseButtonPressedEvent& e) {
		auto& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		return false;
	}

	bool ImGuiLayer::onMouseButtonReleasedEvent(MouseButtonReleasedEvent& e) {
		auto& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool ImGuiLayer::onMouseMovedEvent(MouseMovedEvent& e) {
		auto& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		return false;
	}

	bool ImGuiLayer::onMouseScrolledEvent(MouseScrolledEvent& e) {
		auto& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel  += e.GetYOffset();

		return false;
	}

	bool ImGuiLayer::onWindowResizeEvent(WindowResizeEvent& e) {
		auto& io = ImGui::GetIO();

		io.DisplaySize = ImVec2(e.getWidth(), e.getHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.getWidth(), e.getHeight());

		return false;
	}

	bool ImGuiLayer::onKeyPressedEvent(KeyPressedEvent& e) {
		auto& io = ImGui::GetIO();

		io.KeysDown[e.GetKeyCode()] = true;

		return false;
	}

	bool ImGuiLayer::onKeyReleasedEvent(KeyReleasedEvent& e) {
		auto& io = ImGui::GetIO();

		io.KeysDown[e.GetKeyCode()] = false;
		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];

		return false;
	}

	bool ImGuiLayer::onKeyTypedEvent(KeyTypedEvent& e) {
		auto& io = ImGui::GetIO();

		int keycode = e.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter((unsigned int)keycode);


		return false;
	}
}


