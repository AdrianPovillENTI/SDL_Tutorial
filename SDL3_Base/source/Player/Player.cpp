#include "Player.h"

#include "Gun/Bullet.h"

#include "../InputManager.h"
#include "../RenderManager.h"
#include "../UI/UIManager.h"

Player::Player ( int maxHealth )
    : DamageableObject ( maxHealth , "resources/Player/Player.png" )
{
    Start ( );
}
Player::~Player ( )
{
    if ( cannon )
    {
        RemoveChild ( cannon );
        cannon->Destroy();
        cannon = nullptr;
    }

    if ( laser )
    {
        RemoveChild ( laser );
        laser->Destroy();
        laser = nullptr;
    }

    for ( Turret * t : turrets )
    {
        if ( t )
        {
            RemoveChild ( t );
            t->Destroy();
        }
    }
    turrets.clear ( );
}
void Player::Start ( )
{
    InitializeStats();
    InitializeGuns();
    InitializePhysics();
    healthManager.onShieldChanged = [](int hp, int maxHp)
    {
        UIM->UpdateShield(hp, maxHp);
    };

    healthManager.onLifesChanged = [](int lifes)
    {
        UIM->UpdateLifes(lifes);
    };

    healthManager.onDeath = [this]()
    {
        Destroy();
    };

    healthManager.Init(maxHealth, 3);
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

void Player::ReceiveDamage(int dmg) { healthManager.ReceiveDamage(dmg); }

void Player::InitializeStats()
{
    _transform->position = Vector2(100.f, RM->WINDOW_HEIGHT / 2.f);
    _transform->size = Vector2(100.f, 50.f);
    _transform->rotation = 0.f;

    score = 0;

    canShoot = true;
    shootCooldown = 0.f;
    maxShootCooldownTime = 5;

    speedUpgrade = 2.5f;
    speed = 50.0f;
}

void Player::InitializeGuns() 
{
    // Main Gun 

    std::vector<std::string> bulletSprites =
    {
        "resources/Player/NormalShoot/shot_1.png",
        "resources/Player/NormalShoot/shot_2.png",
        "resources/Player/NormalShoot/shot_3.png",
        "resources/Player/NormalShoot/shot_4.png",
        "resources/Player/NormalShoot/shot_5.png",
        "resources/Player/NormalShoot/shot_6.png"
    };
    const int bulletDamage = 10;
    const float bulletSpeed = 40.f;
    Vector2 bulletSpawnPoint = Vector2(75.f, 0.f);

    primaryGun = new Gun("resources/Player/Player.png", bulletSprites, bulletSpeed, bulletDamage, bulletSpawnPoint);
    AddChild(primaryGun, Vector2::Zero);
    SPAWNER.SpawnObject(primaryGun);
    primaryGun->SetActive(true);

    // Laser Gun

    vector<string> laserBulletAnim = {
        "resources/Player/Laser/shot_1.png",
        "resources/Player/Laser/shot_2.png",
        "resources/Player/Laser/shot_3.png",
        "resources/Player/Laser/shot_4.png"
    };
    string laserSprite = "resources/Player/LaserSprite.png";
    Vector2 laserBulletSpawnPoint = Vector2(55.f, -20.f);

    laser = new AmmoGun(laserSprite, laserBulletAnim, 60, 15, 50,laserBulletSpawnPoint); 
    AddChild(laser, Vector2::Zero);
    SPAWNER.SpawnObject(laser);

    laser->onAmmoChanged = [](int _ammo, int _maxAmmo)
    {
        UIM->UpdateLaserAmmo(_ammo, _maxAmmo);
    };

    // Cannon Gun

    vector<string> cannonBulletAnim = {
         "resources/Player/Cannon/shot_1.png",
        "resources/Player/Cannon/shot_2.png",
        "resources/Player/Cannon/shot_3.png",
        "resources/Player/Cannon/shot_4.png"
    };
    string cannonSprite = "resources/Player/CannonSprite.png";
    Vector2 cannonBulletSpawnPoint = Vector2(30.f, 35.f);

    cannon = new AmmoGun(cannonSprite, cannonBulletAnim, 30, 30, 10, cannonBulletSpawnPoint);
    AddChild(cannon, Vector2::Zero);
    SPAWNER.SpawnObject(cannon);

    cannon->onAmmoChanged = [](int _ammo, int _maxAmmo)
    {
        UIM->UpdateCannonAmmo(_ammo, _maxAmmo);
    };

    // Turrets Gun

    string turretSprite = "resources/Player/TomasTurretlina.png";
    Vector2 turretsBulletSpawnPoint = Vector2(0.f, 0.f);;

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
}

void Player::Update ( )
{
    if (IsPendingDestroy()) return;

    const float dt = 1.f / 60.f;

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

    healthManager.Update(dt);
}

void Player::Shoot ( )
{
    if (!canShoot) return;

    primaryGun->Shoot();    

    if (cannon->GetActive())
        cannon->Shoot();

    if (laser->GetActive())
        laser->Shoot();

    if (turrets[0]->GetActive())
    {
        turrets[0]->Shoot();
        if (turrets[1]->GetActive())
            turrets[1]->Shoot();
    }

    canShoot = false;
    shootCooldown = maxShootCooldownTime;
}

void Player::SetCannon() {

    cannon->ResetAmmo();
    if (!cannon->GetActive())
        cannon->SetActive(true);
}

void Player::SetLaser() {

    laser->ResetAmmo();
    if (!laser->GetActive())
        laser->SetActive(true);
}

void Player::SetSpeedUpgrade() {
    speed += speedUpgrade;
}

void Player::SetTurret() {
    if (!turrets[1]->GetActive())
        if (turrets[0]->GetActive())
            turrets[1]->SetActive(true);
        else
            turrets[0]->SetActive(true);
}

void Player::SetInvincible() { healthManager.SetInvincible(10.0f); }
void Player::FillShield() { healthManager.FillShield(); }
bool Player::GetInvencibleStatus ( ) { return healthManager.IsInvincible(); }

void Player::ClampInsideScreen ( )
{
    Vector2 & pos = _transform->position;
    pos = Vector2::ClampVectorX ( pos , 0.f , RM->WINDOW_WIDTH * 1.4f);
    pos = Vector2::ClampVectorY ( pos , 0.f , RM->WINDOW_HEIGHT * 1.3f);
}

void Player::OnCollision(Object* collided)
{

}