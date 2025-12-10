#pragma once
#include "Enemy.h"
#include "../Patterns/MovementPatternData.h"

//EL BOLAS
//POCA VIDA = 1
//Mucha vida = 10
class Swirlers : public Enemy 
{
    MovementPatternData movePattern;
public:
    Swirlers ( ) :
        Enemy
        ( 
            0.5f , //Speed
            1 , //Health
            2, //Damage
            "resources/Player/Player.png" , //Sprite path
            new EnemyBehaviourPattern
            (
                new MultiPhasePattern
                ({
                    { new LinearPattern ( Vector2::Left,0.5f ),120},
                    { new SinusoidalMovementPattern ( Vector2::Left,100,1 ),120 },
                    { new CircularMovementPattern ( 1,false ),120 }
                }) ,
                new ScreenBoundsExit ( 16 )
            ) 
        ) 
    { }
    void Start ( ) override 
    { 
        Enemy::Start ( );
        movePattern =
        {
            { { SC_WIDTH / 3 , Y } , { X - 100, Y + 100 } , { X + 100,Y + 100 } , { X + 100, Y - 100 }, { X + 100, Y - 100 }, {SC_WIDTH,Y}}
        };
    }
    void Update ( ) override { Enemy::Update ( ); }
    void OnCollision ( Object * collided ) override { Enemy::OnCollision(collided); }
    void Move ( ) override { Enemy::Move ( ); }
};

