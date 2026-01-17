#pragma once
#include "../TextObject.h"
#include "UIBar.h"
#include "UIStaticImages.h"

class UI
{
public:
	UI();
	~UI();

	UIBar* cannonAmmoUI;
	UIBar* laserAmmoUI;
	UIBar* shieldUI;
	TextObject* scoreUI;
	TextObject* lifesUI;

private:
	UIStaticImages* staticUI;
	UIStaticImages* staticUIBackground;

	TextObject* scoreLabelUI;
	TextObject* lifesLabelUI;
	TextObject* shieldLabelUI;
	TextObject* laserLabelUI;
	TextObject* cannonLabelUI;

	string scoreText = "SCORE:";
	string lifesText = "LIFES:";
	string cannonText = "Cannon";
	string laserText = "Laser";
	string shieldText = "Shield";

	string cannonBarSprite;
	string laserBarSprite;
	string shieldBarSprite;
	string emptySprite;
	string staticUISprite;
};

