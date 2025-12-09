#include "AmmoGun.h"

void AmmoGun::Shoot()
{
	if (ammo > 0)
	{
		Gun::Shoot();
		ammo--;
	}
}
