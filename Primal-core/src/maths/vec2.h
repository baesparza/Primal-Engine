#pragma once

#include <iostream>

namespace primal
{
	namespace maths
	{

		struct vec2
		{
			float x, y;

			vec2() = default;
			vec2(const float& ax, const float& ay);

			vec2& add(const vec2& other);
			vec2& substract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& divide(const vec2& other);

			friend vec2 operator+ (vec2 a, const vec2 &b);
			friend vec2 operator- (vec2 a, const vec2 &b);
			friend vec2 operator* (vec2 a, const vec2 &b);
			friend vec2 operator/ (vec2 a, const vec2 &b);

			friend void operator+= (vec2 &a, const vec2 &b);
			friend void operator-= (vec2 &a, const vec2 &b);
			friend void operator*= (vec2 &a, const vec2 &b);
			friend void operator/= (vec2 &a, const vec2 &b);

			friend bool operator== (const vec2 &a, const vec2 &b);
			friend bool operator!= (const vec2 &a, const vec2 &b);

			friend std::ostream& operator<< (std::ostream& stream, vec2& v);
		};

	}
}