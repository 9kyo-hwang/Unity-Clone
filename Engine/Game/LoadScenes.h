#pragma once
#include "../Source/SceneManager.h"
#include "GameplayScene.h"
#include "TitleScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\Game.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\Game.lib")
#endif

namespace Unity
{
	inline void LoadScenes()
	{
		SceneManager::Instance().CreateScene<TitleScene>(L"TitleScene");
		//SceneManager::Instance().CreateScene<LobbyScene>(L"LobbyScene");
		SceneManager::Instance().CreateScene<GameplayScene>(L"GameplayScene");

		SceneManager::Instance().LoadScene(L"GameplayScene");
	}
}
