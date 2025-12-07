#include "Game.h"
#include "Gameplay.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include <cassert>
#include "TestObject.h"

void Game::Init()
{
	RM->Init();

	RM->LoadTexture("resources/Player/Player.png");
	RM->LoadTexture( "resources/Player/NormalShoot/shot5_1.png" );
	RM->LoadTexture("resources/Background.png");
	RM->LoadTexture("resources/Items/Score.png");
	RM->LoadTexture("resources/Items/Cannon.png");
	RM->LoadTexture("resources/Items/Laser.png");
	RM->LoadTexture("resources/Items/SpeedUpgrade.png");
	RM->LoadTexture("resources/Items/Turret.png");
	RM->LoadTexture("resources/Items/ForceField.png");
	RM->LoadTexture("resources/Items/Shield.png");

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