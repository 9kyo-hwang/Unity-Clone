#pragma once
#include "CommonInclude.h"
#include "Singleton.h"

namespace Unity
{
	enum class KeyboardState
	{
		None,
		Down,
		Press,
		Up,
		End
	};

	enum class KeyCode
	{
		LeftMouseButton = VK_LBUTTON,
		RightMouseButton = VK_RBUTTON,

		UpArrow = VK_UP,
		DownArrow = VK_DOWN,
		LeftArrow = VK_LEFT,
		RightArrow = VK_RIGHT,
		Space = VK_SPACE,

		Alpha1 = '1', Alpha2 = '2', Alpha3 = '3', Alpha4 = '4', Alpha5 = '5',
		Alpha6 = '6', Alpha7 = '7', Alpha8 = '8', Alpha9 = '9', Alpha0 = '0',

		Q = 'Q', W = 'W', E = 'E', R = 'R', T = 'T', Y = 'Y', U = 'U', I = 'I', O = 'O', P = 'P',
		A = 'A', S = 'S', D = 'D', F = 'F', G = 'G', H = 'H', J = 'J', K = 'K', L = 'L',
		Z = 'Z', X = 'X', C = 'C', V = 'V', B = 'B', N = 'N', M = 'M',
		End
	};

	constexpr int32 KeyCount = static_cast<int32>(UINT8_MAX) + 1;

	class InputManager final : public Singleton<InputManager>
	{
	public:
		~InputManager() override {}

		void Awake();
		void Update();

		bool GetKeyDown(KeyCode key) const { return GetKeyState(key) == KeyboardState::Down; }
		bool GetKey(KeyCode key) const { return GetKeyState(key) == KeyboardState::Press; }
		bool GetKeyUp(KeyCode key) const { return GetKeyState(key) == KeyboardState::Up; }

	private:
		KeyboardState GetKeyState(KeyCode key) const { return _states[static_cast<int32>(key)]; }

	private:
		std::vector<KeyboardState> _states;
	};
}
