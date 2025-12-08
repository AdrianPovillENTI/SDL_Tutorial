#pragma once
#include "DamageableObject.h"
#include <string>

class Bullet : public DamageableObject
{
private:
    int damage;
    float speed;

    float frameTime;
    float frameTimeMax;
    int currentFrame;
    std::vector<string> animationFrames;

public:
    Bullet(const string path);
    ~Bullet();

    void Start() override;
    void Update() override;
    void ChangeSpriteFrame();
    void Move() override;

    void SetDamage(int d) { damage = d; }
    int GetDamage() const { return damage; }
    void SetAnimationSprites ( vector<string> & animationFrames );
};