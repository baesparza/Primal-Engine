#include "vec2.h"

namespace primal
{
	namespace maths
	{

		vec2::vec2(const float & ax, const float & ay) : x(ax), y(ay)
		{ }

		vec2 & vec2::add(const vec2 & other)
		{
			x += other.x;
			y += other.y;
			return (*this);
		}

		vec2 & vec2::substract(const vec2 & other)
		{
			x -= other.x;
			y -= other.y;
			return (*this);
		}

		vec2 & vec2::multiply(const vec2 & other)
		{
			x *= other.x;
			y *= other.y;
			return (*this);
		}

		vec2 & vec2::divide(const vec2 & other)
		{
			x /= other.x;
			y /= other.y;
			return (*this);
		}

		vec2 operator+(vec2 a, const vec2 & b)
		{
			return a.add(b);
		}

		vec2 operator-(vec2 a, const vec2 & b)
		{
			return a.substract(b);
		}

		vec2 operator*(vec2 a, const vec2 & b)
		{
			return a.multiply(b);
		}

		vec2 operator/(vec2 a, const vec2 & b)
		{
			return a.divide(b);
		}

		void operator+=(vec2 &a, const vec2 & b)
		{
			a.add(b);
		}

		void operator-=(vec2 & a, const vec2 & b)
		{
			a.substract(b);
		}

		void operator*=(vec2 & a, const vec2 & b)
		{
			a.multiply(b);
		}

		void operator/=(vec2 & a, const vec2 & b)
		{
			a.divide(b);
		}

		bool operator==(const vec2 & a, const vec2 & b)
		{
			if ((a.x != b.x) || (a.y != b.y))
				return false;
			return true;
		}

		bool operator!=(const vec2 & a, const vec2 & b)
		{
			return !(a == b);
		}

		std::ostream & operator<<(std::ostream & stream, vec2 & v)
		{
			stream << "Vect2: (" << v.x << ", " << v.y << ")";
			return stream;
		}

	}
}