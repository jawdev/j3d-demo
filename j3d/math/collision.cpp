/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/math/collision.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d {

/*******************************************************************************
* COLLISION
*******************************************************************************/

bool collision::ray_aabb(ray3 r, const aabb &a)
{
	r.d.invert();
	float tmin = -INFINITY;
	float tmax = INFINITY;
	float t1, t2;
	for (int i = 0; i < 3; ++i) {
		t1 = (a.min[i] - r.o[i]) * r.d[i];
		t2 = (a.max[i] - r.o[i]) * r.d[i];
		tmin = math::max(tmin, math::min(t1, t2));
		tmax = math::min(tmax, math::max(t1, t2));
	}
	return tmax > math::max(tmin, 0);
}

}

