#include "SceneManager.h"
#include "Scene.h"

namespace Unity
{
	void SceneManager::Awake()
	{
		
	}

	void SceneManager::Update()
	{
		_activeScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		_activeScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		_activeScene->Render(hdc);
	}

}