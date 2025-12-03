#pragma once
#include "DamageableObject.h"
#include <functional>
class Item : public DamageableObject
{
private:
    int impactCount;
    int maxImpactCount;
    function<void ( )> onMaxImpactReached;
public:
    Item ( Transform t ) :
        DamageableObject ( 1 , "resources/bullet.png" ) ,
        impactCount ( maxImpactCount )
    {
        _transform->position = t.position;
        _transform->scale = Vector2::One;
        _transform->rotation = 0.f;
    }
    ~Item ( );

    void Start ( ) override
    {
    }
    void Update ( ) override
    {
        if ( !active ) return;
        Object::Update ( );
        GameObject::Update ( );
        if ( impactCount >= maxImpactCount )
        {
            if ( maxImpactCount > ( 4 * 6 ) ) return;
            if ( onMaxImpactReached != NULL )
            {
                onMaxImpactReached ( );
                maxImpactCount += 4;
                
            }
        }
    }
    int GetDamage ( ) const { return 1; }
    void SetAction ( function<void ( )> action )
    {
        onMaxImpactReached = action;
    }
    int GetImpactCount() const { return impactCount; }
    int GetMaxImpactCount() const { return maxImpactCount; }
    bool HasOnMaxImpactReached() const { return onMaxImpactReached != nullptr; }

    void Move ( Vector2 targetPos ) override
    {

    }

};