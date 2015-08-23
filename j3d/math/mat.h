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

	float data[4][4]; // c, r

	mat4() { iden(); }

	float get(const int &r, const int &c) { return data[c][r]; }
	void set(const int &r, const int &c, const float &val) { data[c][r] = val; }
	float &at(const int &i) { return data[i % 4][i / 4]; }

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

	//////////////////////////////////////////////
	// MATHS

	mat4 &invert()
	{
		mat4 inv;
		inv[0] =	 at(5)  * at(10) * at(15) - 
					 at(5)  * at(11) * at(14) - 
					 at(9)  * at(6)  * at(15) + 
					 at(9)  * at(7)  * at(14) +
					 at(13) * at(6)  * at(11) - 
					 at(13) * at(7)  * at(10);
		inv[4] =	-at(4)  * at(10) * at(15) + 
					 at(4)  * at(11) * at(14) + 
					 at(8)  * at(6)  * at(15) - 
					 at(8)  * at(7)  * at(14) - 
					 at(12) * at(6)  * at(11) + 
					 at(12) * at(7)  * at(10);
		inv[8] =	 at(4)  * at(9)  * at(15) - 
					 at(4)  * at(11) * at(13) - 
					 at(8)  * at(5)  * at(15) + 
					 at(8)  * at(7)  * at(13) + 
					 at(12) * at(5)  * at(11) - 
					 at(12) * at(7)  * at(9);
		inv[12] =	-at(4)  * at(9)  * at(14) + 
					 at(4)  * at(10) * at(13) +
					 at(8)  * at(5)  * at(14) - 
					 at(8)  * at(6)  * at(13) - 
					 at(12) * at(5)  * at(10) + 
					 at(12) * at(6)  * at(9);
		inv[1] =	-at(1)  * at(10) * at(15) + 
					 at(1)  * at(11) * at(14) + 
					 at(9)  * at(2)  * at(15) - 
					 at(9)  * at(3)  * at(14) - 
					 at(13) * at(2)  * at(11) + 
					 at(13) * at(3)  * at(10);
		inv[5] = 	 at(0)  * at(10) * at(15) - 
					 at(0)  * at(11) * at(14) - 
					 at(8)  * at(2)  * at(15) + 
					 at(8)  * at(3)  * at(14) + 
					 at(12) * at(2)  * at(11) - 
					 at(12) * at(3)  * at(10);
		inv[9] =	-at(0)  * at(9)  * at(15) + 
					 at(0)  * at(11) * at(13) + 
					 at(8)  * at(1)  * at(15) - 
					 at(8)  * at(3)  * at(13) - 
					 at(12) * at(1)  * at(11) + 
					 at(12) * at(3)  * at(9);
		inv[13] = 	 at(0)  * at(9)  * at(14) - 
					 at(0)  * at(10) * at(13) - 
					 at(8)  * at(1)  * at(14) + 
					 at(8)  * at(2)  * at(13) + 
					 at(12) * at(1)  * at(10) - 
					 at(12) * at(2)  * at(9);
		inv[2] =	 at(1)  * at(6)  * at(15) - 
					 at(1)  * at(7)  * at(14) - 
					 at(5)  * at(2)  * at(15) + 
					 at(5)  * at(3)  * at(14) + 
					 at(13) * at(2)  * at(7)  - 
					 at(13) * at(3)  * at(6);
		inv[6] =	-at(0)  * at(6)  * at(15) + 
					 at(0)  * at(7)  * at(14) + 
					 at(4)  * at(2)  * at(15) - 
					 at(4)  * at(3)  * at(14) - 
					 at(12) * at(2)  * at(7)  + 
					 at(12) * at(3)  * at(6);
		inv[10] =	 at(0)  * at(5)  * at(15) - 
					 at(0)  * at(7)  * at(13) - 
					 at(4)  * at(1)  * at(15) + 
					 at(4)  * at(3)  * at(13) + 
					 at(12) * at(1)  * at(7) - 
					 at(12) * at(3)  * at(5);
		inv[14] =	-at(0)  * at(5)  * at(14) + 
					 at(0)  * at(6)  * at(13) + 
					 at(4)  * at(1)  * at(14) - 
					 at(4)  * at(2)  * at(13) - 
					 at(12) * at(1)  * at(6)  + 
					 at(12) * at(2)  * at(5);
		inv[3] =	-at(1)  * at(6)  * at(11) + 
					 at(1)  * at(7)  * at(10) + 
					 at(5)  * at(2)  * at(11) - 
					 at(5)  * at(3)  * at(10) - 
					 at(9)  * at(2)  * at(7)  + 
					 at(9)  * at(3)  * at(6);
		inv[7] =	 at(0)  * at(6)  * at(11) - 
					 at(0)  * at(7)  * at(10) - 
					 at(4)  * at(2)  * at(11) + 
					 at(4)  * at(3)  * at(10) + 
					 at(8)  * at(2)  * at(7)  - 
					 at(8)  * at(3)  * at(6);
		inv[11] =	-at(0)  * at(5)  * at(11) + 
					 at(0)  * at(7)  * at(9)  + 
					 at(4)  * at(1)  * at(11) - 
					 at(4)  * at(3)  * at(9)  - 
					 at(8)  * at(1)  * at(7)  + 
					 at(8)  * at(3)  * at(5);
		inv[15] =	 at(0)  * at(5)  * at(10) - 
					 at(0)  * at(6)  * at(9)  - 
					 at(4)  * at(1)  * at(10) + 
					 at(4)  * at(2)  * at(9)  + 
					 at(8)  * at(1)  * at(6)  - 
					 at(8)  * at(2)  * at(5);

		float det =	at(0) * inv[0] +
					at(1) * inv[4] +
					at(2) * inv[8] +
					at(3) * inv[12];
		if (det == 0) {
			J3D_DEBUG_WARN("determinant = 0");
			return *this;
		}
		det = 1.0f / det;
		for (int i = 0; i < 16; ++i)
			at(i) = inv[i] * det;
		return *this;
	}

	mat4 inverse()
	{
		mat4 m = *this;
		m.invert();
		return m;
	}

	void inverse(mat4 *m)
	{
		*m = *this;
		m->invert();
	}

	//////////////////////////////////////////////
	// OPERATORS

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
		return at(i);
	}

	mat4 operator*(const mat4 m)
	{
		mat4 result = *this;
		result *= m;
		return result;
	}

	//////////////////////////////////////////////
	// CAST OPERATORS

	operator GLfloat *() { return (GLfloat *)data; }

	//////////////////////////////////////////////
	// EXTRAS

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
