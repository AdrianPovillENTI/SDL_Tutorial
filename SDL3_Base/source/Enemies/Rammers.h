#pragma once
#include "Enemy.h"
//Dron
class Rammers : public Enemy
{
public:
    Rammers ( string path ) :
        Enemy
        (
        2 , //Speed
        17 , //Health
        4 , //Damage
        path , //Sprite path
        new EnemyBehaviourPattern
        (
        new MultiPhasePattern
        ( {
            { new LinearPattern ( Vector2::Left,speed ),2 }
        } ) 
        )
        )
    {
    }
    void Start ( ) override { Enemy::Start ( ); }
    void Update ( ) override { Enemy::Update ( ); }
    void OnCollision ( Object * collided ) override { Enemy::OnCollision ( collided ); }
    void Move ( ) override { Enemy::Move ( ); }

};

