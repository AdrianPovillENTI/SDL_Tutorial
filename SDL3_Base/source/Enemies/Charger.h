#pragma once
#include "Enemy.h"

// WAZOWSKY / CHARGER
class Charger : public Enemy
{
private:
    float phaseTimer = 0.f;

    float moveTime = 0.75f; // tiempo moviéndose
    float stopTime = 1.0f;  // tiempo parado

    bool isMoving = true;

    Vector2 ChooseDirection ( );

    void CreatePattern ( Vector2 dir );

public:
    Charger ( );
    void Start ( ) override;
    void Move ( ) override;
};