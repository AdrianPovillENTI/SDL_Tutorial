#include "TextRenderer.h"

TextRenderer::TextRenderer(Transform* transform, std::string text) : Renderer(transform, FONT_PATH) {
	SetText(text);
}

TextRenderer::~TextRenderer()
{
	SDL_DestroyTexture(_textTexture);
	_textTexture = nullptr;
}

void TextRenderer::SetText(std::string text)
{
	if (_textTexture != nullptr)
		SDL_DestroyTexture(_textTexture);

	SDL_Surface* surf = TTF_RenderText_Solid(
		RM->GetFont(_resourcePath),
		text.c_str(),
		text.length(),
		_color
	);
	assert(surf);

	_textTexture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surf);
	assert(_textTexture);

	_sourceRect = { 0.f, 0.f, (float)surf->w, (float)surf->h };

	_text = text;
}

void TextRenderer::SetColor(SDL_Color color) {
	Renderer::SetColor(color);
	SetText(_text);
}

void TextRenderer::Update(float dt)
{
	Vector2 offset = (Vector2(-_transform->size.x, -_transform->size.y) / 2.0f) * _transform->scale;

	_destinationRect.x = _transform->position.x + offset.x;
	_destinationRect.y = _transform->position.y + offset.x;

	if (_autoSize)
	{
		_destinationRect.w = _sourceRect.w * _transform->scale.x;
		_destinationRect.h = _sourceRect.h * _transform->scale.y;
	}
	else
	{
		_destinationRect.w = _transform->size.x * _transform->scale.x;
		_destinationRect.h = _transform->size.y * _transform->scale.y;
	}
}

void TextRenderer::Render()
{
	SDL_RenderTextureRotated(
		RM->GetRenderer(),
		_textTexture,
		&_sourceRect,
		&_destinationRect,
		_transform->rotation,
		NULL,
		SDL_FLIP_NONE
	);
}
