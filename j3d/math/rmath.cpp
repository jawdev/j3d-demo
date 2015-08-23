/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/math/rmath.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d {

/*******************************************************************************
* RMATH
*******************************************************************************/

void rmath::screen_ray(ray3 *r, float x, float y)
{
	if (!J3D_CACHE(active_exists, core::CameraBase))
		J3D_DEBUG_ERROR("no active Camera in cache");
	y = (float)engine::config()->window_height - y;
	x = (x / (float)engine::config()->window_width) * 2.0f - 1.0f;
	y = (y / (float)engine::config()->window_height) * 2.0f - 1.0f;
	cout << "x = " << x << ", y = " << y << endl;
	core::CameraBase *p_cam = J3D_CACHE_ACTIVE(core::CameraBase);
	r->d.x(x);
	r->d.y(y);
	r->d.z(p_cam->near());
	r->d = vec4(r->d) * p_cam->transform().inverse();
	r->d.normalize();
	r->o = p_cam->pos();
}

bool rmath::intersection(ray3 r, vec3 min, vec3 max)
{
	r.d.invert();
	float tmin = -INFINITY;
	float tmax = INFINITY;
	float t1, t2;
	for (int i = 0; i < 3; ++i) {
		t1 = (min[i] - r.o[i]) * r.d[i];
		t2 = (max[i] - r.o[i]) * r.d[i];
		tmin = math::max(tmin, math::min(t1, t2));
		tmax = math::min(tmax, math::max(t1, t2));
	}
	cout << "{min = " << tmin << ", max = " << tmax << "}" << endl;
	return tmax > math::max(tmin, 0);
}

}
