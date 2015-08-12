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

Camera::Camera() {}
Camera::~Camera() {}

mat4 &Camera::projection()
{
	float a = (float)engine::config()->window_width;
	a /= (float)engine::config()->window_height;
	vmath::perspective(&o_mat_projection, -a, a, -1, 1, o_near, o_far);
	return o_mat_projection;
}

}
