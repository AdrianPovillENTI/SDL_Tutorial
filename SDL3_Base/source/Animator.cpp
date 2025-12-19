#include "Animator.h"


Animator::Animator(std::vector<std::string> _anim) : animationFrames(_anim), frameTime(0.0f), frameTimeMax(30), currentFrame(0) {}

void Animator::SetAnimationSprites(std::vector<std::string> _anim)
{
	animationFrames = _anim;
}

std::string Animator::ChangeSpriteFrame()
{
	frameTime += 1.0f / 30.0f;

	if (frameTime >= frameTimeMax)
	{
		frameTime = 0.0f;

		if (currentFrame >= animationFrames.size() - 1) currentFrame = animationFrames.size() - 3;
			currentFrame = (currentFrame + 1) % animationFrames.size();
	}

	return animationFrames[ currentFrame ];
}