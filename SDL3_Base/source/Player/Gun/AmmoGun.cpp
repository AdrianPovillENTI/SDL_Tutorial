#include "AmmoGun.h"

void AmmoGun::Shoot()
{
	if (ammo > 0)
	{
		Gun::Shoot();
		ammo--;

		if (onAmmoChanged)
			onAmmoChanged(ammo, maxAmmo);
	}
}

void AmmoGun::ResetAmmo()
{
	ammo = maxAmmo;
	if (onAmmoChanged) onAmmoChanged(ammo, maxAmmo);
}
