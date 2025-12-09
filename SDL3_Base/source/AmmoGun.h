#pragma once
#include "Gun.h"
class AmmoGun : public Gun
{
private:
    int ammo;

public:
    AmmoGun(std::vector<std::string> bulletAnim, float speed, float cadence, int dmg, Vector2 spawnBullet) : Gun(bulletAnim, speed, cadence, dmg, spawnBullet), ammo(0) {}
    void Shoot() override;
    void ResetAmmo() { ammo = 100; }
    int GetAmmo() { return ammo; }
};

