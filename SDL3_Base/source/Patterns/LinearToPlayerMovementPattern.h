#pragma once
#include "MovementPattern.h"
#include "../Player.h"
class LinearToPlayerMovementPattern : public MovementPattern
{
private:
    Player* player;
    Vector2 direction;
    float speed;

public:
    LinearToPlayerMovementPattern ( Player* _player, float _speed  )
        : direction ( player->GetTransform()->position ) , player(_player ), speed(_speed )
    {
        direction.Normalize ( );
    }
    Vector2 GetDelta ( float dt , float elapsed , int index ) override;
};