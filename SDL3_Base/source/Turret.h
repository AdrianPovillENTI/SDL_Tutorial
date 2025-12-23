#pragma once
#include "Gun.h"
class Turret : public Gun
{
private:
    bool lowerTurret;
    float angle;
    float rotSpeed;
    Vector2 aim;
    bool goingRight;
    float lastX;
    float checkXpos;
    float offset;
    float topRotation;

public: 
    Turret(string sprite, vector<string> bulletAnim, float speed, int dmg, Vector2 spawnBullet, bool _lowerTurret);

    void Update() override;
};

