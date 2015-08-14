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

/*
	static void translation(mat4 *m, const vec4 &v)
	{
		translation(m, vec3(v.x(), v.y(), v.z()));
	}
*/

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

	static mat4 invert(mat4 m)
	{
		mat4 inv, invOut;
		int i;
	float det;

    inv[0] = m[5]  * m[10] * m[15] - 
             m[5]  * m[11] * m[14] - 
             m[9]  * m[6]  * m[15] + 
             m[9]  * m[7]  * m[14] +
             m[13] * m[6]  * m[11] - 
             m[13] * m[7]  * m[10];

    inv[4] = -m[4]  * m[10] * m[15] + 
              m[4]  * m[11] * m[14] + 
              m[8]  * m[6]  * m[15] - 
              m[8]  * m[7]  * m[14] - 
              m[12] * m[6]  * m[11] + 
              m[12] * m[7]  * m[10];

    inv[8] = m[4]  * m[9] * m[15] - 
             m[4]  * m[11] * m[13] - 
             m[8]  * m[5] * m[15] + 
             m[8]  * m[7] * m[13] + 
             m[12] * m[5] * m[11] - 
             m[12] * m[7] * m[9];

    inv[12] = -m[4]  * m[9] * m[14] + 
               m[4]  * m[10] * m[13] +
               m[8]  * m[5] * m[14] - 
               m[8]  * m[6] * m[13] - 
               m[12] * m[5] * m[10] + 
               m[12] * m[6] * m[9];

    inv[1] = -m[1]  * m[10] * m[15] + 
              m[1]  * m[11] * m[14] + 
              m[9]  * m[2] * m[15] - 
              m[9]  * m[3] * m[14] - 
              m[13] * m[2] * m[11] + 
              m[13] * m[3] * m[10];

    inv[5] = m[0]  * m[10] * m[15] - 
             m[0]  * m[11] * m[14] - 
             m[8]  * m[2] * m[15] + 
             m[8]  * m[3] * m[14] + 
             m[12] * m[2] * m[11] - 
             m[12] * m[3] * m[10];

    inv[9] = -m[0]  * m[9] * m[15] + 
              m[0]  * m[11] * m[13] + 
              m[8]  * m[1] * m[15] - 
              m[8]  * m[3] * m[13] - 
              m[12] * m[1] * m[11] + 
              m[12] * m[3] * m[9];

    inv[13] = m[0]  * m[9] * m[14] - 
              m[0]  * m[10] * m[13] - 
              m[8]  * m[1] * m[14] + 
              m[8]  * m[2] * m[13] + 
              m[12] * m[1] * m[10] - 
              m[12] * m[2] * m[9];

    inv[2] = m[1]  * m[6] * m[15] - 
             m[1]  * m[7] * m[14] - 
             m[5]  * m[2] * m[15] + 
             m[5]  * m[3] * m[14] + 
             m[13] * m[2] * m[7] - 
             m[13] * m[3] * m[6];

    inv[6] = -m[0]  * m[6] * m[15] + 
              m[0]  * m[7] * m[14] + 
              m[4]  * m[2] * m[15] - 
              m[4]  * m[3] * m[14] - 
              m[12] * m[2] * m[7] + 
              m[12] * m[3] * m[6];

    inv[10] = m[0]  * m[5] * m[15] - 
              m[0]  * m[7] * m[13] - 
              m[4]  * m[1] * m[15] + 
              m[4]  * m[3] * m[13] + 
              m[12] * m[1] * m[7] - 
              m[12] * m[3] * m[5];

    inv[14] = -m[0]  * m[5] * m[14] + 
               m[0]  * m[6] * m[13] + 
               m[4]  * m[1] * m[14] - 
               m[4]  * m[2] * m[13] - 
               m[12] * m[1] * m[6] + 
               m[12] * m[2] * m[5];

    inv[3] = -m[1] * m[6] * m[11] + 
              m[1] * m[7] * m[10] + 
              m[5] * m[2] * m[11] - 
              m[5] * m[3] * m[10] - 
              m[9] * m[2] * m[7] + 
              m[9] * m[3] * m[6];

    inv[7] = m[0] * m[6] * m[11] - 
             m[0] * m[7] * m[10] - 
             m[4] * m[2] * m[11] + 
             m[4] * m[3] * m[10] + 
             m[8] * m[2] * m[7] - 
             m[8] * m[3] * m[6];

    inv[11] = -m[0] * m[5] * m[11] + 
               m[0] * m[7] * m[9] + 
               m[4] * m[1] * m[11] - 
               m[4] * m[3] * m[9] - 
               m[8] * m[1] * m[7] + 
               m[8] * m[3] * m[5];

    inv[15] = m[0] * m[5] * m[10] - 
              m[0] * m[6] * m[9] - 
              m[4] * m[1] * m[10] + 
              m[4] * m[2] * m[9] + 
              m[8] * m[1] * m[6] - 
              m[8] * m[2] * m[5];

 det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
		if (det == 0) {
			J3D_DEBUG_FATAL("determinant = 0");
			return mat4();
		}
	det = 1.0 / det;
	for (i = 0; i < 16; i++)
        invOut[i] = inv[i] * det;
		
		return invOut;
	}

};

}
#endif
