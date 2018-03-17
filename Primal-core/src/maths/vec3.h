#pragma once

#include <iostream>

namespace primal
{
	namespace maths
	{

		struct vec3
		{
			float x, y, z;

			vec3() = default;
			vec3(const float& ax, const float& ay, const float& az);

			vec3& add(const vec3& other);
			vec3& substract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);

			friend vec3 operator+ (vec3 a, const vec3 &b);
			friend vec3 operator- (vec3 a, const vec3 &b);
			friend vec3 operator* (vec3 a, const vec3 &b);
			friend vec3 operator/ (vec3 a, const vec3 &b);

			friend void operator+= (vec3 &a, const vec3 &b);
			friend void operator-= (vec3 &a, const vec3 &b);
			friend void operator*= (vec3 &a, const vec3 &b);
			friend void operator/= (vec3 &a, const vec3 &b);

			friend bool operator== (const vec3 &a, const vec3 &b);
			friend bool operator!= (const vec3 &a, const vec3 &b);

			friend std::ostream& operator<< (std::ostream& stream, vec3& v);
		};

	}
}