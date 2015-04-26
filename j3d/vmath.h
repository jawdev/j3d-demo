/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /vmath.h
******************************************************************************/
#ifndef J3D_VMATH_H_
#define J3D_VMATH_H_
namespace j3d {

/////////////////////////////////////////////////////////// vec2

struct vec2 {

	float x, y;

	vec2( float _x = 0, float _y = 0 ) {
		x = _x; y = _y;
	}

	vec2& operator=( const vec2& v ) {
		if( this == &v ) return *this;
		x = v.x; y = v.y;
		return *this;
	}

	vec2 operator-() const { return vec2( -x, -y ); }
	vec2 operator+( const vec2& v ) const { return vec2( x+v.x, y+v.y ); }
	vec2 operator-( const vec2& v ) const { return vec2( x-v.x, y-v.y ); }
	vec2 operator*( const float f ) const { return vec2( x*f, y*f ); }
	vec2 operator/( const float f ) const { return vec2( x/f, y/f ); }

	vec2& operator+=( const vec2& v ) { x += v.x; y += v.y; return *this; }
	vec2& operator-=( const vec2& v ) { x -= v.x; y -= v.y; return *this; }
	vec2& operator*=( const float f ) { x *= f; y *= f; return *this; }
	vec2& operator/=( const float f ) { x /= f; y /= f; return *this; }

	GLfloat* glfloat() { return (GLfloat*)this; }
	friend ostream& operator<<( ostream& os, const vec2& v );

};

inline ostream& operator<<( ostream& os, const vec2& v ) {
	os << "<" << v.x << "," << v.y << ">";
	return os;
}

/////////////////////////////////////////////////////////// vec4

struct vec4 {

	float x, y, z, w;
	bool lock_w;

	vec4( float _x = 0, float _y = 0, float _z = 0, float _w = 1, bool _lock_w = true ) {
		x = _x; y = _y; z = _z; w = _w;
		lock_w = _lock_w;
	}

	vec4& operator=( const vec4& v ) {
		if( this == &v ) return *this;
		x = v.x; y = v.y; z = v.z; w = v.w;
		return *this;
	}

	vec4 operator-() const { return vec4( -x, -y, -z, (lock_w?w:-w ) ); }
	vec4 operator+( const vec4& v ) const { return vec4( x+v.x, y+v.y, z+v.z, ( lock_w ? w : w+v.w ) ); }
	vec4 operator-( const vec4& v ) const { return vec4( x-v.x, y-v.y, z-v.z, ( lock_w ? w : w- v.w ) ); }
	vec4 operator*( const float f ) const { return vec4( x*f, y*f, z*f, ( lock_w ? w : w*f ) ); }
	vec4 operator/( const float f ) const { return vec4( x/f, y/f, z/f, ( lock_w ? w : w/f ) ); }

	vec4& operator+=( const vec4& v ) { x += v.x; y += v.y; z += v.z; if( !lock_w ) w += v.w; return *this; }
	vec4& operator-=( const vec4& v ) { x -= v.x; y -= v.y; z -= v.z; if( !lock_w ) w -= v.w; return *this; }
	vec4& operator*=( const float f ) { x *= f; y *= f; z *= f; if( !lock_w ) w *= f; return *this; }
	vec4& operator/=( const float f ) { x /= f; y /= f; z /= f; if( !lock_w ) w /= f; return *this; }

	GLfloat* glfloat() { return (GLfloat*)this; }
	friend ostream& operator<<( ostream& os, const vec4& v );

};

inline ostream& operator<<( ostream& os, const vec4& v ) {
	os << "<" << v.x << "," << v.y << "," << v.z << "," << v.w << ">";
	return os;
}

/////////////////////////////////////////////////////////// vec3

struct vec3 {

	float x, y, z;

	vec3( float _x = 0, float _y = 0, float _z = 0 ) {
		x = _x; y = _y; z = _z;
	}

	vec3& operator=( const vec3& v ) {
		if( this == &v ) return *this;
		x = v.x; y = v.y; z = v.z;
		return *this;
	}

	vec3 operator-() const { return vec3( -x, -y, -z ); }
	vec3 operator+( const vec3& v ) const { return vec3( x+v.x, y+v.y, z+v.z ); }
	vec3 operator-( const vec3& v ) const { return vec3( x-v.x, y-v.y, z-v.z ); }
	vec3 operator*( const float f ) const { return vec3( x*f, y*f, z*f ); }
	vec3 operator/( const float f ) const { return vec3( x/f, y/f, z/f ); }

	vec3& operator+=( const vec3& v ) { x += v.x; y += v.y; z += v.z; return *this; }
	vec3& operator-=( const vec3& v ) { x -= v.x; y -= v.y; z -= v.z; return *this; }
	vec3& operator*=( const float f ) { x *= f; y *= f; z *= f; return *this; }
	vec3& operator/=( const float f ) { x /= f; y /= f; z /= f; return *this; }

	operator vec4() { return vec4( x, y, z, 1 ); }
	GLfloat* glfloat() { return (GLfloat*)this; }
	friend ostream& operator<<( ostream& os, const vec3& v );

};

inline ostream& operator<<( ostream& os, const vec3& v ) {
	os << "<" << v.x << "," << v.y << "," << v.z << ">";
	return os;
}

/////////////////////////////////////////////////////////// mat4

struct mat4 {

	float data[4][4];

	mat4() { iden(); }

	float* row( const unsigned int &i ) {
		float* row_data = new float[4];
		for( int k = 0; k < 4; k++ ) row_data[k] = data[k][i];
		return row_data;
	}

	float* col( const unsigned int &j ) {
		float* col_data = new float[4];
		for( int k = 0; k < 4; k++ ) col_data[k] = data[j][k];
		return col_data;
	}

	float get( const unsigned int& i, const unsigned int& j ) { return data[j][i]; }
	void set( const unsigned int& i, const unsigned int& j, const float& val ) { data[j][i] = val; }

	void zero() {
		for( int j = 0; j < 4; j++ ) for( int i = 0; i < 4; i++ )
			data[j][i] = 0;
	}

	void iden() {
		for( int j = 0; j < 4; j++ ) for( int i = 0; i < 4; i++ )
			data[j][i] = ( j == i ? 1 : 0 );
	}

	mat4& operator=( const mat4& m ) {
		for( int j = 0; j < 4; j++ ) for( int i = 0; i < 4; i++ )
			data[j][i] = m.data[j][i];
		return *this;
	}

	mat4& operator*=( const mat4& m ) {
		mat4 cp = *this;
		for( int j = 0; j < 4; j++ ) for( int i = 0; i < 4; i++ )
			data[j][i] = m.data[j][0]*cp.data[0][i]+m.data[j][1]*cp.data[1][i]+m.data[j][2]*cp.data[2][i]+m.data[j][3]*cp.data[3][i];
		return *this;
	}

	const mat4 operator*( const mat4& m ) const {
		mat4 result = *this;
		result *= m;
		return result;
	}

	GLfloat* glfloat() { return (GLfloat*)this; }
	friend ostream& operator<<( ostream& os, const mat4& m );

};

inline ostream& operator<<( ostream& os, const mat4& m ) {
	os << "========================================";
	os << "========================================" << endl;
	for( int i = 0; i < 4; i++ ) {
		for( int j = 0; j < 4; j++ ) {
			os << setw( 20 );
			os << m.data[j][i];
		}
		os << endl;
	}
	os << "========================================";
	os << "========================================";
	return os;
}

/////////////////////////////////////////////////////////// vmath

namespace vmath {


	static inline vec2 norm( const vec2& v ) {
		float mag = sqrt( v.x*v.x+v.y*v.y );
		if( mag == 0 ) return vec2( 0, 0 );
		else return vec2( v.x/mag, v.y/mag );
	}
	static inline vec3 norm( const vec3& v ) {
		float mag = sqrt( v.x*v.x+v.y*v.y+v.z*v.z );
		if( mag == 0 ) return vec3( 0, 0, 0 );
		else return vec3( v.x/mag, v.y/mag, v.z/mag );
	}
	static inline vec4 norm( const vec4& v ) {
		float mag = sqrt( v.x*v.x+v.y*v.y+v.z*v.z );
		if( mag == 0 ) return vec4( 0, 0, 0, 1 );
		else return vec4( v.x/mag, v.y/mag, v.z/mag, 1 );
	}


	static inline vec3 cross( const vec3& a, const vec3& b ) {
		return vec3( a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x );
	}
	static inline vec4 cross( const vec4& a, const vec4& b ) {
		if( a.w != 1 ) norm( a );
		if( b.w != 1 ) norm( b );
		return vec4( a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x, 1 );
	}


	static inline void translation( mat4* m, const vec3& v ) {
		m->iden();
		m->set( 0, 3, v.x );
		m->set( 1, 3, v.y );
		m->set( 2, 3, v.z );
	}
	static inline void translation( mat4* m, const vec4& v ) {
		translation( m, vec3( v.x, v.y, v.z ) );
	}
	static inline mat4* translation( const vec3& v ) {
		mat4* m = new mat4;
		translation( m, v );
		return m;
	}
	static inline mat4* translation( const vec4& v ) {
		return translation( vec3( v.x, v.y, v.z ) );
	}


	static inline void rotationX( mat4* m, const float& f ) {
		m->iden();
		float cos_ang = cos( f );
		float sin_ang = sin( f );
		m->set( 1, 1, cos_ang );
		m->set( 1, 2, -sin_ang );
		m->set( 2, 1, sin_ang );
		m->set( 2, 2, cos_ang );
	}
	static inline void rotationY( mat4* m, const float& f ) {
		m->iden();
		float cos_ang = cos( f );
		float sin_ang = sin( f );
		m->set( 0, 0, sin_ang );
		m->set( 0, 2, -cos_ang );
		m->set( 2, 0, cos_ang );
		m->set( 2, 2, sin_ang );
	}
	static inline void rotationZ( mat4* m, const float& f ) {
		m->iden();
		float cos_ang = cos( f );
		float sin_ang = sin( f );
		m->set( 0, 0, cos_ang );
		m->set( 0, 1, -sin_ang );
		m->set( 1, 0, sin_ang );
		m->set( 1, 1, cos_ang );
	}
	static inline void rotation( mat4* m, const vec3& v ) {
		mat4 mx, my, mz;
		rotationX( &mx, v.x );
		rotationY( &my, v.y );
		rotationZ( &mz, v.z );
		*m = mz*mx*my;
	}
	static inline void rotation( mat4* m, const vec4& v ) {
		rotation( m, vec3( v.x, v.y, v.z ) );
	}
	static inline mat4* rotation( const vec3& v ) {
		mat4* m = new mat4;
		rotation( m, v );
		return m;
	}
	static inline mat4* rotation( const vec4& v ) {
		return rotation( vec3( v.x, v.y, v.z ) );
	}


	static inline void perspective( mat4* m, float l, float r, float b, float t, float n, float f ) {
		m->iden();
		if( r == l || t == b || n == f || n < 0 || f < 0 ) return;
		float n_t_2 = n*2.0f;
		float r_m_l = r-l;
		float t_m_b = t-b;
		float f_m_n = f-n;
		m->set( 0, 0, n_t_2/r_m_l );
		m->set( 0, 2, ( r+l )/r_m_l );
		m->set( 1, 1, n_t_2/t_m_b );
		m->set( 1, 2, ( t+b )/t_m_b );
		m->set( 2, 2, -( f+n )/f_m_n );
		m->set( 2, 3, -( f*n_t_2 )/f_m_n );
		m->set( 3, 2, -1 );
		m->set( 3, 3, 0 );
	}
	static inline mat4* perspective( float l, float r, float b, float t, float n, float f ) {
		mat4* m = new mat4;
		perspective( m, l, r, b, t, n, f );
		return m;
	}

}

}
#endif
