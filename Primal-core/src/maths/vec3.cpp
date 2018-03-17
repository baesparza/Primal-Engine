#include "vec3.h"

namespace primal
{
	namespace maths
	{

		vec3::vec3(const float & ax, const float & ay, const float & az) : x(ax), y(ay), z(az)
		{ }

		vec3 & vec3::add(const vec3 & other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return (*this);
		}

		vec3 & vec3::substract(const vec3 & other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return (*this);
		}

		vec3 & vec3::multiply(const vec3 & other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return (*this);
		}

		vec3 & vec3::divide(const vec3 & other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return (*this);
		}

		vec3 operator+(vec3 a, const vec3 & b)
		{
			return a.add(b);
		}

		vec3 operator-(vec3 a, const vec3 & b)
		{
			return a.substract(b);
		}

		vec3 operator*(vec3 a, const vec3 & b)
		{
			return a.multiply(b);
		}

		vec3 operator/(vec3 a, const vec3 & b)
		{
			return a.divide(b);
		}

		void operator+=(vec3 &a, const vec3 & b)
		{
			a.add(b);
		}

		void operator-=(vec3 & a, const vec3 & b)
		{
			a.substract(b);
		}

		void operator*=(vec3 & a, const vec3 & b)
		{
			a.multiply(b);
		}

		void operator/=(vec3 & a, const vec3 & b)
		{
			a.divide(b);
		}

		bool operator==(const vec3 & a, const vec3 & b)
		{
			if ((a.x != b.x) || (a.y != b.y) || (a.z != b.z))
				return false;
			return true;
		}

		bool operator!=(const vec3 & a, const vec3 & b)
		{
			return !(a == b);
		}

		std::ostream & operator<<(std::ostream & stream, vec3 & v)
		{
			stream << "vec3: (" << v.x << ", " << v.y << ", " << v.z << ")";
			return stream;
		}

	}
}