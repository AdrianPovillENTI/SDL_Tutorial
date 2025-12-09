#pragma once
#include "DamageableObject.h"
#include "Animator.h"
#include <string>

class Bullet : public GameObject, public Animator
{
private:
    int damage;
    float speed;

public:
    Bullet(const std::vector<std::string>& _anim, float _speed, int _damage);
    ~Bullet() = default;

    void Start() override;
    void Update() override;

    void SetDamage(int d) { damage = d; }
    int GetDamage() const { return damage; }

    void OnCollision(Object* collided) override;
};