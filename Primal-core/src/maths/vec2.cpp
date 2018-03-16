#include "vec2.h"

namespace primal
{
	namespace maths
	{

		vect2::vect2() : x(0), y(0)
		{ }

		vect2::vect2(const float & ax, const float & ay) : x(ax), y(ay)
		{ }

		vect2::vect2(vect2 & v) : x(v.x), y(v.y)
		{ 
			//	std::cout << "Copy" << '\n';
		}

		vect2 & vect2::add(const vect2 & other)
		{
			x += other.x;
			y += other.y;
			return (*this);
		}

		vect2 & vect2::substract(const vect2 & other)
		{
			x -= other.x;
			y -= other.y;
			return (*this);
		}

		vect2 & vect2::multiply(const vect2 & other)
		{
			x *= other.x;
			y *= other.y;
			return (*this);
		}

		vect2 & vect2::divide(const vect2 & other)
		{
			x /= other.x;
			y /= other.y;
			return (*this);
		}

		vect2 & operator+(vect2 & a, const vect2 & b)
		{
			return a.add(b);
		}

		vect2 & operator-(vect2 & a, const vect2 & b)
		{
			return a.substract(b);
		}

		vect2 & operator*(vect2 & a, const vect2 & b)
		{
			return a.multiply(b);
		}

		vect2 & operator/(vect2 & a, const vect2 & b)
		{
			return a.divide(b);
		}

		void operator+=(vect2 &a, const vect2 & b)
		{
			a.add(b);
		}

		void operator-=(vect2 & a, const vect2 & b)
		{
			a.substract(b);
		}

		void operator*=(vect2 & a, const vect2 & b)
		{
			a.multiply(b);
		}

		void operator/=(vect2 & a, const vect2 & b)
		{
			a.divide(b);
		}

		bool operator==(const vect2 & a, const vect2 & b)
		{
			if ((a.x != b.x) || (a.y != b.y))
				return false;
			return true;
		}

		bool operator!=(const vect2 & a, const vect2 & b)
		{
			return !(a == b);
		}

		std::ostream & operator<<(std::ostream & stream, vect2 & v)
		{
			stream << "Vect2: (" << v.x << ", " << v.y << ")";
			return stream;
		}

	}
}