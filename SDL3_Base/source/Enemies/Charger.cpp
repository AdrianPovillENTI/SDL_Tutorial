#include "Charger.h"

Charger::Charger ( )
    : Enemy (
    3 ,
    8 ,
    1 ,
    "resources/Enemies/Imagen4.png"
    )
{
}

Vector2 Charger::DirectionToPlayer ( )
{
    const float margin = 100.f;

    float minX = margin;
    float maxX = SC_WIDTH - margin;
    float minY = margin;
    float maxY = SC_HEIGHT - margin;

    Vector2 target;

    if ( X < margin ) target.x = maxX;
    else if ( X > SC_WIDTH - margin ) target.x = minX;
    else target.x = minX + ( rand ( ) / ( float ) RAND_MAX ) * ( maxX - minX );

    if ( Y < margin ) target.y = maxY;
    else if ( Y > SC_HEIGHT - margin ) target.y = minY;
    else target.y = minY + ( rand ( ) / ( float ) RAND_MAX ) * ( maxY - minY );

    return target;
}

Vector2 Charger::DirectionToTarget ( )
{
    Vector2 dir = targetPoint - _transform->position;

    if ( dir.Magnitude ( ) < 1.f )
        return Vector2::Zero;

    return dir.Normalized ( );
}

void Charger::CreatePattern ( const Vector2 & dir )
{
    delete pattern;
    pattern = nullptr;

    pattern = new EnemyBehaviourPattern (
        new LinearPattern ( dir , speed )
    );
}

void Charger::Start ( )
{
    playOnStart = true;
    isMoving = true;
    phaseTimer = 0.f;

    moveTime = 5.0f + ( rand ( ) % 40 ) / 10.f;
    stopTime = 1.0f + ( rand ( ) % 20 ) / 10.f;

    targetPoint = DirectionToPlayer ( );
    CreatePattern ( DirectionToTarget ( ) );

    Enemy::Start ( );
}

void Charger::Move ( )
{
    if ( !pattern ) return;

    float dt = 1.f / 60.f;
    phaseTimer += dt;

    Enemy::Move ( );

    float distToTarget =
        Vector2::Distance ( _transform->position , targetPoint );

    if ( isMoving && distToTarget < 20.f )
    {
        isMoving = false;
        phaseTimer = 0.f;
        stopTime = 1.0f + ( rand ( ) % 20 ) / 10.f;
        CreatePattern ( Vector2::Zero );
        return;
    }

    if ( isMoving && phaseTimer >= moveTime )
    {
        isMoving = false;
        phaseTimer = 0.f;
        stopTime = 1.0f + ( rand ( ) % 20 ) / 10.f;
        CreatePattern ( Vector2::Zero );
    }
    else if ( !isMoving && phaseTimer >= stopTime )
    {
        isMoving = true;
        phaseTimer = 0.f;
        moveTime = 5.0f + ( rand ( ) % 40 ) / 10.f;

        targetPoint = DirectionToPlayer ( );
        CreatePattern ( DirectionToTarget ( ) );
    }
}