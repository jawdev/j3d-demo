/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/math/vmath.h
*******************************************************************************/
#ifndef __J3D_MATH_VMATH_H__
#define __J3D_MATH_VMATH_H__
namespace j3d {

/*******************************************************************************
* VMATH
*******************************************************************************/

struct vmath {
public:
	
	static void translation(mat4 *m, const vec<3, float> &v);

	static void rotation_x(mat4 *m, const float &f);
	static void rotation_y(mat4 *m, const float &f);
	static void rotation_z(mat4 *m, const float &f);
	static void rotation(mat4 *m, const vec<3, float> &v);

	static void perspective(mat4 *m, float l, float r, float b, float t,
			float n, float f);

};

}
#endif
