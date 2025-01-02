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
		if (Input::Instance().GetKey(KeyCode::LeftArrow))
		{
			_x -= _speed * Time::Instance().DeltaTime();
		}
		if (Input::Instance().GetKey(KeyCode::RightArrow))
		{
			_x += _speed * Time::Instance().DeltaTime();
		}
		if (Input::Instance().GetKey(KeyCode::UpArrow))
		{
			_y -= _speed * Time::Instance().DeltaTime();
		}
		if (Input::Instance().GetKey(KeyCode::DownArrow))
		{
			_y += _speed * Time::Instance().DeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{
		
	}

	void GameObject::Render(HDC hdc)
	{
		assert(hdc != nullptr);

		Rectangle(hdc, 100 + _x, 100 + _y, 200 + _x, 200 + _y);
	}
}
