#include "TimeManager.h"

namespace Unity
{
	Time::Time()
		: _frequency(0)
		, _prevCount(0)
		, _deltaTime(0.f)
	{
		
	}

	void Time::Awake()
	{
		::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(OUT &_frequency));
		::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(OUT &_prevCount));
	}

	void Time::Update()
	{
		uint64 currentCount;
		::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(OUT &currentCount));

		_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
		_prevCount = currentCount;
	}

	void Time::Render(HDC hdc)
	{
		// legacy
		//wchar_t str[50] = L"";
		//swprintf_s(str, 50, L"Time: %f", _deltaTime);
		//int32 len = wcsnlen_s(str, 50);
		//TextOut(hdc, 0, 0, str, len);

		// C++20
		std::wstring text = std::format(L"FPS: {0}", (int32)(1 / _deltaTime));
		::TextOut(hdc, 0, 0, text.c_str(), (int32)text.size());
	}
}