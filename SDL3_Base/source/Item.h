#pragma once
#include "DamageableObject.h"
#include <functional>

class Item : public DamageableObject
{
public:

    enum ItemType
    {
        SCORE = 0 ,
        CANNON ,
        LASER ,
        SPEED_UPGRADE ,
        TURRET ,
        FORCEFIELD ,
        SHIELD ,
        ITEMTYPE_COUNT 
    };

private:
    int impactCount;
    int maxImpactCount;
    std::vector<std::string> itemsSprites;
    std::string actualSprite;
    std::function<void ( )> onMaxImpactReached;
    ItemType type;

public:

    Item ( std::string _path );
    virtual ~Item ( );

    void Update ( ) override;
    void Move ( ) override;

    ItemType GetType ( ) const { return type; }

    void SetAction ( std::function<void ( )> action )
    {
        onMaxImpactReached = action;
    }

    int GetImpactCount ( ) const { return impactCount; }
    int GetMaxImpactCount ( ) const { return maxImpactCount; }
    bool HasOnMaxImpactReached ( ) const { return onMaxImpactReached != nullptr; }

    void SpritesInitialization();

    void OnCollision(Object* o) override;
    void AddImpact ( );
    void CheckImpact ( );
};