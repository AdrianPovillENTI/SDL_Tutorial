#pragma once

#include "Object.h"
#include "Bullet.h"
#include <queue>

#define SPAWNER Spawner::Instance()

class Spawner
{
private:
	Spawner() = default;
	Spawner(Spawner&) = delete;
	Spawner& operator= (const Spawner&) = delete;

public:
	std::queue<Object*> spawnedObjects;
	static Spawner& Instance()
	{
		static Spawner spawner;
		return spawner;
	}


	void SpawnObject(Object* obj) { spawnedObjects.push(obj); }
	Bullet* SpawnBullet(Transform t, Vector2 offset) 
	{ 
		t.position += offset;
        Bullet * obj = new Bullet ( t );
		spawnedObjects.push(obj); 
		return obj;
	}
	bool AreObjectsPendingSpawn ( ) { return !spawnedObjects.empty ( ); }
	Object* GetSpawnedObjects()
	{
		if (!AreObjectsPendingSpawn())
			return nullptr;

		Object* temp = spawnedObjects.front();
		spawnedObjects.pop();
		return temp;
	}

	void ClearSpawner()
	{
		while (AreObjectsPendingSpawn())
		{
			delete spawnedObjects.front();
			spawnedObjects.pop();
		}
	}
};

