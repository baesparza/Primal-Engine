#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include "vect2.h"
#include "vect3.h"
#include "vect4.h"
#include "mat4.h"


namespace primal
{
	namespace maths
	{
		inline float toRadians(float degree)
		{
			return float (degree * (M_PI / 180.f));
		}
	}
}