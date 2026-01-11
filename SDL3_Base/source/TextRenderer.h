#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <cassert>

#include "Renderer.h"
#include "RenderManager.h"

#define FONT_PATH "resources/fonts/Hyperspace.ttf"

class TextRenderer : public Renderer
{
protected:
	std::string _text;
	SDL_Texture* _textTexture;
	bool _autoSize = true;

public:
	TextRenderer(Transform* transform, std::string text);
	~TextRenderer();

	void SetText(std::string text);
	void SetColor(SDL_Color color) override;

	virtual void Update(float dt) override;
	virtual void Render() override;
};

