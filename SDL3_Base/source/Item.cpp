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
    _transform->position = Vector2 ( RM->WINDOW_WIDTH , 500 );
    _transform->scale = Vector2 ( 3 , 3 );
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
        "resources/Player/Items/Score.png",
        "resources/Player/Items/Cannon.png",
        "resources/Player/Items/Laser.png",
        "resources/Player/Items/SpeedUpgrade.png",
        "resources/Player/Items/Turret.png",
        "resources/Player/Items/ForceField.png",
        "resources/Player/Items/Shield.png"
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