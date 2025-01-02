#include "SpriteRenderer.h"

#include "GameObject.h"
#include "Transform.h"

namespace Unity
{
	SpriteRenderer::SpriteRenderer()
	{
		
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
		HBRUSH blueBrush = CreateSolidBrush(RGB(255, 0, 255));
		HBRUSH oldBrush  = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Transform* transform = GetParent()->GetComponent<Transform>();
		const auto& [x, y] = transform->GetPosition();
		Ellipse(hdc, x, y, 100 + x, 100 + y);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}
