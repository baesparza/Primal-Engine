#include "vec4.h"

namespace primal
{
	namespace maths
	{

		vec4::vec4(const float & ax, const float & ay, const float & az, const float & aw) : 
			x(ax), y(ay), z(az), w(aw)
		{ }

		vec4 & vec4::add(const vec4 & other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return (*this);
		}

		vec4 & vec4::substract(const vec4 & other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return (*this);
		}

		vec4 & vec4::multiply(const vec4 & other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return (*this);
		}

		vec4 & vec4::divide(const vec4 & other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return (*this);
		}

		vec4 operator+(vec4 a, const vec4 & b)
		{
			return a.add(b);
		}

		vec4 operator-(vec4 a, const vec4 & b)
		{
			return a.substract(b);
		}

		vec4 operator*(vec4 a, const vec4 & b)
		{
			return a.multiply(b);
		}

		vec4 operator/(vec4 a, const vec4 & b)
		{
			return a.divide(b);
		}

		void operator+=(vec4 &a, const vec4 & b)
		{
			a.add(b);
		}

		void operator-=(vec4 & a, const vec4 & b)
		{
			a.substract(b);
		}

		void operator*=(vec4 & a, const vec4 & b)
		{
			a.multiply(b);
		}

		void operator/=(vec4 & a, const vec4 & b)
		{
			a.divide(b);
		}

		bool operator==(const vec4 & a, const vec4 & b)
		{
			if ((a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w))
				return false;
			return true;
		}

		bool operator!=(const vec4 & a, const vec4 & b)
		{
			return !(a == b);
		}

		std::ostream & operator<<(std::ostream & stream, vec4 & v)
		{
			stream << "vec4: (" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
			return stream;
		}

	}
}