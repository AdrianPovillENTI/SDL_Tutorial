#pragma once
#include "../ImageObject.h"
#include "../TextRenderer.h"
#include "../InputManager.h"
#include <functional>

class Button : public ImageObject {

public:
    using OnClick = std::function<void()>;

private:
    bool _isHovered;
    OnClick _onClick;

private:
    void OnHoverEnter();
    void OnHoverExit();
    void OnClicked();

public:
    Button(OnClick onClick,
           Vector2 position = Vector2(200.f, 100.f),
           Vector2 size = Vector2(350, 100),
           std::string texturePath = "resources/xd.png")
        : ImageObject(texturePath, position, size),
          _isHovered(false),
          _onClick(onClick)
    {
        _transform->position = position;
        _transform->size = size;
        _transform->scale = Vector2(1.f, 1.f);
        _physics->AddCollider(new AABB(_transform->position, _transform->size));
    }

    void Update() override;
    void Render() override;

    void OnCollision(Object* collided) override;
};