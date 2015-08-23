/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/math/vector.h
*******************************************************************************/
namespace j3d {

typedef float vectype;

/*******************************************************************************
* VEC
*******************************************************************************/

template<const int N, class T>
struct vec {

	T data[N];
	
	vec() { data[N] = {0}; }
	vec(const T* _data) { assign(_data); }
	vec(const vec<N, T> &v) { assign(v); }
	vec(initializer_list<T> ts) { assign(ts); }
	vec &operator=(const vec &v) { return assign(v); }

	//////////////////////////////////////////////
	// MATH

	vec &normalize()
	{
		float mag = 0;
		int i;
		for (i = 0; i < N; ++i)
			mag += data[i] * data[i];
		mag = sqrt(mag);
		if (mag == 0)
			return *this;
		for (i = 0; i < N; ++i)
			data[i] = data[i] / mag;
		return *this;
	}

	vec normal() const
	{
		vec<N, T> v(this.data);
		return v.normalize();
	}

	vec &invert()
	{
		for (int i = 0; i < N; ++i)
			data[i] = 1.0 / data[i];
		return *this;
	}

	vec inverse() const
	{
		vec<N, T> v(this.data);
		return v.invert();
	}

	//////////////////////////////////////////////
	// OPERATORS

	vec operator-() const
	{
		vec<N, T> vout;
		for (int i = 0; i < N; ++i)
			vout.data[i] = -data[i];
		return vout;
	}

	vec operator+(const vec<N, T> &v) const
	{
		vec<N, T> vout;
		for (int i = 0; i < N; ++i)
			vout.data[i] = data[i] + v.data[i];
		return vout;
	}

	vec operator-(const vec<N, T> &v) const
	{
		vec<N, T> vout;
		for (int i = 0; i < N; ++i)
			vout.data[i] = data[i] - v.data[i];
		return vout;
	}

	vec operator*(const float &f) const
	{
		vec<N, T> vout;
		for (int i = 0; i < N; ++i)
			vout.data[i] = data[i] * f;
		return vout;
	}

	vec operator/(const float &f) const
	{
		vec<N, T> vout;
		for (int i = 0; i < N; ++i)
			vout.data[i] = data[i] / f;
		return vout;
	}

	vec &operator+=(const vec<N, T> &v)
	{
		for (int i = 0; i < N; ++i)
			data[i] += v.data[i];
		return *this;
	}

	vec &operator-=(const vec &v)
	{
		for (int i = 0; i < N; ++i)
			data[i] -= v.data[i];
		return *this;
	}

	vec &operator*=(const float &f)
	{
		for (int i = 0; i < N; ++i)
			data[i] *= f;
		return *this;
	}

	vec &operator/=(const float &f)
	{
		for (int i = 0; i < N; ++i)
			data[i] /= f;
		return *this;
	}

	T &operator[](const int &i)
	{
		return data[i];
	}

	//////////////////////////////////////////////
	// CAST OPERATORS

	operator int *() { return static_cast<int *>(&data[0]); }
	operator float *() { return static_cast<float *>(&data[0]); }
	//operator GLfloat *() { return static_cast<GLfloat *>(&data[0]); }

	//////////////////////////////////////////////
	// ASSIGN

	vec &assign(const T* _data)
	{
		for (int i = 0; i < N; ++i)
			data[i] = _data[i];
		return *this;
	}

	vec &assign(const vec &v)
	{
		if (this != &v)
			assign(v.data);
		return *this;
	}

	vec &assign(initializer_list<T> ts)
	{
		int i = 0;
		for (T t : ts) {
			data[i++] = t;
			if (i >= N)
				break;
		}
		return *this;
	}

	void info()
	{
		cout << "data = " << &data << ", data[0] " << &data[0] << endl;
		cout << ", data[0] = " << data[0] << endl;
		data[0] = 0;
		cout << "data = " << &data << ", data[0] " << &data[0] << endl;
		cout << ", data[0] = " << data[0] << endl;
	}

	//////////////////////////////////////////////
	// EXTRAS
	
	template<const int, class>
	friend ostream &operator<<(ostream &, const vec<N, T> &);

};

template<int N, class T>
ostream &operator<<(ostream &os, const vec<N, T> &v)
{
	os << "<";
	for (int i = 0; i < N; ++i) {
		if (i > 0)
			os << ", ";
		os << v.data[i];
	}
	os << ">";
	return os;
}

/*******************************************************************************
* VEC2
*******************************************************************************/

struct vec2 : public vec<2, vectype> {

	vec2(vectype x = 0, vectype y = 0) :
			vec<2, vectype>({x, y}) {}

	vec2 &x(const float &f) { data[0] = f; return *this; }
	vec2 &y(const float &f) { data[1] = f; return *this; }

	const vectype &x() const { return data[0]; }
	const vectype &y() const { return data[1]; }

	///////////////////////////////////////
	// OPERATORS

	operator vec3();
	operator vec4();

};

/*******************************************************************************
* VEC3
*******************************************************************************/

struct vec3 : public vec<3, vectype> {

	vec3(vectype x = 0, vectype y = 0, vectype z = 0) :
			vec<3, vectype>({x, y, z}) {}

	vec3 &x(const float &f) { data[0] = f; return *this; }
	vec3 &y(const float &f) { data[1] = f; return *this; }
	vec3 &z(const float &f) { data[2] = f; return *this; }

	const vectype &x() const { return data[0]; }
	const vectype &y() const { return data[1]; }
	const vectype &z() const { return data[2]; }

	//////////////////////////////////////////////
	// MATH

	vec3 cross(const vec3 &b) const
	{
		return vec3(
				y() * b.z() - z() * b.y(),
				z() * b.x() - x() * b.z(),
				x() * b.y() - y() * b.x());
	}

	//////////////////////////////////////////////
	// OPERATORS

	operator vec2();
	operator vec4();

};

/*******************************************************************************
* VEC4
*******************************************************************************/

struct vec4 : public vec<4, float> {

	bool lock_w;

	vec4(vectype x = 0, vectype y = 0, vectype z = 0, vectype w = 1,
			bool _lock_w = true) :
			vec<4, vectype>({x, y, z, w})
	{
		lock_w = _lock_w;
	}

	vec4(const vec2 &v, vectype z = 0, vectype w = 1, bool _lock_w = true) :
			vec<4, vectype>({v.x(), v.y(), z, w})
	{
		lock_w = _lock_w;
	}

	vec4(const vec3 &v, vectype w = 1, bool _lock_w = true) :
			vec<4, vectype>({v.x(), v.y(), v.z(), w})
	{
		lock_w = _lock_w;
	}

	vec4 &x(const float &f) { data[0] = f; return *this; }
	vec4 &y(const float &f) { data[1] = f; return *this; }
	vec4 &z(const float &f) { data[2] = f; return *this; }
	vec4 &w(const float &f) { data[3] = f; return *this; }

	const vectype &x() const { return data[0]; }
	const vectype &y() const { return data[1]; }
	const vectype &z() const { return data[2]; }
	const vectype &w() const { return data[3]; }

	//////////////////////////////////////////////
	// MATH

	vec4 cross(vec4 b) const
	{
		vec4 a = *this;
		if (a.w() != 1)
			a.normalize();
		if (b.w() != 1)
			b.normalize();
		return vec4(
				a.y() * a.z() - a.z() * b.y(),
				a.z() * a.x() - a.x() * b.z(),
				a.x() * a.y() - a.y() * b.x(),
				1);
	}

	//////////////////////////////////////////////
	// OPERATORS

	vec4 operator-() const
	{
		vec4 vout;
		for (int i = 0; i < 4; ++i)
			vout.data[i] = (i == 3 && lock_w ? data[i] : -data[i]);
		return vout;
	}

	vec4 operator+(const vec4 &v) const
	{
		vec4 vout;
		for (int i = 0; i < 4; ++i)
			vout.data[i] = (i == 3 && lock_w ? data[i] : data[i] + v.data[i]);
		return vout;
	}

	vec4 operator-(const vec4 &v) const
	{
		vec4 vout;
		for (int i = 0; i < 4; ++i)
			vout.data[i] = (i == 3 && lock_w ? data[i] : data[i] - v.data[i]);
		return vout;
	}

	vec4 operator*(const float &f) const
	{
		vec4 vout;
		for (int i = 0; i < 4; ++i)
			vout.data[i] = (i == 3 && lock_w ? data[i] : data[i] * f);
		return vout;
	}

	vec4 operator/(const float &f) const
	{
		vec4 vout;
		for (int i = 0; i < 4; ++i) {
			vout.data[i] = (i == 3 && lock_w ? data[i] : data[i] / f);
		}
		return vout;
	}

	vec4 &operator+=(const vec4 &v)
	{
		for (int i = 0; i < 4; ++i) {
			if (i == 3 && lock_w)
				break;
			data[i] += v.data[i];
		}
		return *this;
	}

	vec4 &operator-=(const vec4 &v)
	{
		for (int i = 0; i < 4; ++i) {
			if (i == 3 && lock_w)
				break;
			data[i] -= v.data[i];
		}
		return *this;
	}

	vec4 &operator*=(const float &f)
	{
		for (int i = 0; i < 4; ++i) {
			if (i == 3 && lock_w)
				break;
			data[i] *= f;
		}
		return *this;
	}

	vec4 &operator/=(const float &f)
	{
		for (int i = 0; i < 4; ++i) {
			if (i == 3 && lock_w)
				break;
			data[i] /= f;
		}
		return *this;
	}
	
	vec4 operator*(const mat4 &m) const;
	
	operator vec2();
	operator vec3();

};

}
