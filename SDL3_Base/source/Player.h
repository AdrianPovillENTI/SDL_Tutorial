#pragma once
#include "DamageableObject.h"
#include "Spawner.h"
#include "Bullet.h"

#pragma region
#include "Item.h"
#include "AmmoGun.h"
#include "SpeedVfx.h"
#include "Turret.h"
#pragma endregion Items

class Player : public DamageableObject
{
public:
    static const int maxEquippedItem = 3;

private:
    int lifes;
    bool invencible;
    float invencibleTime;

    bool canShoot;
    float shootCooldown;
    float maxShootCooldownTime;
    std::vector<std::string> bulletSprites;
    int bulletDamage;
    float bulletSpeed;

    bool isDeath;
    float speed;
    float speedUpgrade;

    int score;
    float hitMaxTime;
    float hitCounter;
    bool hitted;

    Vector2 bulletSpawnPoint;

    AmmoGun* cannon;
    vector<string> cannonBulletAnim;
    string cannonSprite;
    Vector2 cannonBulletSpawnPoint;
    AmmoGun* laser;
    vector<string> laserBulletAnim;
    string laserSprite;
    Vector2 laserBulletSpawnPoint;

    vector<Turret*> turrets;
    vector<string> turretBulletAnim;    
    string turretSprite;    
    Vector2 turretsBulletSpawnPoint;

    SpeedVfx* speedVfx;
    bool isMoving;

public:
    Player ( int maxHealth );
    ~Player ( );

    void Move ( ) override;
    void Start ( ) override;
    void Update ( ) override;
    
    void OnCollision(Object* collided) override;

    void Shoot ( );
    void ApplyItemEffects (Item* item);
    bool GetInvencibleStatus ( );

    void ClampInsideScreen ( );

    void ReceiveDamage ( int _health ) override;
    void InitializeStats();
    void InitializeGuns();
    void InitializePhysics();
};