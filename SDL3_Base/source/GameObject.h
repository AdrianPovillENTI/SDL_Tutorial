#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
using namespace std;

class GameObject : public ImageObject
{
protected:

	bool active;
	vector<GameObject*> children;
	GameObject * parent;
	Vector2 parentOffset;

public:

	GameObject(string _spritePath);
	~GameObject ( ) { }

	virtual void Start ( ) { }
	void Update() override;

	void SetActive ( bool isActive ) { active = isActive; }
	bool GetActive (  ) { return active; }

	void AddChild(GameObject* child, Vector2 offset);
	void RemoveChild(GameObject* gameObject);
};
