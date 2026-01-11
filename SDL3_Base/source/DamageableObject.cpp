#include "DamageableObject.h"

void DamageableObject::ReceiveDamage(int damage)
{
    health -= damage;
    if (onReceiveDamage != nullptr) onReceiveDamage();
    std::cout << "Received damage: " << damage << " | Current health: " << health << std::endl;
    if (health < 0)
    {
        health = 0;
        isDeath = true;
    }
}