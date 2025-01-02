#pragma once

#include "CommonInclude.h"
#include "Singleton.h"

namespace Unity
{
	class Time : public Singleton<Time>
	{
	public:
		Time();
		~Time() override {}

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