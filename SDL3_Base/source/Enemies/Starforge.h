#pragma once
#include "Enemy.h"
#include "../EnemyBullet.h"
class Starforge : public Enemy
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
    Starforge ( );
    void Start ( ) override;
    void Shoot ( );
    void Update ( ) override;
};

