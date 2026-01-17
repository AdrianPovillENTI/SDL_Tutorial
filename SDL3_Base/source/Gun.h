#pragma once
#include "GameObject.h"
#include <vector>
#include <string>

class Gun : public GameObject
{
protected:
	float bulletSpeed;
	int bulletDamage;
	Vector2 bulletSpawnPoint;
	std::vector<std::string> bulletAnimationSprites;
	string gunSprite;

public:
	Gun(std::string sprite, std::vector<std::string> bulletAnim, float _speed, int _dmg, Vector2 spawnBullet);

	virtual void Shoot();
};

