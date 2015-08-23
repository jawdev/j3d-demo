/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/math/ray.cpp
*******************************************************************************/
#include "../j3d.h"
namespace j3d {

/*******************************************************************************
* RAY3
*******************************************************************************/

ray3 &ray3::from_window(int win_x, int win_y)
{
	if (!J3D_CACHE(active_exists, base::CameraBase))
		J3D_DEBUG_ERROR("no active Camera in cache");
	float y = (float)engine::config()->window_height - (float)win_y;
	float x = ((float)win_x / (float)engine::config()->window_width)
			* 2.0f - 1.0f;
	y = ((float)y / (float)engine::config()->window_height)
			* 2.0f - 1.0f;
	base::CameraBase *p_cam = J3D_CACHE_ACTIVE(base::CameraBase);
	d.x(x);
	d.y(y);
	d.z(p_cam->near());
	d = vec4(d) * p_cam->transform().inverse();
	d.normalize();
	o = p_cam->pos();
	return *this;
}

}
