#pragma once
#include "Component.h"

namespace Unity
{
    class Transform : public Component
    {
    public:
        Transform();
        ~Transform() override;

        void Awake() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        Vector2 GetPosition() const { return _position; }
        void SetPosition(const float x, const float y) { _position.x = x; _position.y = y; }
        void SetPosition(const Vector2& other) { _position = other; }

    private:
        Vector2 _position;
    };
}