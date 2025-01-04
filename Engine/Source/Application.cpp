#include "Application.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

namespace Unity
{
	Application::Application()
		: _hWnd(nullptr)
		, _hFrontDC(nullptr)
		, _hBackDC(nullptr)
		, _hBackBmp(nullptr)
		, _rect{}
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
		::DeleteObject(::SelectObject(_hBackDC, _hBackBmp));  // delete Front Bitmap

		InputManager::Instance().Awake();
		TimeManager::Instance().Awake();
		SceneManager::Instance().Awake();
	}

	void Application::Start()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		InputManager::Instance().Update();
		TimeManager::Instance().Update();
		SceneManager::Instance().Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::Instance().LateUpdate();
	}

	void Application::Render()
	{
		TimeManager::Instance().Render(_hBackDC);
		SceneManager::Instance().Render(_hBackDC);

		::BitBlt(_hFrontDC, 0, 0, _rect.right, _rect.bottom, _hBackDC, 0, 0, SRCCOPY);
		::PatBlt(_hBackDC, 0, 0, _rect.right, _rect.bottom, WHITENESS);
	}
}
