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

			_activeScene = scene;  // �� ������ ������ ������ Object Instantiate���� Scene nullptr exception
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
