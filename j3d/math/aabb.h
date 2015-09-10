/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/base/aabb.h
*******************************************************************************/
#ifndef __J3D_CORE_AABB_H__
#define __J3D_CORE_AABB_H__
namespace j3d {

/*******************************************************************************
* AABB
*******************************************************************************/

template<class T>
struct aabb {
	T min;
	T max;

	aabb() {}
	aabb(const T &_min, const T &_max) { assign(_min, _max); }
	aabb(const aabb<T> &a) { assign(a); }
	aabb &operator=(const aabb &a) { return assign(a); }

	aabb &assign(const T &_min, const T &_max)
	{
		min = _min;
		max = _max;
		return *this;
	}

	aabb &assign(const aabb<T> &a)
	{
		min = a.min;
		max = a.max;
		return *this;
	}
};

typedef aabb<vec2> aabb2;
typedef aabb<vec3> aabb3;
typedef aabb<vec4> aabb4;

}
#endif
