#include "Level2.h"
#include "TestObject.h"
#include "ImageRenderer.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "ImageObject.h"

#include "UI/UIManager.h"
#include "MapDecorations.h"
#include "Player/Player.h"
#include "Player/Gun/Bullet.h"

#pragma region

#include "Player/Item.h"
#include "Player/Gun/Turret.h"
#include "Enemies/Waves/WaveManager.h"

#pragma region
#include "Enemies/Headron.h"
#include "Enemies/Gearbot.h"
#include "Enemies/Boosters.h"
#include "Enemies/Lifters.h"
#include "Enemies/Strikers.h"
#include "Enemies/Loopers.h"
#include "Enemies/Angrygons.h"
#include "Enemies/Starforge.h"
#include "Enemies/Scouts.h"
#pragma endregion Enemies

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
		SPAWNER.SpawnObject ( new Background ( i , "resources/Background/Background_Lvl2.png" ) );
	}
	for ( int i = 0; i < 45; i++ )
	{
		SPAWNER.SpawnObject ( new MapDecorations ( "resources/Map/MapDecorations/Ice3.png" ) );
	}
	UIM->InitializeUI();
	
	Player * player = new Player ( 100 );
	SPAWNER.SpawnObject ( player);

	WaveManager * waveManager = new WaveManager
	(
		{ // enemySpawnData vector
			new Wave
			(
				3,
				Vector2 ( RM->WINDOW_WIDTH,0 ),
				new LineSpawnPattern
				(
					Vector2::Up ,
					50.f
				),
				{
					new Boosters ( Vector2::Left ),
					new Boosters ( Vector2::Left ),
					new Boosters ( Vector2::Left ),
					new Boosters ( Vector2::Left ),
					new Boosters ( Vector2::Left ),
					new Boosters ( Vector2::Left ),
					new Boosters ( Vector2::Left ),
					new Boosters ( Vector2::Left )
				}
			),
			new Wave
			(
				3,
				Vector2 ( 0, RM->GAME_WINDOW_HEIGHT / 2 ),
				new LineSpawnPattern
				(
					Vector2::Zero ,
					0
				),
				{
					new Loopers ( 10.f, Vector2::Right ),
					new Loopers ( 20.f, Vector2::Right ),
					new Loopers ( 30.f, Vector2::Right ),
					new Loopers ( 40.f, Vector2::Right ),
					new Loopers ( 10.f, Vector2::Left,Vector2 ( RM->WINDOW_WIDTH, RM->GAME_WINDOW_HEIGHT / 2 ) ),
					new Loopers ( 20.f, Vector2::Left,Vector2 ( RM->WINDOW_WIDTH, RM->GAME_WINDOW_HEIGHT / 2 ) ),
					new Loopers ( 30.f, Vector2::Left,Vector2 ( RM->WINDOW_WIDTH, RM->GAME_WINDOW_HEIGHT / 2 ) ),
					new Loopers ( 40.f, Vector2::Left,Vector2 ( RM->WINDOW_WIDTH, RM->GAME_WINDOW_HEIGHT / 2 ) )
				}
			),
			new Wave
			(
				3,
				Vector2 ( 0,0 ),
				new CornerSpawnPattern
				(
					150
				),
				{
					new Gearbot ( player->GetTransform() ),
					new Gearbot ( player->GetTransform ( ) ),
					new Gearbot ( player->GetTransform ( ) ),
					new Gearbot ( player->GetTransform ( ) ),
					new Gearbot ( player->GetTransform ( ) ),
					new Gearbot ( player->GetTransform ( ) ),
					new Gearbot ( player->GetTransform ( ) ),
					new Gearbot ( player->GetTransform ( ) )
				}
			),
			new Wave
			(
				3,
				Vector2 ( RM->WINDOW_WIDTH / 2, RM->GAME_WINDOW_HEIGHT ),
				new LineSpawnPattern
				(
					Vector2::Right ,
					100.f
				),
				{
					new Strikers ( Vector2::Down ),
					new Strikers ( Vector2::Down ),
					new Strikers ( Vector2::Down ),
					new Strikers ( Vector2::Down )
				}
			),
			new Wave
			(
				3,
				Vector2 ( RM->WINDOW_WIDTH ,0 ),
				new LineSpawnPattern
				(
					Vector2::Up ,
					50.f
				),
				{
					new Lifters ( Vector2::Left ),
					new Lifters ( Vector2::Left ),
					new Lifters ( Vector2::Left ),
					new Lifters ( Vector2::Left ),
					new Lifters ( Vector2::Left ),
					new Lifters ( Vector2::Left ),
					new Lifters ( Vector2::Left ),
					new Lifters ( Vector2::Left )
				}
			),
			new Wave
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
			),
			new Wave
			(
				3 ,
				Vector2 ( RM->WINDOW_WIDTH + 100.f , 50.f ) ,
				new LineSpawnPattern
				(
					Vector2::Up ,
					95.f
				) ,
				{
					new Scouts ( ),
					new Scouts ( ),
					new Scouts ( ),
					new Scouts ( ),
					new Scouts ( ),
					new Scouts ( )
				}
			),
			new Wave
			(
				3,
				Vector2 ( 0, RM->GAME_WINDOW_HEIGHT / 3 ),
				new LineSpawnPattern
				(
					Vector2::Left ,
					50.f
				),
				{
					new Angrygons ( ),
					new Angrygons ( ),
					new Angrygons ( ),
					new Angrygons ( ),
					new Angrygons ( ),
					new Angrygons ( ),
					new Angrygons ( ),
					new Angrygons ( ),
					new Angrygons ( )
				}
			),
			new Wave
			(
				3 ,
				Vector2 ( RM->WINDOW_WIDTH , RM->GAME_WINDOW_HEIGHT / 2 ) ,
				new LineSpawnPattern
				(
					Vector2::Zero ,
					0
				) ,
				{
					new Starforge ( )
				}
			)
		}
	);

	//_objects.push_back ( waveManager );
}