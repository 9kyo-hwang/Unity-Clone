#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"

namespace Unity
{
	SpriteRenderer::SpriteRenderer()
		: _image(nullptr)
		, _width(0)
		, _height(0)
	{
		name = L"SR";
	}

	SpriteRenderer::~SpriteRenderer()
	{
		
	}

	void SpriteRenderer::Awake()
	{
		
	}

	void SpriteRenderer::Update()
	{
		
	}

	void SpriteRenderer::LateUpdate()
	{
		
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		Transform* transform = GetParent()->GetComponent<Transform>();
		const auto& [x, y] = transform->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(_image, Gdiplus::Rect(x, y, _width, _height));
	}

	void SpriteRenderer::Load(const std::wstring& path)
	{
		_image = Gdiplus::Image::FromFile(path.c_str());
		_width = _image->GetWidth();
		_height = _image->GetHeight();
	}
}
