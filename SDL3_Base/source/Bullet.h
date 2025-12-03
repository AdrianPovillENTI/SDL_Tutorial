#pragma once
#include "DamageableObject.h"

class Bullet : public DamageableObject
{
private:
    int damage;
    float speed = 1;
public:
    Bullet ( Transform t): 
        DamageableObject ( 1 , "resources/bullet.png" ),
        damage ( 5 ),
        speed ( 0.5f )  
    {
        _transform->position = t.position;
        _transform->scale = Vector2::One;
        _transform->rotation = 0.f;

        this->speed = speed;
    }
    ~Bullet ( );

    void Start ( ) override
    {
    }
    void Update ( ) override
    {
        if ( !active ) return;
        Object::Update ( );
        GameObject::Update ( );

        if ( _transform->position.x > RM->WINDOW_WIDTH ) SetActive ( false );
            Destroy();
        _physics->AddForce ( Vector2 ( 0.25f , 0 ) );
    }
    int GetDamage ( ) const { return damage; }

    void Move ( Vector2 targetPos ) override
    { 
        _physics->AddForce ( Vector2 ( 0.25f , 0 ) );
    }

};