#pragma once
#include "CommonInclude.h"

namespace Unity
{
	class MetaData
	{
	public:
		MetaData();
		virtual ~MetaData();

		std::wstring& GetName() { return _name; }
		void SetName(const std::wstring& name) { _name = name; }

	private:
		std::wstring _name;
	};
}