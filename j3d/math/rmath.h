/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/math/rmath.h
*******************************************************************************/
#ifndef __J3D_MATH_RMATH_H__
#define __J3D_MATH_RMATH_H__
namespace j3d {

/*******************************************************************************
* RMATH
*******************************************************************************/

struct rmath {
public:

	static void screen_ray(ray3 *, float win_x, float win_y);

	static bool intersection(ray3, vec3 min, vec3 max);

};

/*
 * SCREEN RAYS
	mp_cam->transform();
	cout << mp_cam->pos() << endl;
	vec4 v(1, 1, -1, 1);
	cout << v << endl;
	vec4 v2 = v * vmath::invert(mp_cam->transform());
	cout << v2 << endl;
	cout << vmath::norm(v2 - mp_cam->pos()) << endl;
*/


}
#endif
