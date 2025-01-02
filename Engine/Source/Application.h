#pragma once
#include "CommonInclude.h"
#include "GameObject.h"

namespace Unity
{
	class Application
	{
	public:
		Application();
		~Application();

		void Awake(HWND hWnd);	// Initialize
		void Start();	// Start
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND _hWnd;
		HDC _hdc;

		// 일종의 플레이어같은...
		GameObject _player;
	};
}