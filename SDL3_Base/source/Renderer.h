#pragma once
#include "Transform.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>

class Renderer {
	protected:
		Transform* _transform;
		SDL_Color _color;
		SDL_FRect _sourceRect;
		SDL_FRect _destinationRect;
		std::string _resourcePath;

	public:
		Renderer(Transform* transform, std::string resourcePath)
			: _transform(transform), _resourcePath(resourcePath) { }

		virtual void Update(float dt) = 0;
		virtual void Render() = 0;

		virtual void SetColor(SDL_Color color) { color = _color; }
		SDL_Color GetColor() { return _color; }
};