#pragma once
#include "CommonInclude.h"

namespace Unity
{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Awake();
		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	public:
		const std::pair<float, float>& GetPosition() const { return { _x, _y }; }
		void SetPosition(float x, float y) { _x = x; _y = y; }

	private:
		float _x;
		float _y;
		float _speed;
	};
}
