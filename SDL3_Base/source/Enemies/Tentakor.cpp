#include "Tentakor.h"

Tentakor::Tentakor ()
    : Enemy (
    0 ,  // speed
    100 ,  // health
    5 ,  // damage
    "resources/Player/Player.png"
    )
{

    Start ( );
}

void Tentakor::Start ( )
{
    playOnStart = false;
    LinearPattern * stop = new LinearPattern ( Vector2::Zero , speed );
    bulletSpawnPoints = 
    {
        Vector2 ( 0.f , -45.f ),
        Vector2 ( 0.f , -30.f ),
        Vector2 ( 0.f , -15.f ),
        Vector2 ( 0.f , 0.f ),
        Vector2 ( 0.f , 15.f ),
        Vector2 ( 0.f , 30.f ),
        Vector2 ( 0.f , 45.f )
    };
    pattern = new EnemyBehaviourPattern (
        new MultiPhasePattern 
        ( {
            { stop, 0 }
        } )
    );

    Enemy::Start ( );
}

void Tentakor::Shoot ( )
{ 
    int randBulletAmount = randBulletAmount = rand ( ) % 5 + 3;
    for ( int i = 0; i < randBulletAmount; i++ )
    {
        int randIndex = 0;
        do
        {
            randIndex = rand ( ) % bulletSpawnPoints.size ( );
        }
        while ( lastPosIndex == randIndex );

        EnemyBullet * b = new EnemyBullet ( bulletAnimationSprites , bulletSpeed , bulletDamage );
        b->GetTransform ( )->position = _transform->position + bulletSpawnPoints [ randIndex ];
        lastSpawnPos = bulletSpawnPoints [ randIndex ];
        SPAWNER.SpawnObject ( b );
    }
}

void Tentakor::Update ( )
{
    shootCooldown += 1.f / 60.f;
    if ( shootCooldown >= timeToShoot )
    {
        Shoot();
        shootCooldown = 0.f;
    }
}
