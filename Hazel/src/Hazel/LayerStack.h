#pragma once

#include "Hazel/Core.h"
#include "Layer.h"

#include <vector>

namespace Hazel {
	class LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void pushLayer(Layer* layer);
		void popLayer(Layer* layer);
		
		void pushOverlay(Layer* overlay);
		void popOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return _layers.begin(); }
		std::vector<Layer*>::iterator end() { return _layers.end(); }

	private:
		std::vector<Layer*> _layers;
		std::vector<Layer*>::iterator _layerInsert;
	};
}

