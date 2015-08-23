/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/math/vmath.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d {

/*******************************************************************************
* VMATH
*******************************************************************************/

void vmath::translation(mat4 *m, const vec<3, float> &v)
{
	m->iden();
	m->set(0, 3, v.data[0]);
	m->set(1, 3, v.data[1]);
	m->set(2, 3, v.data[2]);
}

void vmath::rotation_x(mat4 *m, const float &f)
{
	float c = cos(f);
	float s = sin(f);
	m->set(1, 1, c);
	m->set(1, 2, s);
	m->set(2, 1, s);
	m->set(2, 2, -c);
}

void vmath::rotation_y(mat4 *m, const float &f)
{
/*
	float c = cos(f);
	float s = sin(f);
	m->set(0, 0, s);
	m->set(0, 2, -c);
	m->set(2, 0, c);
	m->set(2, 2, s);
*/
	float c = cos(f);
	float s = sin(f);
	m->set(0, 0, -s);
	m->set(0, 2, c);
	m->set(2, 0, c);
	m->set(2, 2, s);
}

void vmath::rotation_z(mat4 *m, const float &f)
{
	float c = cos(f);
	float s = sin(f);
	m->set(0, 0, c);
	m->set(0, 1, -s);
	m->set(1, 0, s);
	m->set(1, 1, c);
}

void vmath::rotation(mat4 *m, const vec<3, float> &v)
{
	mat4 mx, my, mz;
	rotation_x(&mx, v.data[0]);
	rotation_y(&my, v.data[1]);
	rotation_z(&mz, v.data[2]);
	*m = mz * mx * my;
}

void vmath::perspective(mat4 *m, float l, float r, float b, float t,
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


}
