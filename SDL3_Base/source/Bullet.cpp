//#include "Bullet.h"
//#include "RenderManager.h"   // por si usas RM
//#include "InputManager.h"    // si hace falta
//
//Bullet::Bullet ( int damage , const Vector2 & position , const Vector2 & direction )
//    : DamageableObject ( 1 , "resources/bullet.png" ) , damage ( damage )
//{
//    _transform->position = position;
//    _physics->SetVelocity ( direction * speed );
//}
//
//Bullet::~Bullet ( ) { }
//
//void Bullet::Update ( )
//{
//    GameObject::Update ( );
//
//    // si quieres que la bala avance sola:
//    // _physics->AddForce(_physics->GetVelocity());
//}
//
//void Bullet::Move ( Vector2 targetPos )
//{
//    Vector2 dir = targetPos - _transform->position;
//    dir.Normalize ( );
//    _physics->AddForce ( dir * speed );
//}