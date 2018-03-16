#pragma once

#include "maths.h"

namespace primal
{
	namespace maths
	{

		struct mat4
		{
			float elements[4 * 4];

			mat4();
			mat4(float diagonal);
			// TODO: copy constructor

			static mat4 identity();

			mat4& multiply(const mat4& other);

			mat4& operator*= (const mat4 &other);
			friend mat4 operator* (mat4 a, const mat4 &b);

			static mat4 ortographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fov, float aspectRatio, float near, float far);
			
			static mat4 translation(const vect3& translation);
			static mat4 rotation(float angle, const vect3& axis);
			static mat4 scale(const vect3& scale);
		};

	}
}
