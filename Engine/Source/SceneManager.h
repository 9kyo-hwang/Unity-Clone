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
			scene->name = name;

			_activeScene = scene;  // 이 과정을 해주지 않으면 Object Instantiate에서 Scene nullptr exception
			_scenes[name] = scene;

			scene->Awake();
			return scene;
		}

		Scene* LoadScene(const std::wstring& name);
		Scene* GetActiveScene() const { return _activeScene; }

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
