#include "Gun.h"
#include "Bullet.h"
#include "../../Spawner.h"

Gun::Gun(string sprite, vector<string> bulletAnim, float _speed, int _dmg, Vector2 spawnBullet) :
	GameObject(sprite),
	bulletAnimationSprites(bulletAnim),
	bulletDamage(_dmg), bulletSpeed(_speed), 
	bulletSpawnPoint(spawnBullet)
{ 
	active = false;
}

void Gun::Shoot()
{
	Bullet* b = new Bullet(bulletAnimationSprites, bulletSpeed, bulletDamage);
	b->GetTransform()->position = _transform->position + bulletSpawnPoint;

	SPAWNER.SpawnObject(b);
}
