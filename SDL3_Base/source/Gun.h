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
		vector<string> bulletAnimationSprites;
		string gunSprite;

	public:
		Gun(string sprite, vector<string> bulletAnim, float _speed, float _cadence, int _dmg, Vector2 spawnBullet);

		void Update() override;
		virtual void Shoot();
		void OnCollision(Object* collided) override {}
};

