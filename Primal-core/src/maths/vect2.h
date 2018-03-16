#pragma once

#include <iostream>

namespace primal
{
	namespace maths
	{

		struct vect2
		{
			float x, y;

			vect2();
			vect2(const float& ax, const float& ay);
			vect2(vect2& v);

			vect2& add(const vect2& other);
			vect2& substract(const vect2& other);
			vect2& multiply(const vect2& other);
			vect2& divide(const vect2& other);

			// if (&a) cause problems when affecting a, remove (&a) reference
			// or mark (&a) as a const
			friend vect2& operator+ (vect2 &a, const vect2 &b);
			friend vect2& operator- (vect2 &a, const vect2 &b);
			friend vect2& operator* (vect2 &a, const vect2 &b);
			friend vect2& operator/ (vect2 &a, const vect2 &b);

			friend void operator+= (vect2 &a, const vect2 &b);
			friend void operator-= (vect2 &a, const vect2 &b);
			friend void operator*= (vect2 &a, const vect2 &b);
			friend void operator/= (vect2 &a, const vect2 &b);

			friend bool operator== (const vect2 &a, const vect2 &b);
			friend bool operator!= (const vect2 &a, const vect2 &b);

			friend std::ostream& operator<< (std::ostream& stream, vect2& v);
		};

	}
}