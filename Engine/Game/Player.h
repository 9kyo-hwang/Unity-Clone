#pragma once
#include "../Source/GameObject.h"

namespace Unity
{
    class Player : public GameObject
    {
        using Super = GameObject;

    public:
        Player();
        ~Player() override;

        void Awake() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;

    private:
        float _speed;
    };
}

