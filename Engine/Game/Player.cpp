#include "Player.h"

#include "InputManager.h"
#include "TimeManager.h"
#include "Transform.h"

namespace Unity
{
	Player::Player()
		: _speed(500.f)
	{
		
	}

	Player::~Player()
	{
		
	}

	void Player::Awake()
	{
		Super::Awake();
	}

	void Player::Update()
	{
		Super::Update();

		if (InputManager::Instance().GetKey(KeyCode::UpArrow))
		{
			Transform* transform = GetComponent<Transform>();
			auto [x, y] = transform->GetPosition();
			y -= _speed * TimeManager::Instance().DeltaTime();
			transform->SetPosition(x, y);
		}
		if (InputManager::Instance().GetKey(KeyCode::DownArrow))
		{
			Transform* transform = GetComponent<Transform>();
			auto [x, y] = transform->GetPosition();
			y += _speed * TimeManager::Instance().DeltaTime();
			transform->SetPosition(x, y);
		}
		if (InputManager::Instance().GetKey(KeyCode::LeftArrow))
		{
			Transform* transform = GetComponent<Transform>();
			auto [x, y] = transform->GetPosition();
			x -= _speed * TimeManager::Instance().DeltaTime();
			transform->SetPosition(x, y);
		}
		if (InputManager::Instance().GetKey(KeyCode::RightArrow))
		{
			Transform* transform = GetComponent<Transform>();
			auto [x, y] = transform->GetPosition();
			x += _speed * TimeManager::Instance().DeltaTime();
			transform->SetPosition(x, y);
		}
	}

	void Player::LateUpdate()
	{
		Super::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		Super::Render(hdc);
	}
}
