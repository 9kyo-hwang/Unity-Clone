#pragma once
#include "CommonInclude.h"
#include "MetaData.h"

namespace Unity
{
	class Scene : public MetaData
	{
	public:
		Scene();
		~Scene() override;

		virtual void Awake();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(class GameObject* gameObject);

	private:
		std::vector<class GameObject*> _gameObjects;
	};
}
