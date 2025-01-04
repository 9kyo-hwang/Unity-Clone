#include "Scene.h"
#include "GameObject.h"
#include "Layer.h"

namespace Unity
{
	Scene::Scene()
		: _layers(static_cast<size_t>(LayerTypes::Max), new Layer())
	{
		
	}

	Scene::~Scene()
	{
		
	}

	void Scene::Awake()
	{
		for (Layer* layer : _layers)
		{
			if (layer)
			{
				layer->Awake();
			}
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : _layers)
		{
			if (layer)
			{
				layer->Update();
			}
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : _layers)
		{
			if (layer)
			{
				layer->LateUpdate();
			}
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : _layers)
		{
			if (layer)
			{
				layer->Render(hdc);
			}
		}
	}

	void Scene::OnEnter()
	{

	}

	void Scene::OnExit()
	{

	}

	void Scene::AddGameObject(GameObject* gameObject, LayerTypes type) const
	{
		if (gameObject)
		{
			_layers[(uint32)type]->AddGameObject(gameObject);
		}
	}
}
