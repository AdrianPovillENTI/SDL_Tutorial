#pragma once
#include "Gun.h"
class Turret : public Gun
{
private:
    float angle;
    float rotSpeed;
    Vector2 aim;

public: 
    Turret(std::vector<std::string> bulletAnim, float speed, float cadence, int dmg, Vector2 spawnBullet) : Gun(bulletAnim, speed, cadence, dmg, spawnBullet), angle(0), rotSpeed(10), aim(Vector2(0.f, 0.f)) {}

    void Update() override;
};

