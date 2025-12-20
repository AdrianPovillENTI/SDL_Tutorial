#pragma once
#include "Gun.h"
class AmmoGun : public Gun
{
private:
    int ammo;

public:
    AmmoGun(string sprite, vector<string> bulletAnim, float speed, int dmg, Vector2 spawnBullet) : 
        Gun(sprite, bulletAnim, speed, dmg, spawnBullet), ammo(100) {}
    void Shoot() override;
    void ResetAmmo() { ammo = 100; }
    int GetAmmo() { return ammo; }
};

