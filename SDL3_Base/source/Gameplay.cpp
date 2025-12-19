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
#include "Turret.h"
#include "Enemies/WaveManager.h"
#include "Enemies/Swirlers.h"
#include "Patterns/LineSpawnPattern.h"
#pragma endregion Items

void Gameplay::OnEnter()
{
	for ( int i = 0; i < 3; i++ )
	{
		//SPAWNER.SpawnObject ( new Background ( i, "resources/Background.png" ) );
	}
	SPAWNER.SpawnObject ( new Player ( 55 ) );
<<<<<<< HEAD
<<<<<<< Updated upstream
=======
	SPAWNER.SpawnObject(new Item("resources/Items/Score.png"));
=======
>>>>>>> Develop
	WaveManager * waveManager = new WaveManager
	(
		{ //enemySpawnData vector
			new EnemySpawnData 
			( //ID, ORIGIN, SPAWN PATTERNM, VECTOR ENEMIGOS
				1, Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT / 3 ),
				new LineSpawnPattern 
				( 
					Vector2 ( 1,0 ), //Direction where will spawn
					100 //Spacing
				), 
				{ 
					new Swirlers ( ),
					new Swirlers ( ),
					new Swirlers ( ),
					new Swirlers ( ) 
				} 
			) 
		}
	);
	_objects.push_back ( waveManager );
<<<<<<< HEAD
>>>>>>> Stashed changes
=======
>>>>>>> Develop
}