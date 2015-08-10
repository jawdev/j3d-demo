/*******************************************************************************
* JAW DEVELOPMENT LLC
* J3D
* github.com/jawdev/j3d
* j3d/camera.cpp
*******************************************************************************/
#include "j3d.h"
namespace j3d {

/*******************************************************************************
* CAMERA
*******************************************************************************/

Camera::Camera(camera_mode_t m, camera_proj_t p, float n, float f)
		: core::Entity(), core::Reshapeable()
{
	o_mode = m;
	o_proj = p;
	o_near = (n == 0 ? engine::config()->render_distance_near : n);
	o_far = (f == 0 ? engine::config()->render_distance_far : f);
	reshape();
}

Camera::~Camera() {}

////////////////////////////////////////
// UPDATE

void Camera::reshape()
{
	o_calcd_transform = false;
	switch (o_proj) {
	case camera_proj_t::PERSPECTIVE: {
		float a = (float)engine::config()->window_width;
		a /= (float)engine::config()->window_height;
		vmath::perspective(&o_mat_proj, -a, a, -1, 1, o_near, o_far);
		break;
	} case camera_proj_t::NONE:
		o_mat_proj.iden();
		break;
	default:
		J3D_DEBUG_FATAL("invalid projection type: " << (int)o_proj);
		break;
	}
}

const mat4 &Camera::transform()
{
	if (o_locked && o_calcd_transform)
		return o_mat_transform;
	vmath::translation(&o_mat_pos, -o_pos);
	vmath::rotation(&o_mat_rot, -o_rot);
	o_mat_transform = o_mat_rot * o_mat_pos;
	o_mat_transform = o_mat_proj * o_mat_transform;
	o_calcd_transform = true;
	return o_mat_transform;
}

////////////////////////////////////////
// GET SET

Camera *Camera::mode(camera_mode_t m) { o_mode = m; return this; }
Camera *Camera::proj(camera_proj_t p) { o_proj = p; return this; }
Camera *Camera::near(const float &f) { o_near = f; return this; }
Camera *Camera::far(const float &f) { o_far = f; return this; }

camera_mode_t Camera::mode() const { return o_mode; }
camera_proj_t Camera::proj() const { return o_proj; }
float Camera::near() const { return o_near; }
float Camera::far() const { return o_far; }

}
