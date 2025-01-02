#pragma once
#include "CommonInclude.h"
#include "Component.h"

namespace Unity
{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Awake();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template<typename ComponentType>
		ComponentType* AddComponent()
		{
			ComponentType* component = new ComponentType();
			component->SetParent(this);
			_components.push_back(component);
			return component;
		}

		template<typename ComponentType>
		ComponentType* GetComponent()
		{
			for (Component* component : _components)
			{
				if (ComponentType* target = dynamic_cast<ComponentType*>(component))
				{
					return target;
				}
			}

			return nullptr;
		}

	private:
		std::vector<Component*> _components;
	};
}
