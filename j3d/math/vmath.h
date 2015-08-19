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
	
	static void translation(mat4 *m, const vec<3, float> &v)
	{
		m->iden();
		m->set(0, 3, v.data[0]);
		m->set(1, 3, v.data[1]);
		m->set(2, 3, v.data[2]);
	}

	static void rotationX(mat4 *m, const float &f)
	{
		float c = cos(f);
		float s = sin(f);
		m->set(1, 1, c);
		m->set(1, 2, -s);
		m->set(2, 1, s);
		m->set(2, 2, c);
	}

	static void rotationY(mat4 *m, const float &f)
	{
		float c = cos(f);
		float s = sin(f);
		m->set(0, 0, s);
		m->set(0, 2, -c);
		m->set(2, 0, c);
		m->set(2, 2, s);
	}

	static void rotationZ(mat4 *m, const float &f)
	{
		float c = cos(f);
		float s = sin(f);
		m->set(0, 0, c);
		m->set(0, 1, -s);
		m->set(1, 0, s);
		m->set(1, 1, c);
	}

	static void rotation(mat4 *m, const vec<3, float> &v)
	{
		mat4 mx, my, mz;
		rotationX(&mx, v.data[0]);
		rotationY(&my, v.data[1]);
		rotationZ(&mz, v.data[2]);
		*m = mz * mx * my;
	}

	static void perspective(mat4 *m, float l, float r, float b, float t,
			float n, float f)
	{
		m->iden();
		if (r == l || t == b || n == f || n < 0 || f < 0) {
			J3D_DEBUG_FATAL("invalid perspective args: {l = " << l <<
					", r = " << r << ", b = " << b << ", t = " << t <<
					", n = " << n << ", f = " << f << "}");
			return;
		}
		float nt2 = n * 2.0f;
		float rml = r - l;
		float tmb = t - b;
		float fmn = f - n;
		m->set(0, 0, nt2 / rml);
		m->set(0, 2, (r + l) / rml);
		m->set(1, 1, nt2 / tmb);
		m->set(1, 2, (t + b) / tmb);
		m->set(2, 2, -(f + n) / fmn);
		m->set(2, 3, -(f * nt2) / fmn);
		m->set(3, 2, -1);
		m->set(3, 3, 0);
	}

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
