#include "Game.h"
#include "Gameplay.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include <cassert>
#include "TestObject.h"
#include "MainMenu.h"

void Game::Init()
{
	RM->Init();

	//Player Sprites

	//Bullet Sprites
    //Normal Bullet
#pragma region LoadPlayerTextures
	RM->LoadTexture("resources/Player/Player.png");
	RM->LoadTexture("resources/Player/CannonSprite.png");
	RM->LoadTexture("resources/Player/LaserSprite.png");
	RM->LoadTexture("resources/Player/ShieldSprite.png");

	RM->LoadTexture( "resources/Player/SpeedVfx/speed_1.png" );
	RM->LoadTexture( "resources/Player/SpeedVfx/speed_2.png" );
	RM->LoadTexture( "resources/Player/SpeedVfx/speed_3.png" );
    RM->LoadTexture ( "resources/Player/SpeedVfx/speed_4.png" );
#pragma endregion LoadPlayerTextures
#pragma region LoadBulletTextures
	//NormalBullet bullet
	RM->LoadTexture( "resources/Player/NormalShoot/shot_1.png" );
	RM->LoadTexture( "resources/Player/NormalShoot/shot_2.png" );
    RM->LoadTexture ( "resources/Player/NormalShoot/shot_3.png" );
    RM->LoadTexture ( "resources/Player/NormalShoot/shot_4.png" );
    RM->LoadTexture ( "resources/Player/NormalShoot/shot_5.png" );
    RM->LoadTexture ( "resources/Player/NormalShoot/shot_6.png" );
	//NormalBullet explosion
	RM->LoadTexture( "resources/Player/NormalShoot/shot_exp_1.png" );
	RM->LoadTexture( "resources/Player/NormalShoot/shot_exp_2.png" );
	RM->LoadTexture( "resources/Player/NormalShoot/shot_exp_3.png" );
	RM->LoadTexture( "resources/Player/NormalShoot/shot_exp_4.png" );
	RM->LoadTexture( "resources/Player/NormalShoot/shot_exp_5.png" );
	RM->LoadTexture( "resources/Player/NormalShoot/shot_exp_6.png" );
	RM->LoadTexture( "resources/Player/NormalShoot/shot_exp_7.png" );
	RM->LoadTexture( "resources/Player/NormalShoot/shot_exp_8.png" );
    //Cannon Bullet
	RM->LoadTexture ( "resources/Player/Cannon/shot_1.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_2.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_3.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_4.png" );
	//Cannon explosion
	RM->LoadTexture ( "resources/Player/Cannon/shot_exp_1.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_exp_2.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_exp_3.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_exp_4.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_exp_5.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_exp_6.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_exp_7.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_exp_8.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_exp_9.png" );
	RM->LoadTexture ( "resources/Player/Cannon/shot_exp_10.png" );
    //Turret Bullet
	RM->LoadTexture ( "resources/Player/Turret/shot_1.png" );
	RM->LoadTexture ( "resources/Player/Turret/shot_2.png" );
	RM->LoadTexture ( "resources/Player/Turret/shot_3.png" );
	RM->LoadTexture ( "resources/Player/Turret/shot_4.png" );
	RM->LoadTexture ( "resources/Player/Turret/shot_5.png" );
	RM->LoadTexture ( "resources/Player/Turret/shot_6.png" );
	//Turret explosion
	RM->LoadTexture ( "resources/Player/Turret/shot_exp_1.png" );
	RM->LoadTexture ( "resources/Player/Turret/shot_exp_2.png" );
	RM->LoadTexture ( "resources/Player/Turret/shot_exp_3.png" );
	RM->LoadTexture ( "resources/Player/Turret/shot_exp_4.png" );
	RM->LoadTexture ( "resources/Player/Turret/shot_exp_5.png" );
    //Laser Bullet
	RM->LoadTexture ( "resources/Player/Laser/shot_1.png" );
	RM->LoadTexture ( "resources/Player/Laser/shot_2.png" );
	RM->LoadTexture ( "resources/Player/Laser/shot_3.png" );
	RM->LoadTexture ( "resources/Player/Laser/shot_4.png" );
	//Laser explosion
	RM->LoadTexture ( "resources/Player/Laser/shot_exp_1.png" );
	RM->LoadTexture ( "resources/Player/Laser/shot_exp_2.png" );
	RM->LoadTexture ( "resources/Player/Laser/shot_exp_3.png" );
	RM->LoadTexture ( "resources/Player/Laser/shot_exp_4.png" );
	RM->LoadTexture ( "resources/Player/Laser/shot_exp_5.png" );
#pragma endregion LoadBulletTextures
	RM->LoadTexture("resources/Background.png");
	RM->LoadTexture("resources/Items/Score.png");
	RM->LoadTexture("resources/Items/Cannon.png");
	RM->LoadTexture("resources/Items/Laser.png");
	RM->LoadTexture("resources/Items/SpeedUpgrade.png");
	RM->LoadTexture("resources/Items/Turret.png");
	RM->LoadTexture("resources/Items/ForceField.png");
	RM->LoadTexture("resources/Items/Shield.png");

	RM->LoadTexture("resources/UI/CannonBar.png");
	RM->LoadTexture("resources/UI/LaserBar.png");
	RM->LoadTexture("resources/UI/ShieldBar.png");
	RM->LoadTexture("resources/UI/EmptySprite.png");
	RM->LoadTexture("resources/UI/StaticUI.png");

	//RM->LoadFont("resources/fonts/Hyperspace.ttf");
	assert(SM.AddScene("MainMenu", new MainMenu()));
	assert(SM.AddScene("Gameplay", new Gameplay()));

	assert(SM.InitFirstScene("Gameplay"));
	_isRunning = true;
}

void Game::InitSDL()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		throw SDL_GetError();
}

void Game::CreateWindowAndRenderer()
{
	if (!SDL_CreateWindowAndRenderer(
		"Test",
		512, 512,
		SDL_WINDOW_RESIZABLE,
		&_window,
		&_renderer
	))
		throw SDL_GetError();
}

//void Game::HandleEvents()
//{
//	SDL_Event event;
//
//	while (SDL_PollEvent(&event))
//		if (event.type == SDL_EVENT_QUIT)
//			_isRunning = false;
//}

void Game::HandleEvents()
{
	_isRunning = !IM->Listen();
}

void Game::Update()
{
	SM.UpdateCurrentScene();
}

void Game::Render()
{
	RM->ClearScreen();
	
	SM.GetCurrentScene()->Render();

	RM->RenderScreen();
}

void Game::Release()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}