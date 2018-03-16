#pragma once

#include <iostream>

namespace primal
{
	namespace maths
	{

		struct vect4
		{
			float x, y, z, w;

			vect4() = default;
			vect4(const float& ax, const float& ay, const float& az, const float& aw);

			vect4& add(const vect4& other);
			vect4& substract(const vect4& other);
			vect4& multiply(const vect4& other);
			vect4& divide(const vect4& other);

			friend vect4 operator+ (vect4 a, const vect4 &b);
			friend vect4 operator- (vect4 a, const vect4 &b);
			friend vect4 operator* (vect4 a, const vect4 &b);
			friend vect4 operator/ (vect4 a, const vect4 &b);

			friend void operator+= (vect4 &a, const vect4 &b);
			friend void operator-= (vect4 &a, const vect4 &b);
			friend void operator*= (vect4 &a, const vect4 &b);
			friend void operator/= (vect4 &a, const vect4 &b);

			friend bool operator== (const vect4 &a, const vect4 &b);
			friend bool operator!= (const vect4 &a, const vect4 &b);

			friend std::ostream& operator<< (std::ostream& stream, vect4& v);
		};

	}
}