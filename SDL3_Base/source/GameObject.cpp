#include "GameObject.h"

GameObject::GameObject(string _spritePath): ImageObject(_spritePath, Vector2(0.0f, 0.0f), Vector2(1360.0f, 768.0f))
{
	active = true;
	_physics->SetLinearDrag(0.1f);
	_physics->SetAngularDrag(0.1f);

	parent = nullptr;
	parentOffset = Vector2::Zero;
}

GameObject::~GameObject() 
{ 
    for (GameObject* child : children) {
        if (child != nullptr) {
            child->parent = nullptr;
        }
    }
    if (parent != nullptr) {
        parent->RemoveChild(this);
    }
}
void GameObject::Update()
{
	if (!active) return;

	Object::Update();

	if (parent != nullptr)
		_transform->position = parent->_transform->position + parentOffset;
}

void GameObject::AddChild(GameObject* child, Vector2 offset)
{
	child->parent = this;
	child->parentOffset = offset;
	children.push_back(child);

	child->_transform->position = _transform->position + offset;
}

void GameObject::RemoveChild(GameObject* gameObject)
{
	vector<GameObject*>::iterator it = std::find(children.begin(), children.end(), gameObject);
	if (it != children.end())
	{
		children.erase(it);
		gameObject->parent = nullptr;
		gameObject->parentOffset = Vector2::Zero;
	}
}
