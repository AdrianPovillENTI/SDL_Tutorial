#include "Gun.h"
#include "Bullet.h"
#include "../../Spawner.h"
#include "../../Audio/AudioManager.h"

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
	AM->PlaySound("resources/audio/sfx/Shot.wav");
	SPAWNER.SpawnObject(b);
}
