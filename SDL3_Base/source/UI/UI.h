#pragma once
#include "../TextObject.h"
#include "UIBar.h"
#include "UIStaticImages.h"

class UI
{
public:
	UI();
	~UI() = delete;

	UIBar* cannonAmmoUI;
	UIBar* laserAmmoUI;
	UIBar* shieldUI;
	TextObject* scoreUI;
	TextObject* lifesUI;
	UIStaticImages* staticUI;
	UIStaticImages* staticUIBackground;

private:
	TextObject* scoreLabelUI;
	TextObject* lifesLabelUI;
	TextObject* shieldLabelUI;
	TextObject* laserLabelUI;
	TextObject* cannonLabelUI;

	string cannonBarSprite;
	string laserBarSprite;
	string shieldBarSprite;
	string emptySprite;
	string staticUISprite;
};

