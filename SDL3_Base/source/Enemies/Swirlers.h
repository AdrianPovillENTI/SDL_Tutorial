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
                    {new CheckPointMovementPattern(&_transform->position, movePattern, 0.5f), 120 }
                }) ,
                new ScreenBoundsExit ( 16 )
            ) 
        ) 
    { 
    }
    void Start ( ) override 
    { 
        Enemy::Start ( );
        movePattern.checkpoints = { { (float)SC_WIDTH / 3 , (float)Y }, { (float)X - 100, (float)Y + 100 }, { (float)X + 100,(float)Y + 100 }, { (float)X + 100, (float)Y - 100 }, { (float)X + 100, (float)Y - 100 }, { (float)SC_WIDTH,Y } };
    }
    void Update ( ) override { Enemy::Update ( ); }
    void OnCollision ( Object * collided ) override { Enemy::OnCollision(collided); }
    void Move ( ) override { Enemy::Move ( ); }
};

