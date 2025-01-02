#include "GameplayScene.h"

#include "GameObject.h"
#include "Player.h"
#include "SpriteRenderer.h"
#include "Transform.h"

namespace Unity
{
	GameplayScene::GameplayScene()
	{
		
	}

	GameplayScene::~GameplayScene()
	{
		
	}

	void GameplayScene::Awake()
	{
		{
			Player* player = new Player();

			Transform* transform = player->AddComponent<Transform>();
			transform->SetPosition(800, 450);
			transform->SetName(L"TR");

			SpriteRenderer* renderer = player->AddComponent<SpriteRenderer>();
			renderer->SetName(L"SR");

			AddGameObject(player);
		}
		{
			Player* player = new Player();

			Transform* transform = player->AddComponent<Transform>();
			transform->SetPosition(300, 450);
			transform->SetName(L"TR");

			SpriteRenderer* renderer = player->AddComponent<SpriteRenderer>();
			renderer->SetName(L"SR");

			AddGameObject(player);
		}
		{
			Player* player = new Player();

			Transform* transform = player->AddComponent<Transform>();
			transform->SetPosition(100, 650);
			transform->SetName(L"TR");

			SpriteRenderer* renderer = player->AddComponent<SpriteRenderer>();
			renderer->SetName(L"SR");

			AddGameObject(player);
		}
	}

	void GameplayScene::Update()
	{
		Super::Update();
	}

	void GameplayScene::LateUpdate()
	{
		Super::LateUpdate();
	}

	void GameplayScene::Render(HDC hdc)
	{
		Super::Render(hdc);
	}
}
