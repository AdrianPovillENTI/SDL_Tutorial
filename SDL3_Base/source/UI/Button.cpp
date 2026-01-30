#include "Button.h"

Button::Button(OnClick onClick,
	Vector2 position,
	Vector2 size,
	std::string texturePath)
	: ImageObject(texturePath, position, size),
	_isHovered(false),
	_onClick(onClick)
{
	_transform->position = position;
	_transform->size = size;
	_transform->scale = Vector2(1.f, 1.f);
	_physics->AddCollider(new AABB(_transform->position, _transform->size));
}

void Button::OnHoverEnter() {
	_transform->scale = Vector2::One * 0.95f;
	_isHovered = true;
}
void Button::OnHoverExit() {
	_transform->scale = Vector2::One;
	_isHovered = false;
}
void Button::OnClicked() {
	_onClick();
}

void Button::Update()
{
	Object::Update();
	if (!_isHovered && _physics->CheckOverlappingPoint({ (float)IM->GetMouseX(), (float)IM->GetMouseY() }))
		OnHoverEnter();
	else if (_isHovered && !_physics->CheckOverlappingPoint({ (float)IM->GetMouseX() , (float)IM->GetMouseY() }))
		OnHoverExit();
	else if (_isHovered && IM->GetLeftClick())
		OnClicked();
}

void Button::Render()
{
	Object::Render();
	ImageObject::Render ( );
}
