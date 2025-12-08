#include "Bullet.h"
#include "RenderManager.h"
Bullet::Bullet(const string path)
	: DamageableObject(1, path),
	  damage(5),
	  speed(2),
	  frameTime(0.0f),
	  frameTimeMax(30),
	  currentFrame(0)
{
	_transform->scale = Vector2(2, 2);
	animationFrames = {
		"resources/Player/NormalShoot/shot_1.png",
		"resources/Player/NormalShoot/shot_2.png",
		"resources/Player/NormalShoot/shot_3.png",
		"resources/Player/NormalShoot/shot_4.png",
		"resources/Player/NormalShoot/shot_5.png",
		"resources/Player/NormalShoot/shot_6.png"
	};
}

Bullet::~Bullet() = default;


void Bullet::Update()
{
	GameObject::Update();

	Move();
	ChangeSpriteFrame();

	if (_transform->position.x > RM->WINDOW_WIDTH * 1.4f || _transform->position.x < 0 ||
		_transform->position.y > RM->WINDOW_HEIGHT * 1.3f || _transform->position.y < 0)
	{
		Destroy();
	}
}

void Bullet::ChangeSpriteFrame()
{
	frameTime += 1.0f / 60.0f;

	if (frameTime >= frameTimeMax)
	{
		frameTime = 0.0f;
		if ( currentFrame >= animationFrames.size ( ) - 1) currentFrame = animationFrames.size() - 3;

		currentFrame = (currentFrame + 1) % animationFrames.size ( );
		_renderer->SetResourcePath(animationFrames[currentFrame]);
	}
}

void Bullet::Move()
{
	_physics->SetVelocity(Vector2(speed, 0));
}

void Bullet::SetAnimationSprites ( vector<string> & _animationFrames )
{
    animationFrames = _animationFrames;
}
