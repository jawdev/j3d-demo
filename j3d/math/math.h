/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/math/math.h
*******************************************************************************/
#ifndef __J3D_MATH_MATH_H__
#define __J3D_MATH_MATH_H__
namespace j3d {

/*******************************************************************************
* MATH
*******************************************************************************/

struct math {

	static float min(float a, float b)
	{
		return (a < b ? a : b);
	}

	static float max(float a, float b)
	{
		return (a > b ? a : b);
	}

};

}
#endif
