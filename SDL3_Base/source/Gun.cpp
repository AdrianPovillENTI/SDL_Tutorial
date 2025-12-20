#include "Gun.h"
#include "Bullet.h"
#include "Spawner.h"

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
	Bullet* bullet1 = new Bullet(bulletAnimationSprites, bulletSpeed, bulletDamage);
	bullet1->GetTransform()->position = _transform->position + bulletSpawnPoint;
	Bullet* bullet2 = new Bullet(bulletAnimationSprites, bulletSpeed, bulletDamage);
	bullet2->GetTransform()->position = _transform->position + bulletSpawnPoint + Vector2::Left;

	SPAWNER.SpawnObject(bullet1);
	SPAWNER.SpawnObject(bullet2);
}
