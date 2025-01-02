#include "Player.h"

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