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

	staticUI = new UIStaticImages(staticUISprite);
	staticUIBackground = new UIStaticImages(emptySprite);

	cannonAmmoUI = new UIBar(cannonBarSprite, 100);
	laserAmmoUI = new UIBar(laserBarSprite, 100);
	shieldUI = new UIBar(shieldBarSprite, 100);


	SPAWNER.SpawnObject(staticUIBackground);

	SPAWNER.SpawnObject(cannonAmmoUI);
	SPAWNER.SpawnObject(laserAmmoUI);
	SPAWNER.SpawnObject(shieldUI);

	SPAWNER.SpawnObject(staticUI);

	scoreUI = new TextObject("00000", Vector2(150, RM->WINDOW_HEIGHT + 15), Vector2::One * 2);
	lifesUI = new TextObject("3", Vector2(700, RM->WINDOW_HEIGHT + 30), Vector2::One * 3);

	SPAWNER.SpawnObject(scoreUI);
	SPAWNER.SpawnObject(lifesUI);

	scoreLabelUI = new TextObject(scoreText, Vector2(150, RM->WINDOW_HEIGHT - 25), Vector2::One * 2);
	lifesLabelUI = new TextObject(lifesText, Vector2(400, RM->WINDOW_HEIGHT + 30), Vector2::One * 3);
	cannonLabelUI = new TextObject(cannonText, Vector2(700, RM->WINDOW_HEIGHT - 5), Vector2::One * 1);
	laserLabelUI = new TextObject(laserText, Vector2(700, RM->WINDOW_HEIGHT - 40), Vector2::One * 1);
	shieldLabelUI = new TextObject(shieldText, Vector2(700, RM->WINDOW_HEIGHT - 75), Vector2::One * 1);

	SPAWNER.SpawnObject(scoreLabelUI);
	SPAWNER.SpawnObject(lifesLabelUI);
	SPAWNER.SpawnObject(cannonLabelUI);
	SPAWNER.SpawnObject(laserLabelUI);
	SPAWNER.SpawnObject(shieldLabelUI);
}