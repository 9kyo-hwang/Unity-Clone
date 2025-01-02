#include "GameObject.h"
#include "Input.h"

namespace Unity
{
	GameObject::GameObject()
		: _x(0.f)
		, _y(0.f)
		, _speed(0.f)
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
		if (Input::Instance()->GetKey(KeyCode::LeftArrow))
		{
			_x -= 0.01f;
		}
		if (Input::Instance()->GetKey(KeyCode::RightArrow))
		{
			_x += 0.01f;
		}
		if (Input::Instance()->GetKey(KeyCode::UpArrow))
		{
			_y -= 0.01f;
		}
		if (Input::Instance()->GetKey(KeyCode::DownArrow))
		{
			_y += 0.01f;
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