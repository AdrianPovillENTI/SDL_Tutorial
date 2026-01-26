#pragma once
#include <functional>
class PlayerHealth
{
public:
    std::function<void(int hp, int maxHp)> onShieldChanged;
    std::function<void(int lifes)> onLifesChanged;
    std::function<void()> onDeath;
    std::function<void()> onTookDamage;

    void Init(int maxHp, int startLifes);

    void ReceiveDamage(int dmg);
    void FillShield();

    void SetInvincible(float seconds);
    bool IsInvincible() const { return invincible; }

    void Update(float dt);

    int GetHp() const { return hp; }
    int GetMaxHp() const { return maxHp; }
    int GetLifes() const { return lifes; }

private:
    int hp = 0;
    int maxHp = 0;
    int lifes = 0;

    bool invincible = false;
    float invincibleTimer = 0.0f;
};

