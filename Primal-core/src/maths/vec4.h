#pragma once

#include <iostream>

namespace primal
{
	namespace maths
	{

		struct vec4
		{
			float x, y, z, w;

			vec4() = default;
			vec4(const float& ax, const float& ay, const float& az, const float& aw);
			vec4(const float & n);


			vec4& add(const vec4& other);
			vec4& substract(const vec4& other);
			vec4& multiply(const vec4& other);
			vec4& divide(const vec4& other);

			friend vec4 operator+ (vec4 a, const vec4 &b);
			friend vec4 operator- (vec4 a, const vec4 &b);
			friend vec4 operator* (vec4 a, const vec4 &b);
			friend vec4 operator/ (vec4 a, const vec4 &b);

			friend void operator+= (vec4 &a, const vec4 &b);
			friend void operator-= (vec4 &a, const vec4 &b);
			friend void operator*= (vec4 &a, const vec4 &b);
			friend void operator/= (vec4 &a, const vec4 &b);

			friend bool operator== (const vec4 &a, const vec4 &b);
			friend bool operator!= (const vec4 &a, const vec4 &b);

			friend std::ostream& operator<< (std::ostream& stream, vec4& v);
		};

	}
}