#pragma once

#include <iostream>

namespace primal
{
	namespace maths
	{

		struct vect3
		{
			float x, y, z;

			vect3() = default;
			vect3(const float& ax, const float& ay, const float& az);

			vect3& add(const vect3& other);
			vect3& substract(const vect3& other);
			vect3& multiply(const vect3& other);
			vect3& divide(const vect3& other);

			friend vect3 operator+ (vect3 a, const vect3 &b);
			friend vect3 operator- (vect3 a, const vect3 &b);
			friend vect3 operator* (vect3 a, const vect3 &b);
			friend vect3 operator/ (vect3 a, const vect3 &b);

			friend void operator+= (vect3 &a, const vect3 &b);
			friend void operator-= (vect3 &a, const vect3 &b);
			friend void operator*= (vect3 &a, const vect3 &b);
			friend void operator/= (vect3 &a, const vect3 &b);

			friend bool operator== (const vect3 &a, const vect3 &b);
			friend bool operator!= (const vect3 &a, const vect3 &b);

			friend std::ostream& operator<< (std::ostream& stream, vect3& v);
		};

	}
}