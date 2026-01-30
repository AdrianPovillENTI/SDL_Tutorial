#include "PlayerHealth.h"
#include "../Audio/AudioManager.h"

void PlayerHealth::Init(int _maxHp, int _initialLifes)
{
	maxHp = _maxHp;
	hp = maxHp;
	lifes = _initialLifes;

	if (onShieldChanged) onShieldChanged(hp, maxHp);
	if (onLifesChanged) onLifesChanged(lifes);
}

void PlayerHealth::SetInvincible(float seconds)
{
	invincible = true;
	invincibleTimer = seconds;
}

void PlayerHealth::ReceiveDamage(int dmg)
{
	if (invincible) return;

	AM->PlaySound("resources/audio/sfx/Damage.wav");

	hp -= dmg;

	if (onShieldChanged) onShieldChanged(hp, maxHp);
	
	SetInvincible(3.f);

	if (hp <= 0)
	{
		if (lifes > 0)
		{
			lifes--;
			if (onLifesChanged) onLifesChanged(lifes);

			FillShield();
			SetInvincible(1);
		}
		else
		{
			if (onDeath) onDeath();
		}
	}
}

void PlayerHealth::FillShield()
{
	hp = maxHp;
	if (onShieldChanged) onShieldChanged(hp, maxHp);
}

void PlayerHealth::Update(float dt)
{
	if (!invincible) return;

	invincibleTimer -= dt;
	if (invincibleTimer <= 0.0f)
	{
		invincible = false;
		invincibleTimer = 0.0f;
	}
}