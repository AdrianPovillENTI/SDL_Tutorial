#include "Game.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "..\SceneManager.h"
#include <cassert>

void Game::Init()
{
	RM->Init();

	RM->LoadTexture("recources/xd.png");

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