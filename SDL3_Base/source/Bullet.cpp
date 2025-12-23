#include "Bullet.h"
#include "Enemies/Enemy.h"

#include "RenderManager.h"

Bullet::Bullet(const std::vector<std::string>& _anim, float _speed, int _damage)
	: GameObject(_anim[0]), Animator(_anim),
	damage(_damage), speed(_speed)
{
	_transform->scale = Vector2 ( 0.2f , 0.2f );
	_physics->AddCollider(new AABB(_transform->position, _transform->size));
}
void Bullet::Start ( )
{
}

void Bullet::Update()
{
	GameObject::Update();

	_physics->SetVelocity(Vector2(speed, 0.f));

	_renderer->SetResourcePath ( ChangeSpriteFrame ( ) );

	if (_transform->position.x > RM->WINDOW_WIDTH * 1.4f || _transform->position.x < 0 ||
		_transform->position.y > RM->WINDOW_HEIGHT * 1.3f || _transform->position.y < 0)
		Destroy();
}

void Bullet::OnCollision(Object* other)
{
	if (dynamic_cast<Item*>(other) || dynamic_cast<Enemy*>(other))
		Destroy();
}

