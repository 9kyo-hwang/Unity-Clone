#pragma once
#include "Component.h"

namespace Unity
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer() override;

		void Awake() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Load(const std::wstring& path);

	private:
		Gdiplus::Image* _image;
		uint32 _width;
		uint32 _height;
	};
}
