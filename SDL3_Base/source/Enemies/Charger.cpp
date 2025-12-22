#include "Charger.h"

Charger::Charger ( )
    : Enemy (
    1.8f ,  // Speed
    3 ,     // Health
    1 ,     // Damage
    "resources/Player/Player.png"
    )
{
}

Vector2 Charger::ChooseDirection ( )
{
    if ( Y < 80.f ) return Vector2::Down;
    if ( Y > SC_HEIGHT - 80.f ) return Vector2::Up;
    if ( X < 80.f ) return Vector2::Right;
    if ( X > SC_WIDTH - 80.f ) return Vector2::Left;

    int r = rand ( ) % 4;
    if ( r == 0 ) return Vector2::Up;
    if ( r == 1 ) return Vector2::Down;
    if ( r == 2 ) return Vector2::Left;
    return Vector2::Right;
}

void Charger::CreatePattern ( Vector2 dir )
{
    delete pattern;
    pattern = nullptr;

    LinearPattern * move = new LinearPattern ( dir , speed );
    LinearPattern * stop = new LinearPattern ( Vector2::Zero , 0.f );

    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern ( {
            { move, moveTime * 60.f },
            { stop, stopTime * 60.f }
        } )
    );
}

void Charger::Start ( )
{
    playOnStart = true;
    isMoving = true;
    phaseTimer = 0.f;

    Vector2 dir = ChooseDirection ( );
    CreatePattern ( dir );

    Enemy::Start ( );
}

void Charger::Move ( )
{
    if ( !pattern ) return;

    float dt = 1.f / 15.f;
    phaseTimer += dt;

    Enemy::Move ( );

    if ( isMoving && phaseTimer >= moveTime )
    {
        isMoving = false;
        phaseTimer = 0.f;
    }
    else if ( !isMoving && phaseTimer >= stopTime )
    {
        Vector2 newDir = ChooseDirection ( );
        CreatePattern ( newDir );

        isMoving = true;
        phaseTimer = 0.f;
    }
}