#include "Bullet.h"
#include "RenderManager.h"

Bullet::Bullet(const std::string& path)
	: DamageableObject(1, path),
	  damage(5),
	  speed(2)
{
	_transform->scale = Vector2(2, 2);
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

	if (_transform->position.x > RM->WINDOW_WIDTH * 1.4f || _transform->position.x < 0||
		_transform->position.y > RM->WINDOW_HEIGHT * 1.3f||_transform->position.y < 0)
	{
		Destroy();
	}
}

void Bullet::Move()
{
	_physics->SetVelocity(Vector2(speed, 0));
}