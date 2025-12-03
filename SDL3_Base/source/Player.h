#pragma once
#include "DamageableObject.h"
#include "Spawner.h"
#include "Bullet.h"

class Player : public DamageableObject
{
public:
    static const int maxEquippedItem = 3;
private:
    bool invencible;
    float invencibleTime;
    bool canShoot;
    float shootCooldown;
    float maxShootCooldownTime;
    int bulletDamage;
    bool isDeath;
    //vector<Item *> inventory;
public:
    vector<Bullet *> bullets;
    Player(int maxHealth) : DamageableObject(maxHealth, "resources/xd.png")
    {
        _transform->position = Vector2 ( RM->WINDOW_WIDTH / 2.0f , RM->WINDOW_HEIGHT / 2.0f );
        canShoot = true;
        invencible = false;
        invencibleTime = 0.0f;
        maxShootCooldownTime = 30; //0.5f segundos ya que 1/60 es igual a 1 cada 60 frames
        shootCooldown = 0.0f;
        bulletDamage = 10;
        isDeath = false;
        for ( int i = 0; i < 10; i++ )
        {
            Bullet * b = new Bullet ( *_transform );
            bullets.push_back ( b);
            b->Start ( );
            b->SetActive ( false );
        }
    }
    ~Player() { }
    void Move(Vector2 targetPos) override
    {
        Vector2 direction = targetPos - _transform->position;
        direction.Normalize();
        _physics->AddForce(direction * 0.1f);
    }
    void Start ( ) override
    {
        _transform->position = Vector2 ( RM->WINDOW_WIDTH / 3.f , RM->WINDOW_HEIGHT / 3.f );
        _transform->scale = Vector2::One;
        _transform->rotation = 0.f;
    }
    void Update() override
    {
        GameObject::Update ( );
        if ( IM->GetEvent ( SDLK_S , DOWN ) || IM->GetEvent ( SDLK_S , HOLD ) )
        {
            _physics->AddForce ( Vector2 ( 0.f , 0.5f ) );
        }
        else if ( IM->GetEvent ( SDLK_W , DOWN ) || IM->GetEvent ( SDLK_W , HOLD ) )
        {
            _physics->AddForce ( Vector2 ( 0.f , -0.5f ) );
        }
        else if ( IM->GetEvent ( SDLK_D , DOWN ) || IM->GetEvent ( SDLK_D , HOLD ) )
        {
            _physics->AddForce ( Vector2 ( 0.5f , 0 ) );
        }
        else if ( IM->GetEvent ( SDLK_A , DOWN ) || IM->GetEvent ( SDLK_A , HOLD ) )
        {
            _physics->AddForce ( Vector2 ( -0.5f , 0 ) );
        }
        if ( IM->GetEvent ( SDLK_SPACE , DOWN ) || IM->GetEvent ( SDLK_SPACE , HOLD ) )
        {
            Shoot ( );
        }
        for ( Bullet* bullet : bullets )
        {
            if ( bullet->GetActive ( ) ) bullet->Update ( );
        }

        if (!canShoot)
        {
            shootCooldown -= 1.0f / 60.0f;
            if ( shootCooldown <= 0.0f )
            {
                canShoot = true;
                shootCooldown = 0.0f;
            }
        }

        if (invencible)
        {
            invencibleTime -= 1.0f / 60.0f;
            if (invencibleTime <= 0.0f)
            {
                invencible = false;
            }
        }

        if (health <= 0 && !isDeath)
        {
            isDeath = true;
        }
        for ( Bullet* b : bullets )
        {
            b->Update ( );
        }
    }
    void OnCollisionEnter(Object* other)
    {
        /*IDamageable* enemy = dynamic_cast<IDamageable*>(other);
        if (enemy != nullptr && !invencible)
        {
            ReceiveDamage(enemy->GetDamage());
            invencible = true;
            invencibleTime = 2.0f;
        }*/
    }
    void PickUpItem(/*Item* item*/)
    {
        //if (inventory.size() < maxEquippedItem)
        //{
        //    inventory.push_back(item);
        //}
    }
    bool GetInvencibleStatus()
    {
        return invencible;
    }
    void Shoot()
    {
        if (!canShoot) return;

        SPAWNER.SpawnBullet(*_transform, Vector2::Right * 75);

        canShoot = false;
        shootCooldown = maxShootCooldownTime;
    }
    void ShootTime( )
    {
        //Gestionar tiempo entre disparos (si prefieres separarlo)
    }

};

