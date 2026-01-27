#pragma once
#include "../DamageableObject.h"
#include "../Spawner.h"
#include "Gun/Bullet.h"
#include "Gun/Gun.h"

#include "PlayerHealth.h"

#pragma region
#include "Gun/AmmoGun.h"
#include "Gun/Turret.h"
#pragma endregion Items

class Player : public DamageableObject
{
private:
    PlayerHealth healthManager;

    bool canShoot;
    float shootCooldown;
    float maxShootCooldownTime;

    float speed;
    float speedUpgrade;

    int score;
    float hitMaxTime;
    float hitCounter;
    bool hitted;

    Gun* primaryGun;
    AmmoGun* cannon;
    AmmoGun* laser;
    vector<Turret*> turrets;

    bool isMoving;

public:
    Player ( int maxHealth );
    ~Player ( );

    void Move ( ) override;
    void Start ( ) override;
    void Update ( ) override;

    void Shoot ( );
    void FillShield();
    void SetCannon();
    void SetLaser();
    void SetTurret();
    void SetInvincible();
    void SetSpeedUpgrade();
    bool GetInvencibleStatus ( );

    void ClampInsideScreen ( );

    void OnCollision(Object* o) override;
    void ReceiveDamage ( int _health ) override;

    void InitializeStats();
    void InitializeGuns();
    void InitializePhysics();
};