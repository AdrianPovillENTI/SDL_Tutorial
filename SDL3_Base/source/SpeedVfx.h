#pragma once
#include "GameObject.h"
class SpeedVfx : public GameObject
{
private:
    int currentFrame;
    float frameCounter;
    float frameMaxDuration;
    vector<string> animationFrames;
public:
    SpeedVfx ( ) : GameObject( "resources/Player/SpeedVfx/speed_1.png" )
        ,currentFrame ( 0 ) , frameCounter ( 0 ) , frameMaxDuration ( 30 )
    {
        _transform->scale = Vector2 { 2,2 };
        animationFrames = {
            "resources/Player/SpeedVfx/speed_1.png",
            "resources/Player/SpeedVfx/speed_2.png",
            "resources/Player/SpeedVfx/speed_3.png",
            "resources/Player/SpeedVfx/speed_4.png",
        };
    }
    ~SpeedVfx();
    void Update ( ) override;
    void ChangeSpriteFrame ( );
    void SetAnimationSprites ( vector<string> & _animationFrames );
};

