#pragma once
#include "Enemy.h"

//WAZOWSKI
class Charger : public Enemy
{
public:
    Charger ( string path ) :
        Enemy
        (
        0.5f , //Speed
        1 , //Health
        1 , //Damage
        path , //Sprite path
        new EnemyBehaviourPattern
        (
        new MultiPhasePattern
        ( {
            { new LinearPattern ( Vector2::Left,0.5f ),2 }
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

