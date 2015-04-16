/******************************************************************************
* JAW DEVELPMENT LLC
* J3D
* github.com/jawdev/j3d
* /vmath.h
******************************************************************************/
#ifndef J3D_VMATH_H_
#define J3D_VMATH_H_
namespace j3d {

/////////////////////////////////////////////////////////// vec3

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

	const float operator[]( int i ) const { return *( &x+i ); }
	GLfloat& operator[]( int i ) { return *( &x+i ); }

	operator const GLfloat*() const { return static_cast<const GLfloat*>( &x ); }
	operator GLfloat*() { return static_cast<GLfloat*>( &x ); }

	friend ostream& operator<<( ostream& os, const vec2& v );

};

inline ostream& operator<<( ostream& os, const vec2& v ) {
	os << "<" << v.x << "," << v.y << ">";
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

	const float operator[]( int i ) const { return *( &x+i ); }
	GLfloat& operator[]( int i ) { return *( &x+i ); }

	operator const GLfloat*() const { return static_cast<const GLfloat*>( &x ); }
	operator GLfloat*() { return static_cast<GLfloat*>( &x ); }

	friend ostream& operator<<( ostream& os, const vec3& v );

};

inline ostream& operator<<( ostream& os, const vec3& v ) {
	os << "<" << v.x << "," << v.y << "," << v.z << ">";
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

	const float operator[]( int i ) const { return *( &x+i ); }
	GLfloat& operator[]( int i ) { return *( &x+i ); }

	operator const GLfloat*() const { return static_cast<const GLfloat*>( &x ); }
	operator GLfloat*() { return static_cast<GLfloat*>( &x ); }

	friend ostream& operator<<( ostream& os, const vec4& v );

};

inline ostream& operator<<( ostream& os, const vec4& v ) {
	os << "<" << v.x << "," << v.y << "," << v.z << "," << v.w << ">";
	return os;
}

}
#endif
