#pragma once
#include "GameObject.h"

class Gun : public GameObject
{
protected:
	float bulletSpeed;
	int bulletDamage;
	Vector2 bulletSpawnPoint;
	vector<string> bulletAnimationSprites;
	string gunSprite;

public:
	Gun(string sprite, vector<string> bulletAnim, float _speed, int _dmg, Vector2 spawnBullet);

	virtual void Shoot();
};

