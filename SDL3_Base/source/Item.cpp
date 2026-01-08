#include "Item.h"
#include "Spawner.h"
#include "Vector2.h"
#include "RenderManager.h" 
#include "ScoreManager.h"
#include "Player.h"
#include <cstdlib>  


Item::Item ( std::string _path, Vector2 pos )
    : DamageableObject ( 1 , _path ) ,
    impactCount ( 0 ) ,
    maxImpactCount ( 4 )
{
    _transform->scale = Vector2::One;
    _physics->AddCollider(new AABB(_transform->position, _transform->size));
    _transform->position = pos;
    _transform->rotation = 0.f;
    type = SCORE;
    SpritesInitialization();  
}

Item::~Item ( )
{
}

void Item::SpritesInitialization() 
{
    itemsSprites = {
        "resources/Items/Score.png",
        "resources/Items/Cannon.png",
        "resources/Items/Laser.png",
        "resources/Items/SpeedUpgrade.png",
        "resources/Items/Turret.png",
        "resources/Items/ForceField.png",
        "resources/Items/Shield.png"
    };
    actualSprite = itemsSprites[0];
}

void Item::Update ( )
{
    Object::Update ( );
    GameObject::Update ( );
}

void Item::Move ( )
{
}

void Item::OnCollision(Object* o)
{
    if (Player* p = dynamic_cast<Player*>(o))
    {
        switch (type)
        {
        case Item::SCORE: SCR->AddScore(1000); break; }
        case Item::CANNON: { p->SetCannon(); break; }
        case Item::LASER: { p->SetLaser(); break; }
        case Item::SPEED_UPGRADE: { p->SetSpeedUpgrade(); break; }
        case Item::TURRET: { p->SetTurret(); break; }
        case Item::FORCEFIELD: { p->SetInvincible(); break; }
        case Item::SHIELD: { p->FillShield();  break; }
        default: break;
        }
        Destroy();
        SetActive(false);
    }

    if (Bullet* b = dynamic_cast<Bullet*>(o))
    {
        AddImpact();
    }
}

void Item::AddImpact ( )
{
    impactCount++;
    CheckImpact ( );
}

void Item::CheckImpact ( )
{
    if ( impactCount < maxImpactCount )
        return;

    if ( type < SHIELD )
    {
        type = static_cast< ItemType > ( type + 1 );
        actualSprite = itemsSprites[(int)type];
        _renderer->SetResourcePath(itemsSprites[(int)type]);
    }
    else
    {
        return;
    }

    if ( onMaxImpactReached )
        onMaxImpactReached ( );

    maxImpactCount += 4;
}