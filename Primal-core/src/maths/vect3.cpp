#include "vect3.h"

namespace primal
{
	namespace maths
	{

		vect3::vect3() : x(0), y(0), z(0)
		{ }

		vect3::vect3(const float & ax, const float & ay, const float & az) : x(ax), y(ay), z(az)
		{ }

		vect3::vect3(vect3 & v) : x(v.x), y(v.y), z(v.z)
		{ }

		vect3 & vect3::add(const vect3 & other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return (*this);
		}

		vect3 & vect3::substract(const vect3 & other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return (*this);
		}

		vect3 & vect3::multiply(const vect3 & other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return (*this);
		}

		vect3 & vect3::divide(const vect3 & other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return (*this);
		}

		vect3 operator+(vect3 a, const vect3 & b)
		{
			return a.add(b);
		}

		vect3 operator-(vect3 a, const vect3 & b)
		{
			return a.substract(b);
		}

		vect3 operator*(vect3 a, const vect3 & b)
		{
			return a.multiply(b);
		}

		vect3 operator/(vect3 a, const vect3 & b)
		{
			return a.divide(b);
		}

		void operator+=(vect3 &a, const vect3 & b)
		{
			a.add(b);
		}

		void operator-=(vect3 & a, const vect3 & b)
		{
			a.substract(b);
		}

		void operator*=(vect3 & a, const vect3 & b)
		{
			a.multiply(b);
		}

		void operator/=(vect3 & a, const vect3 & b)
		{
			a.divide(b);
		}

		bool operator==(const vect3 & a, const vect3 & b)
		{
			if ((a.x != b.x) || (a.y != b.y) || (a.z != b.z))
				return false;
			return true;
		}

		bool operator!=(const vect3 & a, const vect3 & b)
		{
			return !(a == b);
		}

		std::ostream & operator<<(std::ostream & stream, vect3 & v)
		{
			stream << "vect3: (" << v.x << ", " << v.y << ", " << v.z << ")";
			return stream;
		}

	}
}