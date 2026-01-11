#include "ArachnidTail.h"
#include "../Player.h"

void ArachnidTail::OnEnterFunction()
{
    counterToPlay += 1.f / 60.f;

    if (counterToPlay < timeToPlay) return;
    playOnStart = true;
    state = Enemy::EnemyState::ON_UPDATE;
}