#pragma once
#include "CommonInclude.h"
#include "Singleton.h"

namespace Unity
{
	class Scene;

	class SceneManager : public Singleton<SceneManager>
	{
	public:
		template<typename SceneType>
		Scene* CreateScene(const std::wstring& name)
		{
			SceneType* scene = new SceneType();
			scene->SetName(name);
			scene->Awake();

			return _scenes[name] = scene;
		}

		Scene* LoadScene(const std::wstring& name)
		{
			if (_scenes.contains(name))
			{
				return _activeScene = _scenes[name];
			}

			return nullptr;
		}

	public:
		void Awake();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		std::unordered_map<std::wstring, Scene*> _scenes;
		Scene* _activeScene = nullptr;
	};
}
