#include "Scene.h"
#include "Spawner.h"

void Scene::Update()
{
    while ( SPAWNER.AreObjectsPendingSpawn ( ) )
    {
        Object * spawned = SPAWNER.GetSpawnedObjects ( );
        if ( spawned != nullptr )
        {
            _objects.push_back ( spawned );
            GameObject * go = dynamic_cast< GameObject * >( spawned );
            if ( go ) go->Start ( );
        }
    }

    for (int i = _objects.size() - 1; i >= 0; i--)
    {
        if (_objects[i]->IsPendingDestroy())
        {
            delete _objects[i];
            _objects.erase(_objects.begin() + i);
        }
    }

    for (int i = _ui.size() - 1; i >= 0; i--)
    {
        if (_ui[i]->IsPendingDestroy())
        {
            delete _ui[i];
            _ui.erase(_ui.begin() + i);
        }
    }

    for (Object* o : _objects)
        o->Update();

    for (Object* o : _ui)
        o->Update();

    int objSize = _objects.size();
    for (int i = 0; i < objSize; i++)
    {
        for (int j = i + 1; j < _objects.size(); j++)
        {
            if (_objects[i]->GetRigidbody()->CheckCollision(_objects[j]->GetRigidbody()))
            {

            }
        }
    }

    int uiSize = _ui.size();
    for (int i = 0; i < uiSize; i++)
    {
        for (int j = i + 1; j < _objects.size(); j++)
        {
            if (_ui[i]->GetRigidbody()->CheckCollision(_ui[j]->GetRigidbody()))
            {

            }
        }
    }
}

void Scene::Render()
{
    for (Object* o : _objects)
        o->Render();

    for (Object* o : _ui)
        o->Render();
}

void Scene::OnExit() {
    for (Object* o : _objects)
        delete o;

    _objects.clear();

    for (Object* o : _ui)
        delete o;

    _ui.clear();
}