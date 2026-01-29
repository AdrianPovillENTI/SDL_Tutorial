#pragma once
#include "Object.h"
#include "TextRenderer.h"

class TextObject : public Object
{
public:
	TextObject(std::string text);
	TextObject(std::string text, Vector2 pos, Vector2 scale);
	TextObject(std::string text, Vector2 pos, Vector2 scale, SDL_Color color);

	void SetText(std::string text){ dynamic_cast<TextRenderer*>(_renderer)->SetText(text); }
};
