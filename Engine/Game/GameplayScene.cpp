#include "GameplayScene.h"

#include "GameObject.h"

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
		AddGameObject(new GameObject());
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
