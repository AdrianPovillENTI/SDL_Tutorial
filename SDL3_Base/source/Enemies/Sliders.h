#pragma once
#include "Enemy.h"
//Planchas
class Sliders : public Enemy
{
public:
    Sliders ( string path ) :
        Enemy
        (
        3 , //Speed
        5 , //Health
        1 , //Damage
        path , //Sprite path
        new EnemyBehaviourPattern
        (
        new MultiPhasePattern
        ( {
            { new LinearPattern ( Vector2::Left,0.5f ),speed }
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

