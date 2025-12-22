#pragma once
#include "DamageableObject.h"
#include "Animator.h"
#include <string>
#include <iostream>

class EnemyBullet : public GameObject , public Animator
{
private:
    int damage;
    float speed;

public:
    EnemyBullet ( const std::vector<std::string> & _anim , float _speed , int _damage );
    ~EnemyBullet ( ) = default;

    void Start ( ) override;
    void Update ( ) override;

    void SetDamage ( int d ) { damage = d; }
    int GetDamage ( ) const { return damage; }

    void OnCollision ( Object * collided ) override;
};