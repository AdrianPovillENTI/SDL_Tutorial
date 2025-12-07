#pragma once
#include "DamageableObject.h"
#include "Spawner.h"
#include "Bullet.h"

#pragma region
#include "Item.h"
#include "Cannon.h"
#include "Laser.h"
#include "ForceField.h"
#include "Shield.h"
#include "SpeedUpgrade.h"
#include "Score.h"
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
    int originalMaxShootCooldownTime;

    std::string bulletSprite;
    int bulletDamage;
    int originalDamage;
    bool isDeath;
    float speed;
    float shotSpeed;

    Vector2 offset;

    std::vector<Item *> inventory;

public:
    Player ( int maxHealth );
    ~Player ( );

    void Move ( ) override;
    void Start ( ) override;
    void Update ( ) override;

    void Shoot ( );
    void SetShootSpeed ( );
    bool GetInvencibleStatus ( );

    void ClampInsideScreen ( ); // <<< NUEVO
};