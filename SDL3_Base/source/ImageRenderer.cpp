#include "ImageRenderer.h"
#include <cassert>
#include <SDL3_image/SDL_image.h>

void ImageRenderer::LoadTexture(std::string texturePath, SDL_Renderer* renderer)
{
	_texture = IMG_LoadTexture(renderer, texturePath.c_str());
	assert(_texture);

	_sourceRect = { 0.0f, 0.0f, (float)_texture->w, (float)_texture->h };
}

<<<<<<< HEAD
void ImageRenderer::Update()
=======
 void ImageRenderer::Update() 
>>>>>>> parent of 14887ae (Input Manager)
{
	//does nothing
	//Could update shaders
}

void ImageRenderer::Render(SDL_Renderer* renderer)
{
	SDL_RenderTexture(renderer, _texture, &_sourceRect, &_destinationRect);
}
