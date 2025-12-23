#include "Level1.h"
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
#include "Enemies/Headron.h"
#include "Enemies/Gearbot.h"
#include "Patterns/LineSpawnPattern.h"
#include "Patterns/TopBottomSpawnPattern.h"
#include "Patterns/RandomSpawnPattern.h"
#include "Patterns/CornerSpawnPattern.h"
#pragma endregion Items

void Level1::OnEnter ( )
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
    Player * player = new Player ( 55 );
	SPAWNER.SpawnObject ( player );

	SPAWNER.SpawnObject ( new Item ( "resources/Items/Score.png" ) );
	SPAWNER.SpawnObject ( new Item ( "resources/Items/Score.png" ) );
	SPAWNER.SpawnObject ( new Item ( "resources/Items/Score.png" ) );
	UIManager * uiManager = new UIManager ( );


	WaveManager * waveManager = new WaveManager
	(
		{ // enemySpawnData vector
			//new EnemySpawnData 
			//( //ID, ORIGIN, SPAWN PATTERNM, VECTOR ENEMIGOS
			//	1, 
			//	Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT / 3 ),
			//	new LineSpawnPattern 
			//	( 
			//		Vector2 ( 1,0 ), //Direction where will spawn
			//		100 //Spacing
			//	), 
			//	{ 
			//		new Swirlers ( ),
			//		new Swirlers ( ),
			//		new Swirlers ( ),
			//		new Swirlers ( ) 
			//	} 
			//) ,
			//new EnemySpawnData
			//(
			//	2,
			//	 Vector2 ( RM->WINDOW_WIDTH * 0.5f , RM->WINDOW_HEIGHT * 2);,
			//	new TopBottomSpawnPattern
			//	(
			//		300.f
			//	),
			//	{
			//		new Gulper ( Vector2::Up),
			//		new Gulper ( Vector2::Down )
			//	}
			//),
			/*new EnemySpawnData
			(
				3,
				origin,
				new RandomSpawnPattern
				(
					Vector2::Down,
					100,
					50.f
				),
				{
					new Drifter ( Vector2::Left ),
					new Drifter ( Vector2::Left ),
					new Drifter ( Vector2::Left ),
					new Drifter ( Vector2::Left ),
					new Drifter ( Vector2::Left ),
					new Drifter ( Vector2::Left ),
					new Drifter ( Vector2::Left ),
					new Drifter ( Vector2::Left ),
					new Drifter ( Vector2::Left )
				}
			)*/
			/*new EnemySpawnData
			(
				3,
				Vector2(50,RM->WINDOW_HEIGHT),
				new LineSpawnPattern
				(
					Vector2::Right,
					150
				),
				{
					new Floater (),
					new Floater (),
					new Floater (),
					new Floater (),
					new Floater (),
					new Floater (),
					new Floater (),
					new Floater ()
				}
			),*/
			//new EnemySpawnData
			//(
			//	3,
			//	Vector2 ( 0,0 ),
			//	new CornerSpawnPattern
			//	(
			//		150
			//	),
			//	{
			//		new Charger ( ),
			//		new Charger ( ),
			//		new Charger ( ),
			//		new Charger ( ),
			//		new Charger ( ),
			//		new Charger ( ),
			//		new Charger ( ),
			//		new Charger ( )
			//	}
			//)
			//new EnemySpawnData
			//(
			//	3,
			//	Vector2(RM->WINDOW_WIDTH,100),
			//	new LineSpawnPattern
			//	(
			//		Vector2::Up,
			//		50
			//	),
			//	{
			//		new Mawler(),
			//		new Mawler(),
			//		new Mawler(),
			//		new Mawler(),
			//		new Mawler(),
			//		new Mawler(),
			//		new Mawler(),
			//		new Mawler()
			//	}
			//)
		/*	new EnemySpawnData
			(
				3,
				Vector2(0,RM->GAME_WINDOW_HEIGHT / 2),
				new LineSpawnPattern
				(
					Vector2::Zero,
					0
				),
				{
					new Splitta(0),
					new Splitta(1),
					new Splitta(2),
					new Splitta(3),
					new Splitta(4),
					new Splitta(5),
					new Splitta(6),
					new Splitta(7)
				}
			),*/
			/*new EnemySpawnData
			(
				3,
				Vector2(RM->WINDOW_WIDTH, -100),
				new LineSpawnPattern
				(
					Vector2::Down,
					50
				),
				{
					new Arachnid(),
					new ArachnidTail(30.f),
					new ArachnidTail(60.f),
					new ArachnidTail(90.f),
					new ArachnidTail(120.f),
					new ArachnidTail(4.5f),
					new ArachnidTail(5.5f),
					new ArachnidTail(6.5f)
				}
			),*/
			/*new EnemySpawnData
			/*
						new EnemySpawnData
						(
							3 ,
							Vector2 ( RM->WINDOW_WIDTH , RM->GAME_WINDOW_HEIGHT / 2 ) ,
							new LineSpawnPattern
							(
								Vector2::Zero ,
								0
							) ,
							{
								new Tentakor ( )
							}
						)
			*/
			new EnemySpawnData
			(
				3,
				Vector2(-150, RM->GAME_WINDOW_HEIGHT/ 2 - 50),
				new LineSpawnPattern
				(
					Vector2::Zero,
					0
				),
				{
					new Headron(true, 0.f),
					new Headron(false, 0.f),
					new Headron(true, 10.f),
					new Headron(false, 10.f),
					new Headron(true, 20.f),
					new Headron(false, 20.f),
					new Headron(true, 30.f),
					new Headron(false, 30.f)
				}
			)*/
			new EnemySpawnData
			(
				3,
				Vector2 ( 0,0 ),
				new CornerSpawnPattern
				(
					150
				),
				{
					new Gearbot ( player ),
					new Gearbot ( player ),
					new Gearbot ( player ),
					new Gearbot ( player ),
					new Gearbot ( player ),
					new Gearbot ( player ),
					new Gearbot ( player ),
					new Gearbot ( player )
				}
			)
		}
	);

	_objects.push_back ( waveManager );
}