#include "Gun.h"
#include "Bullet.h"
#include "Spawner.h"

Gun::Gun(std::vector<std::string> bulletAnim, float _speed, float _cadence, int _dmg, Vector2 spawnBullet) : 
	GameObject("resources/Items/Cannon.png"), 
	bulletAnimationSprites(bulletAnim),
	bulletDamage(_dmg), bulletSpeed(_speed), 
	canShoot(true), 
	shootCooldown(0), 
	maxShootCooldownTime(_cadence),  
	bulletSpawnPoint(spawnBullet)
{ 
	active = false;
}

void Gun::Shoot()
{
	if (!canShoot) return;

	Bullet* bullet = new Bullet(bulletAnimationSprites, bulletSpeed, bulletDamage);
	bullet->GetTransform()->position = _transform->position + bulletSpawnPoint;

	SPAWNER.SpawnObject(bullet);

	canShoot = false;
	shootCooldown = maxShootCooldownTime;
}

void Gun::Update()
{
	if (!canShoot)
	{
		shootCooldown -= 1.f / 60.f;
		if (shootCooldown <= 0.f)
		{
			canShoot = true;
			shootCooldown = 0.f;
		}
	}
}
