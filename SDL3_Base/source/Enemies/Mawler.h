#pragma once
#include "Enemy.h"
//BOCAXANCLUS PATRONUS
class Mawler : public Enemy
{
public:
    Mawler ( string path ) :
        Enemy
        (
        0.5f , //Speed
        5 , //Health
        1 , //Damage
        path , //Sprite path
        new EnemyBehaviourPattern
        (
        new MultiPhasePattern
        ( {
            { new LinearPattern ( Vector2::Left,0.5f ),2 }
        } ) ,
        new ScreenBoundsExit ( 16 )
        )
        )
    {
    }
    void Start ( ) override { Enemy::Start ( ); }
    void Update ( ) override { Enemy::Update ( ); }
    void OnCollision ( Object * collided ) override { Enemy::OnCollision ( collided ); }
    void Move ( ) override { Enemy::Move ( ); }

};

