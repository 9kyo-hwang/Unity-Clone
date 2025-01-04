#include "GameplayScene.h"

#include "GameObject.h"
#include "InputManager.h"
#include "Object.h"
#include "Player.h"
#include "SceneManager.h"
#include "SpriteRenderer.h"
#include "Transform.h"

namespace Unity
{
	GameplayScene::GameplayScene()
		: background(nullptr)
	{
		
	}

	GameplayScene::~GameplayScene()
	{
		
	}

	void GameplayScene::Awake()
	{
		{
			background = Object::Instance().Instantiate<Player>(LayerTypes::Background, 100, 100);
			SpriteRenderer* renderer = background->AddComponent<SpriteRenderer>();
			renderer->Load(L"E:\\Github\\Unity-Clone\\Engine\\Resources\\CloudOcean.png");
		}
	}

	void GameplayScene::Update()
	{
		Super::Update();
	}

	void GameplayScene::LateUpdate()
	{
		Super::LateUpdate();

		if (InputManager::Instance().GetKeyDown(KeyCode::N))
		{
			SceneManager::Instance().LoadScene(L"TitleScene");
		}
	}

	void GameplayScene::Render(HDC hdc)
	{
		Super::Render(hdc);

		std::wstring text = std::format(L"GameplayScene");
		::TextOut(hdc, 0, 0, text.c_str(), (int32)text.size());
	}

	void GameplayScene::OnEnter()
	{
		
	}

	void GameplayScene::OnExit()
	{
		Transform* transform = background->GetComponent<Transform>();
		transform->SetPosition(0, 0);
	}

}
