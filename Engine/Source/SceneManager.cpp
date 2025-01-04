#include "SceneManager.h"
#include "Scene.h"

namespace Unity
{
	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (_activeScene)
		{
			_activeScene->OnExit();
		}

		if (_scenes.contains(name))
		{
			_activeScene = _scenes[name];
			_activeScene->OnEnter();
			return _activeScene;
		}

		return nullptr;
	}

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