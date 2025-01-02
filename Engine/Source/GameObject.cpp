#include "GameObject.h"
#include "InputManager.h"
#include "TimeManager.h"

namespace Unity
{
	GameObject::GameObject()
		: _x(0.f)
		, _y(0.f)
		, _speed(500.f)
	{
		
	}

	GameObject::~GameObject()
	{
		
	}

	void GameObject::Awake()
	{
		
	}

	void GameObject::Start()
	{
		
	}

	void GameObject::Update()
	{
		if (InputManager::Instance().GetKey(KeyCode::LeftArrow))
		{
			_x -= _speed * TimeManager::Instance().DeltaTime();
		}
		if (InputManager::Instance().GetKey(KeyCode::RightArrow))
		{
			_x += _speed * TimeManager::Instance().DeltaTime();
		}
		if (InputManager::Instance().GetKey(KeyCode::UpArrow))
		{
			_y -= _speed * TimeManager::Instance().DeltaTime();
		}
		if (InputManager::Instance().GetKey(KeyCode::DownArrow))
		{
			_y += _speed * TimeManager::Instance().DeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{
		
	}

	void GameObject::Render(HDC hdc)
	{
		assert(hdc != nullptr);

		Ellipse(hdc, _x, _y, 100 + _x, 100 + _y);
	}
}
