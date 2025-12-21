#pragma once
#include "Gun.h"
class AmmoGun : public Gun
{
private:
    int ammo;
    int maxAmmo;

public:
    AmmoGun(string sprite, vector<string> bulletAnim, float speed, int dmg, int ammo, Vector2 spawnBullet) : 
        Gun(sprite, bulletAnim, speed, dmg, spawnBullet), maxAmmo(ammo), ammo(maxAmmo) {}
    void Shoot() override;
    void ResetAmmo() { ammo = maxAmmo; }
    int GetAmmo() { return ammo; }
};

