#pragma once

#include "Spawner.h"
#include "Background.h"

class BackgroundManager {
private:
	std::string background1_path = "resources/Background.png";

public:

	BackgroundManager()
	{
		for (int i = 0; i < 3; i++)
		{
			SPAWNER.SpawnBackground(i, background1_path);
		}
	}
};
