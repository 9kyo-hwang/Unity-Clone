#include "GameObject.h"
#include "InputManager.h"
#include "TimeManager.h"

namespace Unity
{
	GameObject::GameObject()
	{
		
	}

	GameObject::~GameObject()
	{
		for (Component* component : _components)
		{
			delete component;
			component = nullptr;
		}
	}

	void GameObject::Awake()
	{
		for (Component* component : _components)
		{
			component->Awake();
		}
	}

	void GameObject::Update()
	{
		for (Component* component : _components)
		{
			component->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* component : _components)
		{
			component->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		assert(hdc != nullptr);

		for (Component* component : _components)
		{
			component->Render(hdc);
		}
	}
}
