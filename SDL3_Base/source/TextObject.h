#pragma once
#include "Object.h"
#include "TextRenderer.h"

class TextObject : public Object
{
public:
	TextObject(std::string text);
	TextObject(std::string text, Vector2 pos, Vector2 scale);

	void SetText(std::string text){ dynamic_cast<TextRenderer*>(_renderer)->SetText(text); }
};
