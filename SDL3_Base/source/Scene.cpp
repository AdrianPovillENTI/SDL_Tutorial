#include "Scene.h"
#include "Spawner.h"
#include "ICollisionable.h"

void Scene::Update()
{
    //SPAWNER.ClearSpawnedObjects ( ); //Al pasar a la siguiente escena

    while ( SPAWNER.AreObjectsPendingSpawn ( ) )
    {
        Object * spawned = SPAWNER.GetSpawnedObjects ( );
        GameObject * gameObject = dynamic_cast< GameObject * >( spawned );
        if ( gameObject ) gameObject->Start ( );
        _objects.push_back ( spawned );
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
        for (int j = i + 1; j < objSize; j++)
        {
            if (_objects[i]->GetRigidbody()->CheckCollision(_objects[j]->GetRigidbody()))
            {
                if (auto* o = dynamic_cast<ICollisionable*>(_objects[i]))
                    o->OnCollision(_objects[j]);
                if (auto* o = dynamic_cast<ICollisionable*>(_objects[j]))
                    o->OnCollision(_objects[i]);
            }
        }
    }

    int uiSize = _ui.size();
    for (int i = 0; i < uiSize; i++)
    {
        for (int j = i + 1; j < uiSize; j++)
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