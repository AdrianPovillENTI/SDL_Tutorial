#include "Player.h"

#include "Spawner.h"
#include "Item.h"
#include "SpeedUpgrade.h"
#include "Bullet.h"
#include "SpeedVfx.h"

#include "InputManager.h"
#include "RenderManager.h"

Player::Player ( int maxHealth )
    : DamageableObject ( maxHealth , "resources/Player/Player.png" ) ,
    offset ( Vector2 ( 75.f , 0.f ) )
{
    Start ( );
}

Player::~Player ( )
{
}

void Player::Start ( )
{
    InitializeStats();
    InitializeGuns();
    InitializePhysics();
}

void Player::InitializePhysics() 
{
    if ( _physics != nullptr )
    {
        _physics->SetLinearDrag ( 0.1f );
        _physics->SetAngularDrag ( 0.1f );
    }
}

void Player::InitializeStats()
{

    _transform->position = Vector2(100.f, RM->WINDOW_HEIGHT / 2.f);
    _transform->scale = Vector2::One;
    _transform->rotation = 0.f;

    invencible = false;
    invencibleTime = 0.f;
    isDeath = false;

    canShoot = true;
    shootCooldown = 0.f;
    maxShootCooldownTime = 30;

    bulletSprites = { "resources/Player/NormalShoot/shot_1.png" };
    bulletDamage = 10;
    bulletSpeed = 5;
    originalDamage = bulletDamage;
    speedUpgrade = 2.5f;
}

void Player::InitializeGuns() 
{
    laserAnim = {
        "resources/Player/Laser/shot_1.png",
        "resources/Player/Laser/shot_2.png",
        "resources/Player/Laser/shot_3.png",
        "resources/Player/Laser/shot_4.png"
    };
    cannonAnim = {
         "resources/Player/Cannon/shot_1.png",
        "resources/Player/Cannon/shot_2.png",
        "resources/Player/Cannon/shot_3.png",
        "resources/Player/Cannon/shot_4.png"
    };

    speed = 1.0f;
    shotSpeed = 1.0f;

    inventory.clear();

    cannonPos = Vector2(0.5f, 0.5f);
    laserPos = Vector2(0.5f, 0.5f);
    turretsPos = Vector2(-0.5f, 0.5f);

    cannon = new AmmoGun(cannonAnim, 3, 0.3, 5, cannonPos);
    laser = new AmmoGun(laserAnim, 10, 0.1, 2, laserPos); 
    turrets = { new Turret(turretAnim, bulletSpeed, maxShootCooldownTime, bulletDamage, turretsPos),
        new Turret(turretAnim, bulletSpeed, maxShootCooldownTime, bulletDamage, turretsPos + Vector2(0, -1)) };
}

void Player::Move ( )
{
    isMoving = false;

    if ( IM->GetEvent ( SDLK_S , DOWN ) || IM->GetEvent ( SDLK_S , HOLD ) )
    {
        _physics->AddForce ( Vector2 ( 0 , 0.5f ) );
        isMoving = true;
    }

    if ( IM->GetEvent ( SDLK_W , DOWN ) || IM->GetEvent ( SDLK_W , HOLD ) )
    {
        _physics->AddForce ( Vector2 ( 0 , -0.5f ) );
        isMoving = true;
    }

    if ( IM->GetEvent ( SDLK_D , DOWN ) || IM->GetEvent ( SDLK_D , HOLD ) )
    {
        _physics->AddForce ( Vector2 ( 0.5f , 0 ) );
        isMoving = true;
    }

    if ( IM->GetEvent ( SDLK_A , DOWN ) || IM->GetEvent ( SDLK_A , HOLD ) )
    {
        _physics->AddForce ( Vector2 ( -0.5f , 0 ) );
        isMoving = true;
    }

    if ( isMoving && speedVfx == nullptr )
    {
        //speedVfx = new SpeedVfx ( );
        AddChild ( speedVfx , Vector2 ( -80.0f , 10.0f ) );
        SPAWNER.SpawnObject ( speedVfx );
        turboActivated = true;
    }

    if ( !isMoving && speedVfx != nullptr )
    {
        RemoveChild ( speedVfx );
        speedVfx->Destroy ( );
        speedVfx = nullptr;
        turboActivated = false;
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
        invencibleTime -= 1.f / 60.f;
        if ( invencibleTime <= 0 )
            invencible = false;
    }

    if ( health <= 0 && !isDeath )
    {
        isDeath = true;
        Destroy ( );
    }
}

void Player::Shoot ( )
{
    if (cannon->GetActive())
        cannon->Shoot();
    if (laser->GetActive())
        laser->Shoot();

    if (!canShoot) return;
    Bullet * bullet = new Bullet ( bulletSprites, bulletSpeed, bulletDamage);
    bullet->GetTransform ( )->position = _transform->position + offset;

    SPAWNER.SpawnObject ( bullet );

    canShoot = false;
    shootCooldown = maxShootCooldownTime;
}

void Player::ApplyItemEffects (Item* item)
{
    switch ( item->GetType ( ) )
    {
        case Item::SCORE:
            // Score ++
            break;

        case Item::CANNON:
        {
            if (cannon->GetActive())
                cannon->ResetAmmo();
            else
                cannon->SetActive(true);

            break;
        }

        case Item::LASER:
        {
            if (laser->GetActive())
                laser->ResetAmmo();
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
            invencibleTime = 5;
            break;
        }

        case Item::SHIELD:
        {
            health = maxHealth;
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
    if (Item* item = dynamic_cast<Item*>(collided))
    {
        ApplyItemEffects(item);
        collided->Destroy();
    }

}