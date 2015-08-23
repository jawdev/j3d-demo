/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/math/ray.h
*******************************************************************************/
#ifndef __J3D_MATH_RAY_H__
#define __J3D_MATH_RAY_H__
namespace j3d {

/*******************************************************************************
* RAY
*******************************************************************************/

template<class T>
struct ray {

	T o;
	T d;

	ray() {}
	ray(const ray &r) { assign(r); }
	ray(const T &_o, const T &_d) { assign(_o, _d); }

	ray &assign(const ray<T> &r)
	{
		o = r.o;
		d = r.d;
		return *this;
	}

	ray &assign(const T &_o, const T &_d)
	{
		o = _o;
		d = _d;
		return *this;
	}

	template<class>
	friend ostream &operator<<(ostream &, const ray<T> &);

};

template<class T>
ostream &operator<<(ostream &os, const ray<T> &r)
{
	os << "{" << r.o << ", " << r.d << "}";
	return os;
}

typedef ray<vec2> ray2;
typedef ray<vec3> ray3;

}
#endif
