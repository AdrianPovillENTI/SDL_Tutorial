#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "string"
using namespace std;

class GameObject : public ImageObject
{
protected:
	bool active;
	vector<GameObject*> children;
	GameObject * parent;
	Vector2 parentOffset;
public:
	GameObject ( string _spritePath) : ImageObject ( _spritePath , Vector2 ( 0.0f , 0.0f ) , Vector2 ( 1306.0f , 1324.0f ) )
	{
		active = true;
		_physics->SetLinearDrag ( 0.1f );
		_physics->SetAngularDrag ( 0.1f );

		parent = nullptr;
		parentOffset = Vector2::Zero;
	}
	~GameObject ( )
	{
	}
	virtual void Start ( ) { }
	void Update ( ) override
	{
		if ( !active ) return;

		Object::Update ( );

		if ( parent != nullptr )
			_transform->position = parent->_transform->position + parentOffset;
	}
	void SetActive ( bool isActive )
	{
		active = isActive;
	}
	bool GetActive (  )
	{
		return active;
	}
	void AddChild ( GameObject * child, Vector2 offset )
	{
		child->parent = this;
		child->parentOffset = offset;
		children.push_back ( child );

		child->_transform->position = _transform->position + offset;
	}
	void RemoveChild ( GameObject* gameObject )
	{
		vector<GameObject *>::iterator it = std::find ( children.begin ( ) , children.end ( ) , gameObject );
		if ( it != children.end())
		{
			children.erase ( it );
			gameObject->parent = nullptr;
			gameObject->parentOffset = Vector2::Zero;
		}
	}
};
