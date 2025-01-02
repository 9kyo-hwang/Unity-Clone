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
		HDC _hFrontDC;

		// 일종의 플레이어같은...
		GameObject _player;

	private:  // for Back Buffering
		HDC _hBackDC;
		HBITMAP _hBackBmp;
		RECT _rect;
	};
}