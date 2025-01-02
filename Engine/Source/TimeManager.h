#pragma once

#include "CommonInclude.h"
#include "Singleton.h"

namespace Unity
{
	class TimeManager : public Singleton<TimeManager>
	{
	public:
		TimeManager();
		~TimeManager() override {}

		void Awake();
		void Update();
		void Render(HDC hdc);

		float DeltaTime() const { return _deltaTime; }

	private:
		uint64 _frequency;
		uint64 _prevCount;
		float _deltaTime;
	};
}