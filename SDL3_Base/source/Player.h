#pragma once
#include "DamageableObject.h"
#include "Spawner.h"
#include "Bullet.h"

#pragma region
#include "Item.h"
#include "AmmoGun.h"
#include "SpeedUpgrade.h"
#include "SpeedVfx.h"
#include "Turret.h"
#pragma endregion Items

class Player : public DamageableObject
{
public:
    static const int maxEquippedItem = 3;

private:
    bool invencible;
    float invencibleTime;

    bool canShoot;
    float shootCooldown;
    float maxShootCooldownTime;
    std::vector<std::string> bulletSprites;
    int bulletDamage;
    int originalDamage;
    float bulletSpeed;

    bool isDeath;
    float speed;
    float shotSpeed;

    float speedUpgrade;

    Vector2 offset;

    std::vector<Item *> inventory;

    AmmoGun* cannon;
    std::vector<std::string> cannonAnim;
    Vector2 cannonPos;
    AmmoGun* laser;
    std::vector<std::string> laserAnim;
    Vector2 laserPos;

    std::vector<Turret*> turrets;
    std::vector<std::string> turretAnim;    
    Vector2 turretsPos;

    SpeedVfx* speedVfx;
    bool isMoving;
    bool turboActivated;

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

    void ClampInsideScreen ( ); // <<< NUEVO

    void InitializeStats();
    void InitializeGuns();
    void InitializePhysics();
};