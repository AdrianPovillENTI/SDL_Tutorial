#include "Scene.h"

void Scene::Update()
{
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

	int size = _objects.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + j; j < _objects.size(); j++)
		{
			if (_objects[i]->GetRigidbody()->CheckCollision(_objects[j]->GetRigidbody()))
			{

			}
		}
	}

	int size = _ui.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + j; j < _ui.size(); j++)
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