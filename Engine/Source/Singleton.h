#pragma once

namespace Unity
{
	template<typename T>
	class Singleton
	{
	public:
		Singleton() = default;
		virtual ~Singleton() = default;
		Singleton(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton& operator=(Singleton&&) = delete;

		static T& Instance()
		{
			static T instance;
			return instance;
		}
	};
}