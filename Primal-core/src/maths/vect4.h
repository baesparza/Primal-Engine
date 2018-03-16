#pragma once

#include <iostream>

namespace primal
{
	namespace maths
	{

		struct vect4
		{
			float x, y, z, w;

			vect4();
			vect4(const float& ax, const float& ay, const float& az, const float& aw);
			vect4(vect4& v);

			vect4& add(const vect4& other);
			vect4& substract(const vect4& other);
			vect4& multiply(const vect4& other);
			vect4& divide(const vect4& other);

			// if (&a) cause problems when affecting a, remove (&a) reference
			// or mark (&a) as a const
			friend vect4& operator+ (vect4 &a, const vect4 &b);
			friend vect4& operator- (vect4 &a, const vect4 &b);
			friend vect4& operator* (vect4 &a, const vect4 &b);
			friend vect4& operator/ (vect4 &a, const vect4 &b);

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