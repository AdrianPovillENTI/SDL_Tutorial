#pragma once
#include "ICollisionable.h"
#include "GameObject.h"
#include "Animator.h"
#include <string>

class Bullet : public GameObject, public Animator, public ICollisionable
{
private:
    int damage;
    float speed;
    Vector2 dir;

public:
    Bullet(const std::vector<std::string>& _anim, float _speed, int _damage, Vector2 _dir = Vector2::Right);
    ~Bullet() = default;

    void Start() override;
    void Update() override;

    void SetDamage(int d) { damage = d; }
    int GetDamage() const { return damage; }

    void OnCollision(Object* collided) override;
};