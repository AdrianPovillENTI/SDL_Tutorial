#pragma once
#include "Gun.h"
#include <functional>
class AmmoGun : public Gun
{
private:
    int ammo;
    int maxAmmo;

public:
    std::function<void(int ammo, int maxAmmo)> onAmmoChanged;

    AmmoGun(string sprite, vector<string> bulletAnim, float speed, int dmg, int ammo, Vector2 spawnBullet) : 
        Gun(sprite, bulletAnim, speed, dmg, spawnBullet), maxAmmo(ammo), ammo(maxAmmo) {}


    void Shoot() override;
    void ResetAmmo();
    int GetAmmo() { return ammo; }
    int GetMaxAmmo() { return maxAmmo; }
};

