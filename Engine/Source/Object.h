#pragma once
#include "Enums.h"
#include "Layer.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Singleton.h"
#include "Transform.h"

namespace Unity
{
	class Object : public Singleton<Object>
	{
	public:
		template<typename T>
		T* Instantiate(LayerTypes type)
		{
			T* gameObject = new T();
			Scene* activeScene = SceneManager::Instance().GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);
			return gameObject;
		}

		template<typename T>
		T* Instantiate(LayerTypes type, Vector2 position)
		{
			T* gameObject = Instantiate<T>(type);
			gameObject->GetComponent<Transform>()->SetPosition(position);
			return gameObject;
		}

		template<typename T>
		T* Instantiate(LayerTypes type, float x, float y)
		{
			return Instantiate<T>(type, Vector2(x, y));
		}
	};
}
