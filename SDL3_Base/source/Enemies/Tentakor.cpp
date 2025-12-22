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
    timeToShoot = 60.f;
    shootCooldown = 1.f;
    bulletSpeed = 2.f;
    bulletDamage = 5;
    lastPosIndex = -1;
    bulletAnimationSprites =
    {
        "resources/Player/NormalShoot/shot_1.png",
        "resources/Player/NormalShoot/shot_2.png",
        "resources/Player/NormalShoot/shot_3.png",
        "resources/Player/NormalShoot/shot_4.png",
        "resources/Player/NormalShoot/shot_5.png",
        "resources/Player/NormalShoot/shot_6.png"
    };
    playOnStart = false;
    LinearPattern * stop = new LinearPattern ( Vector2::Zero , speed );
    bulletSpawnPoints = 
    {
        Vector2 ( 0.f , -150.f ),
        Vector2 ( -100.f , -100.f ),
        Vector2 ( -150.f , -50.f ),
        Vector2 ( -200.f , 0.f ),
        Vector2 ( -150.f , 50.f ),
        Vector2 ( -100.f , 100.f ),
        Vector2 ( 0.f , 150.f )
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
    int randBulletAmount = rand ( ) % 5 + 3;
    for ( int i = 0; i <= randBulletAmount; i++ )
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
    GameObject::Update ( );
    shootCooldown += 1.f / 60.f;
    if ( shootCooldown >= timeToShoot )
    {
        Shoot();
        shootCooldown = 0.f;
    }
}
