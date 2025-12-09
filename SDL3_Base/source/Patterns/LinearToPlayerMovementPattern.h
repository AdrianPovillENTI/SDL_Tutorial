#pragma once
#include "MovementPattern.h"
#include "../Player.h"
class LinearToPlayerMovementPattern : public MovementPattern
{
private:
    Player* player;
    Vector2 target;
    float speed;

public:
    LinearToPlayerMovementPattern ( Player* _player, float _speed  )
        : target ( player->GetTransform()->position ) , player(_player ), speed(_speed )
    {
        target.Normalize ( );
    }
    Vector2 GetDelta ( float dt , float elapsed , int index ) const override;
};