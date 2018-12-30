#include "hzpch.h"
#include "LayerStack.h"

namespace Hazel {
	LayerStack::LayerStack()
		:_layerInsert(_layers.begin())
	{}


	LayerStack::~LayerStack() {
		for (auto layer : _layers)
			delete layer;
	}

	void LayerStack::pushLayer(Layer* layer) {
		_layerInsert = _layers.emplace(_layerInsert, layer);
	}

	void LayerStack::popLayer(Layer* layer) {
		auto it = std::find(_layers.begin(), _layers.end(), layer);
		if (it != _layers.end()) {
			_layers.erase(it);
			_layerInsert--;
		}
	}

	void LayerStack::pushOverlay(Layer* overlay) {
		_layers.emplace_back(overlay);
	}

	void LayerStack::popOverlay(Layer* overlay) {
		auto it = std::find(_layers.begin(), _layers.end(), overlay);
		if (it != _layers.end()) {
			_layers.erase(it);
		}
	}
}

