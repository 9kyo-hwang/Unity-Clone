#pragma once
#include "CommonInclude.h"
#include "Entity.h"

namespace Unity
{
	class GameObject;

	class Layer : public Entity
	{
		using Super = Entity;

	public:
		Layer();
		~Layer() override;

		virtual void Awake();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		LayerTypes _type;
		std::vector<GameObject*> _gameObjects;
	};
}