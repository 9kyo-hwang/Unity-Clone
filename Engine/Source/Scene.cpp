#include "Scene.h"
#include "GameObject.h"

namespace Unity
{
	Scene::Scene()
		: _gameObjects{}
	{
		
	}

	Scene::~Scene()
	{
		
	}

	void Scene::Awake()
	{
		for (GameObject* gameObject : _gameObjects)
		{
			gameObject->Awake();
		}
	}

	void Scene::Update()
	{
		for (GameObject* gameObject : _gameObjects)
		{
			gameObject->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* gameObject : _gameObjects)
		{
			gameObject->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObject : _gameObjects)
		{
			gameObject->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObject)
	{
		_gameObjects.push_back(gameObject);
	}
}
