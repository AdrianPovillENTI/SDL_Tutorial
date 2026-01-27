#include "Turret.h"
#include "Bullet.h"
#include "../../Spawner.h"

Turret::Turret(string sprite, vector<string> bulletAnim, float speed, int dmg, Vector2 spawnBullet, bool _lowerTurret) : 
	Gun(sprite, bulletAnim, speed, dmg, spawnBullet), lowerTurret(_lowerTurret)
{
	_transform->scale = (Vector2(0.5f, 0.5f));
	_transform->rotation = 90;
	goingRight = false;
	active = false;
	lastX = _transform->position.x;
	checkXpos = lastX;
	offset = 100;
	topRotation = 90;
}

void Turret::Update() {

	GameObject::Update();
	
	if (!active) return;

	bool right = _transform->position.x > lastX ? true : false;

	if (goingRight == right)
	{
		if (right)
		{
			if (_transform->position.x - checkXpos > offset)
			{
				if (lowerTurret && _transform->rotation < topRotation * 3)
				{
					_transform->rotation += 45;
				}
				else if (!lowerTurret && _transform->rotation > -topRotation)
					_transform->rotation -= 45;

				checkXpos = _transform->position.x;
			}
		}
		else
		{
			if (checkXpos - _transform->position.x > offset)
			{
				if (lowerTurret && _transform->rotation > topRotation)
					_transform->rotation -= 45;
				else if (!lowerTurret && _transform->rotation < topRotation)
					_transform->rotation += 45;

				checkXpos = _transform->position.x;
			}
		}
	}
	else
	{
		goingRight = right;
		checkXpos = _transform->position.x;
	}

	lastX = _transform->position.x;
}

void Turret::Shoot()
{
	Vector2 aim;

	if (_transform->rotation == 90)
		aim = Vector2::Right;
	else if (_transform->rotation == 45)
		aim = Vector2::Right + Vector2::Down;
	else if (_transform->rotation == 0)
		aim = Vector2::Down;
	else if (_transform->rotation == -45)
		aim = Vector2::Left + Vector2::Down;
	else if (_transform->rotation == -90)
		aim = Vector2::Left;
	else if (_transform->rotation == 135)
		aim = Vector2::Right + Vector2::Up;
	else if (_transform->rotation == 180)
		aim = Vector2::Up;
	else if (_transform->rotation == 225)
		aim = Vector2::Left + Vector2::Down;
	else
		aim = Vector2::Left;

	Bullet* b = new Bullet(bulletAnimationSprites, bulletSpeed, bulletDamage, aim);
	b->GetTransform()->position = _transform->position + bulletSpawnPoint;

	SPAWNER.SpawnObject(b);
}