#pragma once
#include "Entity.h"

namespace Unity
{
	class GameObject;

	class Component : public Entity
	{
		using Super = Entity;

	public:
		Component();
		~Component() override;

		virtual void Awake();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		GameObject* GetParent() const { return _parent; }
		void SetParent(GameObject* parent) { _parent = parent; }

	private:
		GameObject* _parent = nullptr;
	};

}