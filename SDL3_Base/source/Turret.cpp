#include "Turret.h"
Turret::Turret(string sprite, vector<string> bulletAnim, float speed, int dmg, Vector2 spawnBullet, bool _lowerTurret) : 
	Gun(sprite, bulletAnim, speed, dmg, spawnBullet), angle(0), rotSpeed(10), aim(Vector2(0.f, 0.f)), lowerTurret(_lowerTurret)
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
					_transform->rotation += 45;
				else if (!lowerTurret && _transform->rotation > -topRotation)
					_transform->rotation -= 45;

				checkXpos = _transform->position.x;
				cout << _transform->rotation << endl;
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
				cout << _transform->rotation << endl;
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