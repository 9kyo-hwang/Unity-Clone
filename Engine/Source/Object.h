#pragma once
#include "CommonInclude.h"

namespace Unity
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		std::wstring& GetName() { return _name; }
		void SetName(const std::wstring& name) { _name = name; }

	private:
		std::wstring _name;
	};
}