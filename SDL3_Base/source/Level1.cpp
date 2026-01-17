#include "Level1.h"
#include "TestObject.h"
#include "ImageRenderer.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "ImageObject.h"

#include "UI/UIManager.h"
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
//level 2
#include "Enemies/Headron.h"
#include "Enemies/Gearbot.h"
#include "Enemies/Boosters.h"
#include "Enemies/Lifters.h"
#include "Enemies/Strikers.h"
#include "Enemies/Loopers.h"
#include "Enemies/Angrygons.h"

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

	UIManager * uiManager = new UIManager ( );


	WaveManager * waveManager = new WaveManager
	(
		{
			new EnemySpawnData 
			( //ID, ORIGIN, SPAWN PATTERNM, VECTOR ENEMIGOS
				1, 
				Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT / 3 ),
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
			),
			new EnemySpawnData
			(
				2,
				Vector2 ( RM->WINDOW_WIDTH * 0.5f , RM->WINDOW_HEIGHT * 2),
				new TopBottomSpawnPattern
				(
					300.f
				),
				{
					new Gulper ( Vector2::Up ),
					new Gulper ( Vector2::Down )
				}
			),
			new EnemySpawnData
			(
				3,
				Vector2(RM->WINDOW_WIDTH + 50, 50),
				new RandomSpawnPattern
				(
					Vector2::Down,
					100,
					50.f
				),
				{
					new Drifter ( ),
					new Drifter ( ),
					new Drifter ( ),
					new Drifter ( ),
					new Drifter ( ),
					new Drifter ( ),
					new Drifter ( ),
					new Drifter ( ),
					new Drifter ( )
				}
			),
			new EnemySpawnData
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
					new ArachnidTail(5.f),
					new ArachnidTail(10.f),
					new ArachnidTail(15.f),
					new ArachnidTail(20.f),
					new ArachnidTail(25.f),
					new ArachnidTail(30.f),
					new ArachnidTail(35.f)
				}
			),
			new EnemySpawnData
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
			),
			new EnemySpawnData
			(
				3,
				Vector2 ( 0,0 ),
				new CornerSpawnPattern
				(
					150
				),
				{
					new Charger ( ),
					new Charger ( ),
					new Charger ( ),
					new Charger ( ),
					new Charger ( ),
					new Charger ( ),
					new Charger ( ),
					new Charger ( )
				}
			),
			new EnemySpawnData
			(
				2,
				Vector2 ( RM->WINDOW_WIDTH * 0.5f , RM->WINDOW_HEIGHT * 2),
				new TopBottomSpawnPattern
				(
					600.f
				),
				{
					new Gulper ( Vector2::Up),
					new Gulper ( Vector2::Down)
				}
			),
			new EnemySpawnData
			(
				3,
				Vector2(RM->WINDOW_WIDTH,100),
				new LineSpawnPattern
				(
					Vector2::Up,
					50
				),
				{
					new Mawler(),
					new Mawler(),
					new Mawler(),
					new Mawler(),
					new Mawler(),
					new Mawler(),
					new Mawler(),
					new Mawler()
				}
			),
			new EnemySpawnData
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
			),
			new EnemySpawnData
			( //ID, ORIGIN, SPAWN PATTERNM, VECTOR ENEMIGOS
				1,
				Vector2(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT / 3),
				new LineSpawnPattern
				(
					Vector2(1, 0), //Direction where will spawn
					100 //Spacing
				),
				{
					new Swirlers(),
					new Swirlers(),
					new Swirlers(),
					new Swirlers()
				}
			),
			new EnemySpawnData
			(
				2,
				Vector2(RM->WINDOW_WIDTH * 0.5f, RM->WINDOW_HEIGHT * 2),
				new TopBottomSpawnPattern
				(
					300.f
				),
				{
					new Gulper(Vector2::Up),
					new Gulper(Vector2::Down)
				}
			),
			new EnemySpawnData
			(
				3,
				Vector2(RM->WINDOW_WIDTH + 50, 50),
				new RandomSpawnPattern
				(
					Vector2::Down,
					100,
					50.f
				),
				{
					new Drifter(),
					new Drifter(),
					new Drifter(),
					new Drifter(),
					new Drifter(),
					new Drifter(),
					new Drifter(),
					new Drifter(),
					new Drifter()
				}
			),
			new EnemySpawnData
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
					new ArachnidTail(10.f),
					new ArachnidTail(20.f),
					new ArachnidTail(30.f),
					new ArachnidTail(40.f),
					new ArachnidTail(50.f),
					new ArachnidTail(60.f),
					new ArachnidTail(70.f)
				}
			),
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
		}
	);

	_objects.push_back ( waveManager );
}