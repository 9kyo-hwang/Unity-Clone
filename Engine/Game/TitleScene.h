#pragma once
#include "../Source/Scene.h"

namespace Unity
{
	class TitleScene : public Scene
	{
		using Super = Scene;
	public:
		TitleScene();
		~TitleScene() override;

		void Awake() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;
	};
}