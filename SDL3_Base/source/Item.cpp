#include "Item.h"

#include "Spawner.h"
#include "Score.h"
#include "Cannon.h"
#include "Laser.h"
#include "SpeedUpgrade.h"
#include "Turret.h"
#include "ForceField.h"
#include "Shield.h"

#include "Vector2.h"
#include "RenderManager.h" 
#include <cstdlib>  


Item::Item ( std::string _path , ItemType _type )
    : DamageableObject ( 1 , _path ) ,
    impactCount ( 0 ) ,
    maxImpactCount ( 4 ) ,
    type ( _type )
{
    _transform->position = Vector2 ( RM->WINDOW_WIDTH , 500 );
    _transform->scale = Vector2 ( 3 , 3 );
    _transform->rotation = 0.f;
}

Item::~Item ( )
{
}

void Item::Update ( )
{
    Object::Update ( );
    GameObject::Update ( );

}

void Item::Move ( )
{
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
    }
    else
    {
        return;
    }

    switch ( type )
    {
        case SCORE:
            SPAWNER.SpawnObject ( new Score ( ) );
            break;

        case CANNON:
            SPAWNER.SpawnObject ( new Cannon ( ) );
            break;

        case LASER:
            SPAWNER.SpawnObject ( new Laser ( ) );
            break;

        case SPEED_UPGRADE:
            SPAWNER.SpawnObject ( new SpeedUpgrade ( ) );
            break;

        case TURRET:
            SPAWNER.SpawnObject ( new Turret ( ) );
            break;

        case FORCEFIELD:
            SPAWNER.SpawnObject ( new ForceField ( ) );
            break;

        case SHIELD:
            SPAWNER.SpawnObject ( new Shield ( ) );
            break;

        default:
            break;
    }

    if ( onMaxImpactReached )
        onMaxImpactReached ( );

    Destroy ( );
    maxImpactCount += 4;
}