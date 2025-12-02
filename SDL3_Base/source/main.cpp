#include "Game.h"

#include <SDL3/SDL.h>
#include <exception>
#include <iostream>
#include "RenderManager.h"

int main()
{
	Object * obj = new Object();
	Game* game = new Game();
	try
	{
		game->Init();	
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what();
		game->Release();
		return -1;
	}

	while (game->IsRunning())
	{
		obj->Update ( );
		obj->Render ( );
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->Release();

	return 0;
}