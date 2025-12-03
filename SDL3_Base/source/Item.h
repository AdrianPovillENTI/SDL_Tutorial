//#pragma once
//#include "DamageableObject.h"
//
//class Item : public DamageableObject
//{
//private:
//    int impactCount;
//    int maxImpactCount;
//public:
//    Item ( Transform t ) :
//        DamageableObject ( 1 , "resources/bullet.png" ) ,
//        impactCount ( maxImpactCount );
//    {
//        _transform->position = t.position;
//        _transform->scale = Vector2::One;
//        _transform->rotation = 0.f;
//
//        this->speed = speed;
//    }
//    ~Bullet ( );
//
//    void Start ( ) override
//    {
//    }
//    void Update ( ) override
//    {
//        Object::Update ( );
//        GameObject::Update ( );
//
//        _physics->AddForce ( Vector2 ( 0.25f , 0 ) );
//    }
//    int GetDamage ( ) const { return 1; }
//
//    void Move ( Vector2 targetPos ) override
//    {
//        _physics->AddForce ( Vector2 ( 0.25f , 0 ) );
//    }
//
//};