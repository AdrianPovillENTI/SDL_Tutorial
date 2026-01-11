#pragma once
#include "GameObject.h"
#include "ICollisionable.h"
#include "Animator.h"
#include <string>
#include <iostream>

class EnemyBullet : public GameObject , public Animator, public ICollisionable
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