#pragma once
#include "Enemy.h"

//VICHAKO VERDAKO GORDAKO
class Gulper : public Enemy
{
public:
    Gulper ( string path ) :
        Enemy
        (
        0.5f , //Speed
        10 , //Health
        2 , //Damage
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
    void Start ( ) override { Enemy::Start; }
    void Update ( ) override { Enemy::Update; }
    void OnCollision ( Object * collided ) override { Enemy::OnCollision ( collided ); }
    void Move ( ) override { Enemy::Move ( ); }

};

