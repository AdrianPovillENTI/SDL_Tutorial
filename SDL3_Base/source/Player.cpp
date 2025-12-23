#include "Player.h"

#include "Spawner.h"
#include "Item.h"
#include "Bullet.h"
#include "SpeedVfx.h"

#include "InputManager.h"
#include "RenderManager.h"
#include "UI/UIManager.h"

Player::Player ( int maxHealth )
    : DamageableObject ( maxHealth , "resources/Player/Player.png" ) ,
    bulletSpawnPoint ( Vector2 ( 75.f , 0.f ) )
{
    Start ( );
}
Player::~Player ( )
{
    if ( speedVfx )
    {
        RemoveChild ( speedVfx );
        delete speedVfx;
        speedVfx = nullptr;
    }

    if ( cannon )
    {
        RemoveChild ( cannon );
        delete cannon;
        cannon = nullptr;
    }

    if ( laser )
    {
        RemoveChild ( laser );
        delete laser;
        laser = nullptr;
    }

    for ( Turret * t : turrets )
    {
        if ( t )
        {
            RemoveChild ( t );
            delete t;
        }
    }
    turrets.clear ( );
}
void Player::Start ( )
{
    InitializeStats();
    InitializeGuns();
    InitializePhysics();
    onReceiveDamage = [this]() 
    {
        if(!invencible )
        {
            invencible = true;
            invencibleTime = 10.0f;
        }
    };
}

void Player::InitializePhysics() 
{
    if ( _physics != nullptr )
    {
        _physics->AddCollider(new AABB(_transform->position, Vector2(_transform->size.x, _transform->size.y/2)));
        _physics->SetLinearDrag ( 1.f );
        _physics->SetAngularDrag (1.f );
    }
}

void Player::ReceiveDamage ( int _health )
{
    if ( invencible ) return;

    health -= _health;
    if ( onReceiveDamage != nullptr ) onReceiveDamage ( );
    std::cout << "Received damage: " << _health << " | Current health: " << health << std::endl;

    UIM->UpdateShield(health, maxHealth);

    if (health <= 0 && lifes > 0)
    {
        lifes--;
        health = maxHealth;
        UIM->UpdateShield(health, maxHealth);
        UIM->UpdateLifes(lifes);
    }
}

void Player::InitializeStats()
{

    _transform->position = Vector2(100.f, RM->WINDOW_HEIGHT / 2.f);
    _transform->size = Vector2(100.f, 50.f);
    _transform->rotation = 0.f;

    score = 0;
    lifes = 3;

    invencible = false;
    invencibleTime = 0.f;
    isDeath = false;

    canShoot = true;
    shootCooldown = 0.f;
    maxShootCooldownTime = 5;

    bulletSprites = 
    { 
        "resources/Player/NormalShoot/shot_1.png",
        "resources/Player/NormalShoot/shot_2.png",
        "resources/Player/NormalShoot/shot_3.png",
        "resources/Player/NormalShoot/shot_4.png",
        "resources/Player/NormalShoot/shot_5.png",
        "resources/Player/NormalShoot/shot_6.png"
    };
    bulletDamage = 10;
    bulletSpeed = 40;
    speedUpgrade = 2.5f;
    speed = 50.0f;
}

void Player::InitializeGuns() 
{
    laserBulletAnim = {
        "resources/Player/Laser/shot_1.png",
        "resources/Player/Laser/shot_2.png",
        "resources/Player/Laser/shot_3.png",
        "resources/Player/Laser/shot_4.png"
    };
    laserSprite = "resources/Player/LaserSprite.png";
    cannonBulletAnim = {
         "resources/Player/Cannon/shot_1.png",
        "resources/Player/Cannon/shot_2.png",
        "resources/Player/Cannon/shot_3.png",
        "resources/Player/Cannon/shot_4.png"
    };
    cannonSprite = "resources/Player/CannonSprite.png";

    turretSprite = "resources/Player/TomasTurretlina.png";


    cannonBulletSpawnPoint = Vector2(30.f, 35.f);
    laserBulletSpawnPoint = Vector2(55.f, -20.f);
    turretsBulletSpawnPoint = Vector2(-0.5f, 0.5f);

    cannon = new AmmoGun(cannonSprite, cannonBulletAnim, 10, 5, 10, cannonBulletSpawnPoint);
    AddChild(cannon, Vector2::Zero);
    SPAWNER.SpawnObject(cannon);

    laser = new AmmoGun(laserSprite, laserBulletAnim, 50, 2, 50,laserBulletSpawnPoint); 
    AddChild(laser, Vector2::Zero);
    SPAWNER.SpawnObject(laser);

    turrets = { new Turret(turretSprite, bulletSprites, bulletSpeed, bulletDamage, turretsBulletSpawnPoint, false),
       new Turret(turretSprite, bulletSprites, bulletSpeed, bulletDamage, turretsBulletSpawnPoint + Vector2(0, -1), true)};
    AddChild(turrets[0], Vector2(-55.f, -35.f));
    AddChild(turrets[1], Vector2(-55.f, 35.f));
    SPAWNER.SpawnObject(turrets[0]);
    SPAWNER.SpawnObject(turrets[1]);
}

void Player::Move ( )
{
    isMoving = false;

    if ( IM->GetEvent ( SDLK_S , DOWN ) || IM->GetEvent ( SDLK_S , HOLD ) )
    {
        _physics->AddForce ( Vector2 ( 0 , 0.5f ) * speed );
        isMoving = true;
    }

    if ( IM->GetEvent ( SDLK_W , DOWN ) || IM->GetEvent ( SDLK_W , HOLD ) )
    {
        _physics->AddForce ( Vector2 ( 0 , -0.5f ) * speed);
        isMoving = true;
    }

    if ( IM->GetEvent ( SDLK_D , DOWN ) || IM->GetEvent ( SDLK_D , HOLD ) )
    {
        _physics->AddForce ( Vector2 ( 0.5f , 0 ) * speed);
        isMoving = true;
    }

    if ( IM->GetEvent ( SDLK_A , DOWN ) || IM->GetEvent ( SDLK_A , HOLD ) )
    {
        _physics->AddForce ( Vector2 ( -0.5f , 0 ) * speed);
        isMoving = true;
    }

    if ( isMoving && speedVfx == nullptr )
    {
        speedVfx = new SpeedVfx ( );
        AddChild ( speedVfx , Vector2 ( -80.0f , 10.0f ) );
        SPAWNER.SpawnObject ( speedVfx );
    }

    if ( !isMoving && speedVfx != nullptr )
    {
        RemoveChild ( speedVfx );
        speedVfx->Destroy ( );
        speedVfx = nullptr;
    }
    if ( speedVfx != nullptr ) speedVfx->Update ( );
}

void Player::Update ( )
{
    GameObject::Update ( );

    Move ( );
    ClampInsideScreen ( );

    if ( IM->GetLeftClick() ) Shoot ( );

    // cooldown
    if ( !canShoot )
    {
        shootCooldown -= 1.f / 60.f;
        if ( shootCooldown <= 0.f )
        {
            canShoot = true;
            shootCooldown = 0.f;
        }
    }

    if ( invencible )
    {
        invencibleTime -= 1.f / 30.f;
        if ( invencibleTime <= 0 )
            invencible = false;
    }

    if (lifes <= 0)
    {
            isDeath = true;
            Destroy ( );
    }
}

void Player::Shoot ( )
{
    if (!canShoot) return;

    Bullet * bullet = new Bullet ( bulletSprites, bulletSpeed, bulletDamage);
    bullet->GetTransform ( )->position = _transform->position + bulletSpawnPoint;

    SPAWNER.SpawnObject ( bullet );

    if (cannon->GetActive())
    {
        cannon->Shoot();
        UIM->UpdateCannonAmmo(cannon->GetAmmo(), cannon->GetMaxAmmo());
    }
    if (laser->GetActive())
    {
        laser->Shoot();
        UIM->UpdateLaserAmmo(laser->GetAmmo(), laser->GetMaxAmmo());
    }
    if (turrets[0]->GetActive())
    {
        turrets[0]->Shoot();
        if (turrets[1]->GetActive())
            turrets[1]->Shoot();
    }

    canShoot = false;
    shootCooldown = maxShootCooldownTime;
}

void Player::ApplyItemEffects (Item* item)
{
    switch ( item->GetType ( ) )
    {
        case Item::SCORE:
            score += 1000;
            UIM->UpdateScore(score);
            break;

        case Item::CANNON:
        {
            if (cannon->GetActive())
            {
                cannon->ResetAmmo();
                UIM->UpdateCannonAmmo(cannon->GetMaxAmmo(), cannon->GetMaxAmmo());
            }
            else
                cannon->SetActive(true);

            break;
        }

        case Item::LASER:
        {
            if (laser->GetActive())
            {
                laser->ResetAmmo();
                UIM->UpdateLaserAmmo(laser->GetMaxAmmo(), laser->GetMaxAmmo());
            }
            else
                laser->SetActive(true);
            break;
        }

        case Item::SPEED_UPGRADE:
        {
            speed += speedUpgrade;
            break;
        }

        case Item::TURRET:
        {
            cout << "geting turret" << endl;
            if (!turrets[1]->GetActive())
                if (turrets[0]->GetActive())
                    turrets[1]->SetActive(true);
                else
                    turrets[0]->SetActive(true);
            break;
        }

        case Item::FORCEFIELD:
        {
            invencible = true;
            invencibleTime = 200;
            break;
        }

        case Item::SHIELD:
        {
            health = maxHealth;
            UIM->UpdateShield(health, maxHealth);
            break;
        }

        default:
            break;
    }
}

bool Player::GetInvencibleStatus ( )
{
    return invencible;
}

void Player::ClampInsideScreen ( )
{
    Vector2 & pos = _transform->position;
    pos = Vector2::ClampVectorX ( pos , 0.f , RM->WINDOW_WIDTH * 1.4f);
    pos = Vector2::ClampVectorY ( pos , 0.f , RM->WINDOW_HEIGHT * 1.3f);
}

void Player::OnCollision(Object* collided)
{

}