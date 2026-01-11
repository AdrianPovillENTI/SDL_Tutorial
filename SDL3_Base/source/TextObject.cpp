#include "TextObject.h"

TextObject::TextObject(std::string text) : Object()
{
	_renderer = new TextRenderer(_transform, text);
	_renderer->SetColor({ 1, 1, 1, 0xFF });
}

TextObject::TextObject(std::string text, Vector2 pos, Vector2 scale) : Object()
{
	_transform->position = pos;
	_transform->scale = scale;
	_renderer = new TextRenderer(_transform, text);
	_renderer->SetColor({ 1, 1, 1, 0xFF });
}
