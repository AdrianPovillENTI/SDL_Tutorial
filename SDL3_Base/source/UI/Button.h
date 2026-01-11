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
        Vector2 size = Vector2(450, 100), 
        std::string texturePath = "resources/ButtonBKG.png");
    void Update() override;
    void Render() override;
};