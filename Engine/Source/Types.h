#pragma once

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

namespace Unity
{
	struct Vector2
	{
		float x;
		float y;

		Vector2()
			: x(0.f)
			, y(0.f)
		{}

		Vector2(float x, float y)
			: x(x)
			, y(y)
		{}

		Vector2(POINT point)
			: x(static_cast<float>(point.x))
			, y(static_cast<float>(point.y))
		{}

		Vector2 operator+(const Vector2& other) const { return { x + other.x, y + other.y }; }
		Vector2 operator-(const Vector2& other) const { return { x - other.x, y - other.y }; }
		Vector2 operator*(const float value) const { return { x * value, y * value }; }
		void operator+=(const Vector2& other) {x += other.x; y += other.y; }
		void operator-=(const Vector2& other) { x -= other.x; y -= other.y; }
		void operator*=(const float value) { x *= value; y *= value; }

		float GetMagnitudeSquared() const { return x * x + y * y; }
		float GetMagnitude() const { return ::sqrt(GetMagnitudeSquared()); }

		void Normalize()
		{
			const float magnitude = GetMagnitude();
			if (magnitude < std::numeric_limits<float>::epsilon())
			{
				return;
			}

			x /= magnitude;
			y /= magnitude;
		}

		float Dot(const Vector2& other) const { return x * other.x + y * other.y; }
		float Cross(const Vector2& other) const { return x * other.y - y * other.x; }
	};
}