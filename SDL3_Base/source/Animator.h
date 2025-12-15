#pragma once
#include <string>
#include <vector>

class Animator
{
protected:
    float frameTime;
    float frameTimeMax;
    int currentFrame;
    std::vector<std::string> animationFrames;
  
public:
    Animator(std::vector<std::string> _anim);
    void SetAnimationSprites(std::vector<std::string> _anim);
    std::string ChangeSpriteFrame();
};

