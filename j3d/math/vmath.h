/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/math/vmath.h
*******************************************************************************/
#ifndef __J3D_MATH_VMATH_H__
#define __J3D_MATH_VMATH_H__

struct vec2;
struct vec3;
struct vec4;
struct mat4;

/*******************************************************************************
* VEC2
*******************************************************************************/

struct vec2 {
	float x, y;

	vec2(float _x = 0, float _y = 0)
	{
		x = _x;
		y = _y;
	}

	vec2 &operator=(const vec2& v)
	{
		if (this != &v) {
			x = v.x;
			y = v.y;
		}
		return *this;
	}

	vec2 operator-() const { return vec2(-x, -y); }

	vec2 operator+(const vec2 &v) const { return vec2(x + v.x, y + v.y); }
	vec2 operator-(const vec2 &v) const { return vec2(x - v.x, y - v.y); }
	vec2 operator*(const float &f) const { return vec2(x * f, y * f); }
	vec2 operator/(const float &f) const { return vec2(x / f, y / f); }
	
	vec2 &operator+=(const vec2 &v) { x += v.x; y += v.y; return *this; }
	vec2 &operator-=(const vec2 &v) { x -= v.x; y -= v.y; return *this; }
	vec2 &operator*=(const float &f) { x *= f; y *= f; return *this; }
	vec2 &operator/=(const float &f) { x /= f; y /= f; return *this; }

	GLfloat *glFloat() { return (GLfloat *)this; }
	friend ostream &operator<<(ostream &, const vec2 &);
};

inline ostream &operator<<(ostream &os, const vec2 &v)
{
	os << "<" << v.x << ", " << v.y << ">";
	return os;
}

/*******************************************************************************
* VEC3
*******************************************************************************/

struct vec3 {
	float x, y, z;

	vec3(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f)
	{
		x = _x;
		y = _y;
		z = _z;
	}
	
	vec3 &operator=(const vec3 &v)
	{
		if (this != &v) {
			x = v.x;
			y = v.y;
			z = v.z;
		}
		return *this;
	}

	vec3 operator-() const { return vec3(-x, -y, -z); }

	vec3 operator+(const vec3 &v) const { return vec3(x + v.x, y + v.y,
			z + v.z); }
	vec3 operator-(const vec3 &v) const { return vec3(x - v.x, y - v.y,
			z - v.z); }
	vec3 operator*(const float &f) const { return vec3(x * f, y * f, z * f); }
	vec3 operator/(const float &f) const { return vec3(x / f, y / f, z / f); }

	vec3 &operator+=(const vec3 &v) { x += v.x; y += v.y; z += v.z;
			return *this; }
	vec3 &operator-=(const vec3 &v) { x -= v.x; y -= v.y; z -= v.z;
			return *this; }
	vec3 &operator*=(const float &f) { x *= f; y *= f; z *= f; return *this; }
	vec3 &operator/=(const float &f) { x /= f; y /= f; z /= f; return *this; }

	GLfloat *glFloat() { return (GLfloat *)this; }
	friend ostream &operator<<(ostream &, const vec3 &);
};

inline ostream &operator<<(ostream &os, const vec3 &v)
{
	os << "<" << v.x << ", " << v.y << ", " << v.z << ">";
	return os;
}

/*******************************************************************************
* VEC4
*******************************************************************************/

struct vec4 {
	float x, y, z, w;
	bool lock_w;

	vec4(float _x = 0, float _y = 0, float _z = 0, float _w = 1,
			bool _lock_w = true)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
		lock_w = _lock_w;
	}

	vec4(const vec2 &v)
	{
		x = v.x;
		y = v.y;
		z = 0;
		w = 1;
		lock_w = true;
	}

	vec4(const vec3 &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = 1;
		lock_w = true;
	}
	
	vec4 &operator=(const vec4 &v)
	{
		if (this != &v) {
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
			lock_w = v.lock_w;
		}
		return *this;
	}

	vec4 operator-() const { return vec4(-x, -y, -z, (lock_w ? w : -w)); }

	vec4 operator+(const vec4 &v) const { return vec4(x + v.x, y + v.y,
			z + v.z, (lock_w ? w : w + v.w)); }
	vec4 operator-(const vec4 &v) const { return vec4(x - v.x, y - v.y,
			z - v.z, (lock_w ? w : w - v.w)); }
	vec4 operator*(const float &f) const { return vec4(x * f, y * f, z * f,
			(lock_w ? w : w * f)); }
	vec4 operator/(const float &f) const { return vec4(x / f, y / f, z / f,
			(lock_w ? w : w / f)); }

	vec4 &operator+=(const vec4 &v) { x += v.x; y += v.y; z += v.z;
			if (!lock_w) w += v.w; return *this; }
	vec4 &operator-=(const vec4 &v) { x -= v.x; y -= v.y; z -= v.z;
			if (!lock_w) w -= v.w; return *this; }
	vec4 &operator*=(const float &f) { x *= f; y *= f; z *= f;
			if (!lock_w) w *= f; return *this; }
	vec4 &operator/=(const float &f) { x /= f; y /= f; z /= f;
			if (!lock_w) w /= f; return *this; }

	vec4 operator*(const mat4 &) const;

	GLfloat *glFloat() { return (GLfloat *)this; }
	friend ostream &operator<<(ostream &, const vec4 &);
};

inline ostream &operator<<(ostream &os, const vec4 &v)
{
	os << "<" << v.x << ", " << v.y << ", ";
	os << v.z << ", " << v.w << ">";
	return os;
}

/*******************************************************************************
* MAT4
*******************************************************************************/

struct mat4 {
	float data[4][4];
	//         c  r

	mat4() { iden(); }

/*
	float *row(const int &r)
	{
		float *row_data = new float[4];
		for (c = 0; c < 4; ++c)
			row_data[c] = data[c][r];
		return row_data;
	}

	float *col(const int &c)
	{
		float *col_data = new float[4];
		for (r = 0; r < 4; ++r)
			col_data[r] = data[c][r];
		return col_data;
	}
*/

	float get(const int &r, const int &c) { return data[c][r]; }
	void set(const int &r, const int &c, const float &val) { data[c][r] = val; }

	void zero()
	{
		int c, r;
		for (c = 0; c < 4; ++c)
			for (r = 0; r < 4; ++r)
				data[c][r] = 0;
	}

	void iden()
	{
		int c, r;
		for (c = 0; c < 4; ++c)
			for (r = 0; r < 4; ++r)
				data[c][r] = (c == r ? 1 : 0);
	}

	mat4 &operator=(const mat4 &m)
	{
		int c, r;
		for (c = 0; c < 4; ++c)
			for (r = 0; r < 4; ++r)
				data[c][r] = m.data[c][r];
		return *this;
	}

	mat4 &operator*=(const mat4 &m)
	{
		int c, r;
		mat4 cp = *this;
		for (c = 0; c < 4; ++c)
			for (r = 0; r < 4; ++r)
				data[c][r] =
					m.data[c][0] * cp.data[0][r] +
					m.data[c][1] * cp.data[1][r] +
					m.data[c][2] * cp.data[2][r] +
					m.data[c][3] * cp.data[3][r];
		return *this;
	}

	float &operator[](const int &i)
	{
		return data[i % 4][i / 4];
	}

	mat4 operator*(const mat4 m)
	{
		mat4 result = *this;
		result *= m;
		return result;
	}

	GLfloat *glFloat() { return (GLfloat *)this; }
	friend ostream &operator<<(ostream &, const mat4 &);
};

inline ostream &operator<<(ostream &os, const mat4 &m)
{
	os << "========================================";
	os << "========================================\n";
	int i, j;
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			os << setw(20);
			os << m.data[j][i];
		}
		os << "\n";
	}
	os << "========================================";
	os << "========================================";
	return os;
}

/*******************************************************************************
* MAT4 VEC4
*******************************************************************************/

inline vec4 vec4::operator*(const mat4 &m) const
{
	vec4 v;
	v.x =	m.data[0][0] * x +
			m.data[1][0] * y +
			m.data[2][0] * z +
			m.data[3][0] * w;
	v.y =	m.data[0][1] * x +
			m.data[1][1] * y +
			m.data[2][1] * z +
			m.data[3][1] * w;
	v.z =	m.data[0][2] * x +
			m.data[1][2] * y +
			m.data[2][2] * z +
			m.data[3][2] * w;
	v.w =	m.data[0][3] * x +
			m.data[1][3] * y +
			m.data[2][3] * z +
			m.data[3][3] * w;
	return v;
}

/*******************************************************************************
* VMATH
*******************************************************************************/

struct vmath {
public:

	static vec2 norm(const vec2 &v)
	{
		float mag = sqrt(v.x * v.x + v.y * v.y);
		return (mag == 0 ? vec2() : vec2(v.x / mag, v.y / mag));
	}

	static vec3 norm(const vec3 &v)
	{
		float mag = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		return (mag == 0 ? vec3() : vec3(v.x / mag, v.y / mag, v.z / mag));
	}

	static vec4 norm(const vec4 &v)
	{
		float mag = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		if (mag == 0)
			return vec4();
		return vec4(v.x / mag, v.y / mag, v.z / mag, 1);
	}

	static vec3 cross(const vec3 &a, const vec3 &b)
	{
		return vec3(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x);
	}

	static vec4 cross(vec4 a, vec4 b)
	{
		if (a.w != 1)
			a = norm(a);
		if (b.w != 1)
			b = norm(b);
		return vec4(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x,
			1);
	}
	
	static void translation(mat4 *m, const vec3 &v)
	{
		m->iden();
		m->set(0, 3, v.x);
		m->set(1, 3, v.y);
		m->set(2, 3, v.z);
	}

	static void translation(mat4 *m, const vec4 &v)
	{
		translation(m, vec3(v.x, v.y, v.z));
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

	static void rotation(mat4 *m, const vec3 &v)
	{
		mat4 mx, my, mz;
		rotationX(&mx, v.x);
		rotationY(&my, v.y);
		rotationZ(&mz, v.z);
		*m = mz * mx * my;
	}

	static void rotation(mat4 *m, const vec4 &v)
	{
		rotation(m, vec3(v.x, v.y, v.z));
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
#endif
