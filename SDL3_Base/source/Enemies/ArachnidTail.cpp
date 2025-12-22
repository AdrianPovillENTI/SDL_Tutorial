#include "ArachnidTail.h"
#include "../Player.h"

void ArachnidTail::OnCollision(Object* collided)
{
	if (Player* p = dynamic_cast<Player*>(collided))
		p->ReceiveDamage(damage);
}