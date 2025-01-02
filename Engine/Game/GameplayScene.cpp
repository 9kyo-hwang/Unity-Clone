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
			Player* background = new Player();

			Transform* transform = background->AddComponent<Transform>();
			transform->SetPosition(0, 0);
			transform->SetName(L"TR");

			SpriteRenderer* renderer = background->AddComponent<SpriteRenderer>();
			renderer->SetName(L"SR");
			renderer->Load(L"E:\\Github\\Unity-Clone\\Engine\\Resources\\CloudOcean.png");

			AddGameObject(background);
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
