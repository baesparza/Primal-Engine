#include "vect4.h"

namespace primal
{
	namespace maths
	{

		vect4::vect4() : x(0), y(0), z(0), w(0)
		{ }

		vect4::vect4(const float & ax, const float & ay, const float & az, const float & aw) : 
			x(ax), y(ay), z(az), w(aw)
		{ }

		vect4::vect4(vect4 & v) : x(v.x), y(v.y), z(v.z), w(v.w)
		{ }

		vect4 & vect4::add(const vect4 & other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return (*this);
		}

		vect4 & vect4::substract(const vect4 & other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return (*this);
		}

		vect4 & vect4::multiply(const vect4 & other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return (*this);
		}

		vect4 & vect4::divide(const vect4 & other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return (*this);
		}

		vect4 operator+(vect4 a, const vect4 & b)
		{
			return a.add(b);
		}

		vect4 operator-(vect4 a, const vect4 & b)
		{
			return a.substract(b);
		}

		vect4 operator*(vect4 a, const vect4 & b)
		{
			return a.multiply(b);
		}

		vect4 operator/(vect4 a, const vect4 & b)
		{
			return a.divide(b);
		}

		void operator+=(vect4 &a, const vect4 & b)
		{
			a.add(b);
		}

		void operator-=(vect4 & a, const vect4 & b)
		{
			a.substract(b);
		}

		void operator*=(vect4 & a, const vect4 & b)
		{
			a.multiply(b);
		}

		void operator/=(vect4 & a, const vect4 & b)
		{
			a.divide(b);
		}

		bool operator==(const vect4 & a, const vect4 & b)
		{
			if ((a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w))
				return false;
			return true;
		}

		bool operator!=(const vect4 & a, const vect4 & b)
		{
			return !(a == b);
		}

		std::ostream & operator<<(std::ostream & stream, vect4 & v)
		{
			stream << "vect4: (" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
			return stream;
		}

	}
}