#include "Item.h"
#include "Spawner.h"
#include "Vector2.h"
#include "RenderManager.h" 
#include "Player.h"
#include <cstdlib>  


Item::Item ( std::string _path )
    : DamageableObject ( 1 , _path ) ,
    impactCount ( 0 ) ,
    maxImpactCount ( 4 )
{
    _transform->scale = Vector2 ( 3 , 3 );
    _physics->AddCollider(new AABB(Vector2::Zero, _transform->scale));
    _transform->position = Vector2 ( RM->WINDOW_WIDTH , 500 );
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
        p->ApplyItemEffects(this);
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
        std::cout << itemsSprites[(int)type] << std::endl;
    }
    else
    {
        return;
    }

    if ( onMaxImpactReached )
        onMaxImpactReached ( );

    maxImpactCount += 4;
}