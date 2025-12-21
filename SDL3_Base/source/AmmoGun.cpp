#include "AmmoGun.h"
#include "UI/UIManager.h"

void AmmoGun::Shoot()
{
	if (ammo > 0)
	{
		Gun::Shoot();
		ammo--;
		UIM->UpdateCannonAmmo(ammo, maxAmmo);
	}
}
