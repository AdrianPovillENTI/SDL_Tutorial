#include "Level2.h"
#include "TestObject.h"
#include "ImageRenderer.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "ImageObject.h"

#include "UI/UIManager.h"
#include "BackgroundManager.h"
#include "MapDecorations.h"
#include "Player.h"
#include "Bullet.h"

#pragma region

#include "Item.h"
#include "Turret.h"
#include "Enemies/WaveManager.h"
#include "Enemies/Swirlers.h"
#include "Enemies/Gulper.h"
#include "Enemies/Floater.h"
#include "Enemies/Drifter.h"
#include "Enemies/Charger.h"
#include "Enemies/Mawler.h"
#include "Enemies/Splitta.h"
#include "Enemies/Arachnid.h"
#include "Enemies/ArachnidTail.h"
#include "Enemies/Tentakor.h"
#include "Patterns/LineSpawnPattern.h"
#include "Patterns/TopBottomSpawnPattern.h"
#include "Patterns/RandomSpawnPattern.h"
#include "Patterns/CornerSpawnPattern.h"
#pragma endregion Items

void Level2::OnEnter ( )
{
	srand ( time ( NULL ) );

	for ( int i = 0; i < 3; i++ )
	{
		SPAWNER.SpawnObject ( new Background ( i , "resources/Background.png" ) );
	}
	for ( int i = 0; i < 45; i++ )
	{
		SPAWNER.SpawnObject ( new MapDecorations ( "resources/Map/MapDecorations/Ice3.png" ) );
	}
	SPAWNER.SpawnObject ( new Player ( 55 ) );

	SPAWNER.SpawnObject ( new Item ( "resources/Items/Score.png" ) );
	SPAWNER.SpawnObject ( new Item ( "resources/Items/Score.png" ) );
	SPAWNER.SpawnObject ( new Item ( "resources/Items/Score.png" ) );
	UIManager * uiManager = new UIManager ( );


	//WaveManager * waveManager = new WaveManager
	//(
	//	{ // enemySpawnData vector
	//		//new EnemySpawnData 
	//		//( //ID, ORIGIN, SPAWN PATTERNM, VECTOR ENEMIGOS
	//		//	1, 
	//		//	Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT / 3 ),
	//		//	new LineSpawnPattern 
	//		//	( 
	//		//		Vector2 ( 1,0 ), //Direction where will spawn
	//		//		100 //Spacing
	//		//	), 
	//		//	{ 
	//		//		new Swirlers ( ),
	//		//		new Swirlers ( ),
	//		//		new Swirlers ( ),
	//		//		new Swirlers ( ) 
	//		//	} 
	//		//),
	//	}
	//);

	//_objects.push_back ( waveManager );
}