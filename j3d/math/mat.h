/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/math/mat4.h
*******************************************************************************/
namespace j3d {

/*******************************************************************************
* MAT4
*******************************************************************************/

struct mat4 {

	float data[4][4];
	//         c  r

	mat4() { iden(); }

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

}
