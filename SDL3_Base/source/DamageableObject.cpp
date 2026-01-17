#include "DamageableObject.h"

void DamageableObject::ReceiveDamage(int damage)
{
    health -= damage;
    if (onReceiveDamage != nullptr) onReceiveDamage();
    if (health < 0)
    {
        health = 0;
        isDeath = true;
    }
}