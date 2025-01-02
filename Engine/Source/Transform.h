#pragma once
#include "Component.h"

namespace Unity
{
    using Vector2Int = std::pair<int, int>;

    class Transform : public Component
    {
    public:
        Transform();
        ~Transform() override;

        void Awake() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

        Vector2Int GetPosition() const { return _position; }
        void SetPosition(const int x, const int y) { _position.first = x; _position.second = y; }

    private:
        Vector2Int _position;
    };
}