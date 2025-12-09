#include "Gameplay.h"
#include "TestObject.h"
#include "ImageRenderer.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "ImageObject.h"

#include "BackgroundManager.h"
#include "Player.h"
#include "Bullet.h"

#pragma region
#include "Item.h"
#include "SpeedUpgrade.h"
#include "Turret.h"
#pragma endregion Items

void Gameplay::OnEnter()
{
	for ( int i = 0; i < 3; i++ )
	{
		//SPAWNER.SpawnObject ( new Background ( i, "resources/Background.png" ) );
	}
	SPAWNER.SpawnObject ( new Player ( 55 ) );
}