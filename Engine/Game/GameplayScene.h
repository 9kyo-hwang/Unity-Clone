#pragma once
#include "../Source/Scene.h"

namespace Unity
{
	class GameplayScene : public Scene
	{
		using Super = Scene;

	public:
		GameplayScene();
		~GameplayScene() override;

		void Awake() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}