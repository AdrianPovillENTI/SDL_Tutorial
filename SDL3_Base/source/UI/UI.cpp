#include "UI.h"
#include "../RenderManager.h"
#include"../Spawner.h"

UI::UI()
{
	cannonBarSprite = "resources/UI/CannonBar.png";
	laserBarSprite = "resources/UI/LaserBar.png";
	shieldBarSprite = "resources/UI/ShieldBar.png";
	staticUISprite = "resources/UI/StaticUI.png";
	emptySprite = "resources/UI/EmptySprite.png";

	cannonAmmoUI = new UIBar(cannonBarSprite, 100);
	laserAmmoUI = new UIBar(laserBarSprite, 100);
	shieldUI = new UIBar(shieldBarSprite, 100);
	staticUI = new UIStaticImages(staticUISprite);
	staticUIBackground = new UIStaticImages(emptySprite);

	SPAWNER.SpawnObject(staticUIBackground);
	SPAWNER.SpawnObject(cannonAmmoUI);
	SPAWNER.SpawnObject(laserAmmoUI);
	SPAWNER.SpawnObject(shieldUI);
	SPAWNER.SpawnObject(staticUI);
	//scoreUI = new TextObject(to_string(0), Vector2(RM->WINDOW_WIDTH * 2 / 3, RM->WINDOW_HEIGHT - 100), Vector2(100.f, 100.f));
	//lifesUI = new TextObject(to_string(3), Vector2(RM->WINDOW_WIDTH * 2 / 3, RM->WINDOW_HEIGHT - 200), Vector2(100.f, 100.f));

	//SPAWNER.SpawnObject(scoreUI);
	//SPAWNER.SpawnObject(lifesUI);
}