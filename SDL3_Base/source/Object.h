#pragma once
#include "Vector2.h"
#include "Renderer.h"
#include "ImageRenderer.h"
#include "Rigidbody.h"
#include <SDL3/SDL.h>
#include <string>
class Object
{
private: 
	bool _isPendingDestroy = false;
protected:
	Rigidbody* _physics;
	Transform* _transform;
	Renderer* _renderer = nullptr;

public:
	Object() 
	{ 
		_transform = new Transform();
		_physics = new Rigidbody(_transform);
	}

	~Object() {

		delete _transform;
		_transform = nullptr;

		delete _physics;
		_physics = nullptr;

		delete _renderer;
		_renderer = nullptr;
	}

	virtual void Update() 
	{ 	
		if (_physics != nullptr)
			_physics->Update ( 1.0f / 60.0f );
		if(_renderer != nullptr )
		_renderer->Update(0.02f); 
	}

	virtual void Render()
	{
		if ( _renderer != nullptr )
		_renderer->Render();
	}	
	Transform* GetTransform() const { return _transform; }

	bool IsPendingDestroy() const { return _isPendingDestroy; }
	virtual void Destroy() { _isPendingDestroy = true; }

	Rigidbody* GetRigidbody() { return _physics; }
};