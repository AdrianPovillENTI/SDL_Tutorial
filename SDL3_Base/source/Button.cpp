#include "Button.h"

void Button::OnHoverEnter() {
	_transform->rotation = 90.f;
	_isHovered = true;
}
void Button::OnHoverExit() {
	_transform->rotation = 0.f;
	_isHovered = false;
}
void Button::OnClicked() {
	_onClick();
}

void Button::Update()
{
	if (!_isHovered && _physics->CheckOverlappingPoint({ (float)IM->GetMouseX(), (float)IM->GetMouseY() }))
		OnHoverEnter();
	else if (_isHovered && !_physics->CheckOverlappingPoint({ (float)IM->GetMouseX() , (float)IM->GetMouseY() }))
		OnHoverExit();
	else if (_isHovered && IM->GetLeftClick())
		OnClicked();

	Object::Update();
}

void Button::Render()
{
	Object::Render();
}