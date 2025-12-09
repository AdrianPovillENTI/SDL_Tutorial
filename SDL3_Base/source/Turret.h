#pragma once
#include "Gun.h"
class Turret :
    public Gun
{
private:
    float angle;
    float rotSpeed;
public: 
    Turret(std::vector<std::string> bulletAnim, float speed, float cadence, int dmg, Vector2 spawnBullet) : Gun(bulletAnim, speed, cadence, dmg, spawnBullet), angle(0), rotSpeed(10) {}

    void Update() override;
};

