#include "TitleScene.h"

#include "InputManager.h"
#include "SceneManager.h"

namespace Unity
{
	TitleScene::TitleScene()
	{
		
	}

	TitleScene::~TitleScene()
	{
		
	}

	void TitleScene::Awake()
	{
		Super::Awake();
	}

	void TitleScene::Update()
	{
		Super::Update();
	}

	void TitleScene::LateUpdate()
	{
		Super::LateUpdate();

		if (InputManager::Instance().GetKeyDown(KeyCode::N))
		{
			SceneManager::Instance().LoadScene(L"GameplayScene");
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Super::Render(hdc);

		std::wstring text = std::format(L"TitleScene");
		::TextOut(hdc, 0, 0, text.c_str(), (int32)text.size());
	}

	void TitleScene::OnEnter()
	{
		Super::OnEnter();
	}

	void TitleScene::OnExit()
	{
		Super::OnExit();
	}
}
