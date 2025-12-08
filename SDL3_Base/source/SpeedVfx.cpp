#include "SpeedVfx.h"

void SpeedVfx::Update ( )
{
    GameObject::Update ( );

    ChangeSpriteFrame ( );
}
void SpeedVfx::ChangeSpriteFrame ( )
{
    frameCounter += 1.f / 60.f;

    if ( frameCounter >= frameMaxDuration )
    {
        frameCounter = 0;
        currentFrame = ( currentFrame + 1 ) % animationFrames.size ( );
        _renderer->SetResourcePath ( animationFrames [ currentFrame ] );
    }
}
void SpeedVfx::SetAnimationSprites ( vector<string> & _animationFrames )
{
    animationFrames = _animationFrames;
}
