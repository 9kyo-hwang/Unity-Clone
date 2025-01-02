#include "Input.h"

namespace Unity
{
	void Input::Awake()
	{
		_states.resize(KeyCount, KeyboardState::None);
	}

	void Input::Update()
	{
		BYTE ascii[KeyCount]{};
		if (!::GetKeyboardState(ascii))
		{
			return;
		}

		for (int32 key = 0; key < KeyCount; ++key)
		{
			KeyboardState& state = _states[key];
			if (ascii[key] & 0x80)
			{
				if (state == KeyboardState::Press || state == KeyboardState::Down)
				{
					state = KeyboardState::Press;
				}
				else
				{
					state = KeyboardState::Down;
				}
			}
			else
			{
				if (state == KeyboardState::Press || state == KeyboardState::Down)
				{
					state = KeyboardState::Up;
				}
				else
				{
					state = KeyboardState::None;
				}
			}
		}
	}
}