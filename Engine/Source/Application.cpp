#include "Application.h"
#include "GameObject.h"

namespace Unity
{
	Application::Application()
		: _hWnd(nullptr)
		, _hdc(nullptr)
	{
		
	}

	Application::~Application()
	{
		
	}

	void Application::Awake(HWND hWnd)
	{
		_hWnd = hWnd;
		_hdc = GetDC(hWnd);
		_player.Awake();
	}

	void Application::Start()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		_player.Update();
	}

	void Application::LateUpdate()
	{
		_player.LateUpdate();
	}

	void Application::Render()
	{
		_player.Render(_hdc);
	}

}