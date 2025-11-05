#pragma once
#include "Renderer.h"

class ImageRenderer : public Renderer {
public:
	void LoadTexture(std::string texturePath, SDL_Renderer* renderer) override;
<<<<<<< HEAD
	void Update() override;
	void Render(SDL_Renderer* renderer) override;
=======
	virtual void Update() override;
	virtual void Render() override;
>>>>>>> parent of 14887ae (Input Manager)
};