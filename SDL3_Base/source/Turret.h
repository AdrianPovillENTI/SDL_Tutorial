#pragma once
#include "Gun.h"
class Turret : public Gun
{
private:
    float angle;
    float rotSpeed;
    Vector2 aim;

public: 
    Turret(string sprite, vector<string> bulletAnim, float speed, int dmg, Vector2 spawnBullet) : Gun(sprite, bulletAnim, speed, dmg, spawnBullet), angle(0), rotSpeed(10), aim(Vector2(0.f, 0.f)) {}

    void Update() override;
};

