#include "Gameplay.h"
#include "TestObject.h"
#include "Player.h"
#include "Bullet.h"
#include "ImageRenderer.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "ImageObject.h"
#include "BackgroundManager.h"

void Gameplay::OnEnter()
{
	BackgroundManager* background = new BackgroundManager();

	Player* test1 = new Player(55);
	test1->Start ( );
	_objects.push_back(test1);
	
	for ( Bullet* b : test1->bullets )
	{
        b->Start ( );
		_objects.push_back ( b );
	}
}