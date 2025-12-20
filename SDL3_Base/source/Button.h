#pragma once
#include "ImageObject.h"
#include "TextRenderer.h"
#include "InputManager.h"
#include <functional>

class Button : public ImageObject {

public:

	typedef std::function<void()> OnClick;

private:

	bool _isHovered;
	OnClick _onClick;

private:

	void OnHoverEnter();
	void OnHoverExit();
	void OnClicked();

public:

	Button(OnClick onClick) : ImageObject("resources/xd.png", Vector2(0.f, 0.f), Vector2(1306.f, 900))
	{
		_onClick = onClick;
		//test
		_transform->position = Vector2(100.f, 100.f);
		_transform->scale = Vector2(1.f, 1.f);

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}

	virtual void Update() override;
	virtual void Render() override;
};