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

	spriteAnimationFrames = {
		"resources/Player/NormalShoot/shot_1.png",
		"resources/Player/NormalShoot/shot_2.png",
		"resources/Player/NormalShoot/shot_3.png",
		"resources/Player/NormalShoot/shot_4.png",
		"resources/Player/NormalShoot/shot_5.png",
		"resources/Player/NormalShoot/shot_6.png"
	};
}

Bullet::~Bullet() = default;

void Bullet::Start()
{
	SetActive(true);
}

void Bullet::Update()
{
	if (!active) return;

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
		if ( currentFrame >= spriteAnimationFrames.size ( ) - 1) currentFrame = spriteAnimationFrames.size() - 3;

		currentFrame = (currentFrame + 1) % spriteAnimationFrames.size ( );
		_renderer->SetResourcePath(spriteAnimationFrames[currentFrame]);
	}
}

void Bullet::Move()
{
	_physics->SetVelocity(Vector2(speed, 0));
}

void Bullet::SetAnimationSprites ( vector<string> & _spriteAnimationFrames )
{
    spriteAnimationFrames = _spriteAnimationFrames;
}
