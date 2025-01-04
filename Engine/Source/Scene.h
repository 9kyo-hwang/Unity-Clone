#pragma once
#include "CommonInclude.h"
#include "Entity.h"

namespace Unity
{
	class GameObject;
	class Layer;
	enum class LayerTypes;

	class Scene : public Entity
	{
	public:
		Scene();
		~Scene() override;

		virtual void Awake();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, LayerTypes type) const;
		Layer* GetLayer(LayerTypes type) const { return _layers[static_cast<int32>(type)]; }

	private:
		std::vector<Layer*> _layers;
	};
}
