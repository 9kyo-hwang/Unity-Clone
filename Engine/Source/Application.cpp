#include "Application.h"
#include "GameObject.h"
#include "InputManager.h"
#include "TimeManager.h"

namespace Unity
{
	Application::Application()
		: _hWnd(nullptr)
		, _hFrontDC(nullptr)
		, _hBackDC(nullptr)
		, _hBackBmp(nullptr)
		, _rect({})
	{
	}

	Application::~Application()
	{
		
	}

	void Application::Awake(HWND hWnd)
	{
		_hWnd = hWnd;
		_hFrontDC = GetDC(hWnd);

		::GetClientRect(_hWnd, &_rect);
		_hBackDC = ::CreateCompatibleDC(_hFrontDC);
		_hBackBmp = ::CreateCompatibleBitmap(_hFrontDC, _rect.right, _rect.bottom);
		HBITMAP hFrontBmp = static_cast<HBITMAP>(::SelectObject(_hBackDC, _hBackBmp));
		::DeleteObject(hFrontBmp);

		_player.Awake();

		Input::Instance().Awake();
		Time::Instance().Awake();
	}

	void Application::Start()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Instance().Update();
		Time::Instance().Update();

		_player.Update();
	}

	void Application::LateUpdate()
	{
		_player.LateUpdate();
	}

	void Application::Render()
	{
		Time::Instance().Render(_hBackDC);

		_player.Render(_hBackDC);

		::BitBlt(_hFrontDC, 0, 0, _rect.right, _rect.bottom, _hBackDC, 0, 0, SRCCOPY);
		::PatBlt(_hBackDC, 0, 0, _rect.right, _rect.bottom, WHITENESS);
	}
}
