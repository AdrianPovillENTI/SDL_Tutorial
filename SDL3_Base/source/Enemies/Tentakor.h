#pragma once
#include "Enemy.h"
#include "../EnemyBullet.h"
class Tentakor : public Enemy
{
private:
    float timeToShoot;
    float shootCooldown;
    int bulletDamage;
    int lastPosIndex;
    float bulletSpeed;
    vector<Vector2>bulletSpawnPoints;
    Vector2 lastSpawnPos;
    vector<string>bulletAnimationSprites;
public:
    Tentakor ();
    void Start ( ) override;
    void Shoot ( );
    void Update ( ) override; 
};

