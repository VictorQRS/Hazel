#pragma once

#include "Hazel/Layer.h"

namespace Hazel {
	class HAZEL_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach() override;
		void onDetach() override;
		void onUpdate() override;
		void onEvent(Event& event) override;
	private:
		float _time = .0f;
	};
}


