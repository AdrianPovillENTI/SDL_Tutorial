#include "Object.h"
#include "TextRenderer.h"

class TextObject : public Object
{
public:
	TextObject(std::string text) : Object()
	{
		_renderer = new TextRenderer(_transform, text);
		_renderer->SetColor({ 1, 1, 1, 0xFF });
	}

	TextObject(std::string text, Vector2 pos, Vector2 scale) : Object()
	{
		_transform->position = pos;
		_transform->scale = scale;
		_renderer = new TextRenderer(_transform, text);
		_renderer->SetColor({ 1, 1, 1, 0xFF });
	}

	void SetText(std::string text)
	{
		dynamic_cast<TextRenderer*>(_renderer)->SetText(text);
	}

	// Heredado vía Object
	void OnCollision ( Object * collided ) override;
};
