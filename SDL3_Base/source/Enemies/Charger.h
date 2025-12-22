#pragma once
#include "Enemy.h"

// WAZOWSKY / CHARGER
class Charger : public Enemy
{
private:
    Vector2 targetPoint;

    float phaseTimer = 0.f;
    bool isMoving = true;

    float moveTime = 5.0f; // se mueven bastante
    float stopTime = 1.0f;

    Vector2 ChooseSmartTarget ( );
    Vector2 DirectionToTarget ( ) const;
    void CreatePattern ( const Vector2 & dir );

public:
    Charger ( );
    void Start ( ) override;
    void Move ( ) override;
};
