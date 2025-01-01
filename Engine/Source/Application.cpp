#include "Application.h"

namespace Unity
{
	Application::Application()
		: _hWnd(nullptr)
		, _hdc(nullptr)
		, _speed(0.f)
		, _x(0.f)
		, _y(0.f)
	{
		
	}

	Application::~Application()
	{
		
	}

	void Application::Awake(HWND hWnd)
	{
		_hWnd = hWnd;
		_hdc = GetDC(hWnd);
	}

	void Application::Start()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		_speed += 0.01f;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			_x -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			_x += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			_y -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			_y += 0.01f;
		}
	}

	void Application::LateUpdate()
	{
		
	}

	void Application::Render()
	{
		Rectangle(_hdc, 100 + _x, 100 + _y, 200 + _x, 200 + _y);
	}

}