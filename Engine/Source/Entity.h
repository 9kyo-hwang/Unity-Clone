#pragma once
#include "CommonInclude.h"

namespace Unity
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

	public:
		std::wstring name;
	};
}
