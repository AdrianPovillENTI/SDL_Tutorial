#pragma once
#include "Transform.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>

class Renderer {
	protected:
		Transform* _transform;
		SDL_Texture* _texture;
		SDL_FRect _sourceRect;
		SDL_FRect _destinationRect;
		std::string _resourcePath;

	public:
		virtual void LoadTexture(std::string texturePath, SDL_Renderer* renderer) = 0;
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;
		virtual void SetDestinationRect(SDL_FRect rect) {
			_destinationRect = rect;
		}
};