#include "Player.h"

#include "Spawner.h"
#include "Item.h"
#include "Score.h"
#include "Cannon.h"
#include "Laser.h"
#include "SpeedUpgrade.h"
#include "Turret.h"
#include "ForceField.h"
#include "Shield.h"
#include "Bullet.h"

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
    _transform->position = Vector2 ( 100.f , RM->WINDOW_HEIGHT / 2.f );
    _transform->scale = Vector2::One;
    _transform->rotation = 0.f;

    invencible = false;
    invencibleTime = 0.f;
    isDeath = false;

    canShoot = true;
    shootCooldown = 0.f;
    maxShootCooldownTime = 30;
    originalMaxShootCooldownTime = maxShootCooldownTime;

    bulletSprite = "resources/Player/NormalShoot/shot5_1.png";
    bulletDamage = 10;
    originalDamage = bulletDamage;

    speed = 1.0f;
    shotSpeed = 1.0f;

    inventory.clear ( );

    if ( _physics != nullptr )
    {
        _physics->SetLinearDrag ( 0.1f );
        _physics->SetAngularDrag ( 0.1f );
    }
}

void Player::Move ( )
{
    if ( IM->GetEvent ( SDLK_S , DOWN ) || IM->GetEvent ( SDLK_S , HOLD ) )
        _physics->AddForce ( Vector2 ( 0 , 0.5f ) );

    if ( IM->GetEvent ( SDLK_W , DOWN ) || IM->GetEvent ( SDLK_W , HOLD ) )
        _physics->AddForce ( Vector2 ( 0 , -0.5f ) );

    if ( IM->GetEvent ( SDLK_D , DOWN ) || IM->GetEvent ( SDLK_D , HOLD ) )
        _physics->AddForce ( Vector2 ( 0.5f , 0 ) );

    if ( IM->GetEvent ( SDLK_A , DOWN ) || IM->GetEvent ( SDLK_A , HOLD ) )
        _physics->AddForce ( Vector2 ( -0.5f , 0 ) );
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
    if ( !canShoot ) return;

    Bullet * bullet = new Bullet ( bulletSprite );
    bullet->GetTransform ( )->position = _transform->position + offset;

    SPAWNER.SpawnObject ( bullet );

    canShoot = false;
    shootCooldown = maxShootCooldownTime;
}

void Player::SetShootSpeed ( )
{
    for ( Item * item : inventory )
    {
        if ( !item ) continue;

        switch ( item->GetType ( ) )
        {
            case Item::SCORE:
                // Score ++
                break;

            case Item::CANNON:
            {
                Cannon * cannon = dynamic_cast< Cannon * >( item );
                bulletDamage += cannon->GetDamageMultiplier ( );
                shotSpeed += cannon->GetSpeedMultiplier ( );
                maxShootCooldownTime = originalMaxShootCooldownTime / shotSpeed;
                break;
            }

            case Item::LASER:
            {
                Laser * laser = dynamic_cast< Laser * >( item );
                bulletDamage += laser->GetDamageMultiplier ( );
                shotSpeed += laser->GetSpeedMultiplier ( );
                maxShootCooldownTime = originalMaxShootCooldownTime / shotSpeed;
                break;
            }

            case Item::SPEED_UPGRADE:
            {
                SpeedUpgrade * speedUp = dynamic_cast< SpeedUpgrade * >( item );
                shotSpeed += speedUp->GetSpeedMultiplier ( );
                break;
            }

            case Item::TURRET:
            {
                Turret * turret = dynamic_cast< Turret * >( item );
                bulletDamage += turret->GetDamageMultiplier ( );
                shotSpeed += turret->GetSpeedMultiplier ( );
                maxShootCooldownTime = originalMaxShootCooldownTime / shotSpeed;
                break;
            }

            case Item::FORCEFIELD:
            {
                ForceField * ff = dynamic_cast< ForceField * >( item );
                invencible = true;
                invencibleTime = ff->GetDuration ( );
                break;
            }

            case Item::SHIELD:
            {
                Shield * shield = dynamic_cast< Shield * >( item );
                health += shield->GetHealthBonus ( );
                if ( health > maxHealth ) health = maxHealth;
                break;
            }

            default:
                break;
        }
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