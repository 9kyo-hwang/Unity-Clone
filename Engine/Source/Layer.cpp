#include "Layer.h"
#include "GameObject.h"

namespace Unity
{
	Layer::Layer()
		: _type(LayerTypes::None)
		, _gameObjects{}
	{
		
	}

	Layer::~Layer()
	{

	}

	void Layer::Awake()
	{
		for (GameObject* gameObject : _gameObjects)
		{
			if (gameObject)
			{
				gameObject->Awake();
			}
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObject : _gameObjects)
		{
			if (gameObject)
			{
				gameObject->Update();
			}
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObject : _gameObjects)
		{
			if (gameObject)
			{
				gameObject->LateUpdate();
			}
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObject : _gameObjects)
		{
			if (gameObject)
			{
				gameObject->Render(hdc);
			}
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject)
		{
			_gameObjects.push_back(gameObject);
		}
	}
}