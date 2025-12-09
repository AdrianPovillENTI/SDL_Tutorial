#pragma once
#include "GameObject.h"

class Gun : public GameObject
{
	private:
		float bulletSpeed;
		int bulletDamage;

		bool canShoot;
		float shootCooldown;
		float maxShootCooldownTime;

		Vector2 bulletSpawnPoint;
		std::vector<std::string> bulletAnimationSprites;

	public:
		Gun(std::vector<string> bulletAnim, float _speed, float _cadence, int _dmg, Vector2 spawnBullet);

		void Update() override;
		virtual void Shoot();
		void OnCollision(Object* collided) override {}
};

